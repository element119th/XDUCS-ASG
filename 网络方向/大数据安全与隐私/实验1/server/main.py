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

def multimod(a, k, n):  # 快速幂取模
    ans = 1
    while (k != 0):
        if k % 2:
            ans = (ans % n) * (a % n) % n
        a = (a % n) * (a % n) % n
        k = k // 2
    return ans


def get_generator(p):  # 计算素数p的原根
    k = (p - 1) // 2
    for i in range(2, p - 1):
        if multimod(i, k, p) != 1:
            return i


def get_calculation(p, a, X):
    Y = (a ** X) % p
    return Y


def get_DHkey(X, Y, p):  # 得到DH密钥
    key = (Y ** X) % p
    return key


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

    p = 190301

    # 得到素数的一个原根
    g = get_generator(p)

    XB = random.randint(0, p - 1)
    YB = get_calculation(p, int(g), XB)
    ya = conn.recv(1024).decode()  # 得到客户端生成的DH公钥
    conn.sendall(str(YB).encode())  # 向客户端发送DH公钥
    YA = int(ya)

    password = get_DHkey(XB, YA, p)  # 得到DH密钥
    print("协商得到DH密钥为" + str(password))

    key = get_key(password)  # 根据DH密钥生成AES密钥

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
            print('应该接收{},实际接收{}'.format(length, len(file)))
            while(len(file) % 16 != 0):
                file += b'0'
            file = decrypt(file, key)
            if file:
                print('acturally length:{}'.format(len(file)))
                newfile.write(file[:])
                newfile.close()

            t = conn.recv(1024).decode()
            print("")
            if (t == 'close'):
                break
            conn.close() # 关闭连接

    conn.close()  
    print("传输完成，关闭连接")







