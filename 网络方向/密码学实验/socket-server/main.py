# -*- coding: UTF-8 -*-
import sys
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

def get_key(password):  # 生成秘钥
    key = str(password)
    times = 0
    while len(key) % 16 != 0:
        key += '\0'
        times += 1
    return key


def add_to_16(s):  # 转换数据为16位倍数
    times = 0
    while len(s) % 16 != 0:
        s += '\0'
        times += 1
    return str.encode(s)


def decrypt(encrypted_text, password):  # aes解密
    aes = AES.new(str.encode(password), AES.MODE_ECB)
    decrypted_text = aes.decrypt(encrypted_text)

    return decrypted_text


if __name__ == '__main__':

    fileslist = []
    ip_port = ('0.0.0.0', 10870)

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象，准备建立tcp连接
    s.bind(ip_port)  # 绑定服务地址
    s.listen(5)  # 监听连接请求
    print('启动socket服务，等待客户端连接...')
    conn, address = s.accept()  # 等待连接，此处自动阻塞

    print("成功建立连接")

    key1 = 17
    key2 = 19
    fn = (key1 - 1) * (key2 - 1)
    e = rsa.get_E(key1, key2)
    d = rsa.ModReverse(e, fn)
    conkey = conn.recv(1024).decode()
    print(conkey)
    passwd = rsa.decrypt(conkey, d, key1*key2)
    print("解密得到AES秘钥为: {}".format(passwd))

    key = get_key(passwd)  # 根据DH密钥生成AES密钥

    cryptmes = conn.recv(1024)
    omes = decrypt(cryptmes, key).decode()
    print(omes[:omes.find("0")])
    sum = 0

    while True:  #接收客户端信息
        if sum:
            conn, address = s.accept()  # 等待连接，此处自动阻塞
        sum += 1
        infor = conn.recv(1024)  #接收文件长度信息
        length = infor.decode()
        #print(length)
        p1 = omes.find("\n")
        omes = omes[p1 + 1:]
        p2 = omes.find("\n")
        filename = omes[: p2]
        print("开始接收:")
        print(filename)
        if length:
            newfile = open('files/' + filename, 'wb')
            print('length {},filename {}'.format(length, filename))
            conn.sendall(b'ok')  # 表示收到文件长度和文件名
            file = b''
            total = int(length)
            get = 0
            while get < total:  # 接收文件
                data = conn.recv(1024)
                file += data
                get = get + len(data)
                #print(get)
            print('应该接收{},实际接收{}'.format(length, len(file)))
            file = decrypt(file, key)
            if file:
                print('acturally length:{}'.format(len(file)))
                newfile.write(file[:])
                newfile.close()

            filelen = conn.recv(1024)
            filelen = decrypt(filelen, key).decode().strip('0')
            re_md5 = conn.recv(1024)
            or_md5 = md5.Md5sum(file[:int(filelen)])
            print('收到文件的md5码:{}'.format(or_md5))
            print('客户端计算的md5码:{}'.format(re_md5.decode()))
            if(conn.recv(1024).decode() == 'close'):
                break
            conn.close()

    conn.close()  # 关闭连接
    print("关闭连接")