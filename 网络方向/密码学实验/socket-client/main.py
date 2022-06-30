import socket
import base64
from Crypto.Cipher import AES
from Crypto import Random
import os
import time
import base64
import random

import md5
import rsa

def findAllFile(base):    #获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f

def get_key(password):  #生成秘钥
    key = str(password)
    times = 0
    while len(key) % 16 != 0:
        key += '\0'
        times += 1
    return key

def add_to_16(s):   #转换数据为16位倍数
    times = 0
    while len(s) % 16 != 0:
        s = s+b'0'
        times += 1
    return s

def encrypt(data, password):      #aes加密
    aes = AES.new(str.encode(password), AES.MODE_ECB)
    encrypted_text = aes.encrypt(add_to_16(data))

    return encrypted_text


if __name__ == '__main__':
    base = './files/'
    fileslist = []
    num = 0
    for i in findAllFile(base):
        fileslist.append(i)
        num += 1

    omes = "Total number of files: {}\n".format(num)
    for i in fileslist:
        omes += (i + '\n')
    print(omes)

    # 随机生成初始aes秘钥
    num = random.randint(1, 323)
    passwd = str(num)
    key = get_key(passwd)
    print("AES秘钥为: {}".format(key))

    # 加密aes秘钥
    crypt_passwd = rsa.encrypt(num, 23, 323)
    print("加密后的AES秘钥为: {}".format(crypt_passwd))

    # 创建socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象，准备建立tcp连接
    #host = '129.226.166.81'  # 连接腾讯云服务器
    host = '127.0.0.1'
    port = 10870  # 设置端口号
    s.connect((host, port))

    # 发送加密秘钥
    s.sendall(crypt_passwd.encode())

    # 发送文件名信息
    omes = omes.encode()
    cryptmes = encrypt(omes, key)
    s.sendall(cryptmes)
    time.sleep(3)   #等待3s开始发送文件
    sum = 0

    for i in fileslist:
        if sum:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
            s.connect((host, port))
        sum+=1
        print("开始发送: " + i)
        f = open("./files/" + i, 'rb')
        f_str = f.read()
        cryptfile = encrypt(f_str, key)
        f.close()

        if not cryptfile:
            continue

        s.sendall('{}'.format(len(cryptfile)).encode())  # 默认编码 utf-8,发送文件长度值
        reply = s.recv(1024)

        if 'ok' == reply.decode():
            go = 0
            total = len(cryptfile)
            while go < total:  # 发送文件
                data_to_send = cryptfile[go:go + 1024]
                s.sendall(data_to_send)
                go += len(data_to_send)

            #  发送明文长度
            lenfile = encrypt(str(len(f_str)).encode(), key)
            s.sendall(lenfile)

            #  生成文件md5码并发送
            md5_str = md5.Md5sum(f_str)
            s.sendall(md5_str.encode())
            if sum < len(fileslist):
                s.sendall('continue'.encode())
            else:
                s.sendall('close'.encode())

            s.close()  # 关闭连接


