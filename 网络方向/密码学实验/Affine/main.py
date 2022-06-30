import os

def findAllFile(base):    #获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f

def subcrypt(test,ka,kb):
    key = ""
    for j in range(0, len(test)):
        o = test[j]
        if (o.isupper()):
            key += chr(ord("A") + ((ord(test[j]) - ord("A")) * ka + kb) % 26)
        elif (o.islower()):
            key += chr(ord("a") + ((ord(test[j]) - ord("a")) * ka + kb) % 26)
        else:
            key += o

    return key

if __name__ == '__main__':
    base = './files/'
    fileslist = []
    num = 0
    for i in findAllFile(base):
        fileslist.append(i)
        num += 1

    key = str(input("请输入加密秘钥：")).split(",")
    ka = int(key[0])
    kb = int(key[1])

    for filename in fileslist:
        #读取文件内容
        print("开始加密: " + filename)
        f_crypt = ""
        with open("./files/" + filename, encoding="utf8", errors='ignore') as f:
            f_str = f.read()
            f.close()

            crypt_file = open('files/' + 'crypt_' + filename, 'w')
            crypt_file.write(subcrypt(f_str, ka, kb))

            crypt_file.close()

