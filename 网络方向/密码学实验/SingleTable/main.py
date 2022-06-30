import os

def findAllFile(base):    #获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f

if __name__ == '__main__':
    base = './files/'
    fileslist = []
    num = 0
    for i in findAllFile(base):
        fileslist.append(i)
        num += 1

    key = str(input("请输入加密秘钥："))
    table = key
    for i in range(26):
        if table.find(chr(i + ord("a"))) == -1:
            table += chr(i + ord("a"))

    for filename in fileslist:
        #读取文件内容
        print("开始加密: " + filename)
        f_crypt = ""
        with open("./files/" + filename, encoding="utf8", errors='ignore') as f:
            f_str = f.read()
            for i in range(0, len(f_str)):
                t = f_str[i]
                if t.isupper():
                    f_crypt += chr(ord(table[ord(t) - ord("A")]) - 32)
                elif t.islower():
                    f_crypt += table[ord(t) - ord("a")]
                else:
                    f_crypt += t
            f.close()

            print(f_crypt)
            crypt_file = open('files/' + 'crypt_' + filename, 'w')
            for i in range(0, len(f_str)):
                crypt_file.write(f_crypt[i])

            crypt_file.close()

