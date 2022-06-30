import socket
import base64
from Crypto.Cipher import AES
from Crypto import Random
import os
import time
import base64
import random

def findAllFile(base):    #获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f

def multimod(a,k,n):    #快速幂取模
    ans=1
    while(k != 0):
        if k % 2:
            ans = (ans % n)*(a % n) % n
        a = (a % n) * (a % n) % n
        k = k//2
    return ans

def get_generator(p):   #计算素数p的原根
    k = (p - 1) // 2
    for i in range(2, p - 1):
        if multimod(i, k, p) != 1:
            return i

def get_calculation(p, a, X):
    Y = (a ** X) % p
    return Y

def get_DHkey(X, Y, p):  #得到DH密钥
    key = (Y ** X) % p
    return key

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

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象，准备建立tcp连接
    host = '129.226.166.81'  # 连接腾讯云服务器
    #host = '127.0.0.1'
    port = 10870  # 设置端口号
    s.connect((host, port))

    p = 190301

    # 得到素数的一个原根
    g = get_generator(p)

    XA = random.randint(0, p - 1)
    YA = get_calculation(p, int(g), XA)

    s.sendall(str(YA).encode())    #向服务器发送DH公钥
    yb = s.recv(1024).decode()   #得到服务器生成的DH公钥
    YB = int(yb)

    password = get_DHkey(XA, YB, p)   #得到DH密钥
    print("协商得到DH密钥为" + str(password))

    key = get_key(password)   #根据DH密钥生成AES密钥

    # 发送加密后的文件名信息
    omes = omes.encode()
    cryptmes = encrypt(omes,key)
    s.sendall(cryptmes)
    time.sleep(3)   #等待3s开始发送文件
    sum = 0


    for i in fileslist:
        if sum:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((host, port))
        sum += 1
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

            if sum < len(fileslist):
                s.sendall('continue'.encode())
            else:
                print("文件发送完毕")
                s.sendall('close'.encode())

            s.close()  # 关闭连接








