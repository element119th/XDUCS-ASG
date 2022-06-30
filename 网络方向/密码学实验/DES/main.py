# des加密主文件
from box import *
import re
import os

#将明文字符串转化为二进制
def mes2b(mes):
    res = ""
    for i in mes:  #对每个字符进行二进制转化
        tmp = bin(ord(i))[2:]  #将字符转成ascii，再转换成二进制，并去掉前面的0b
        for j in range(0,8-len(tmp)):   #补齐8位
            tmp = '0' + tmp
        res += tmp
    return res


#解密时将二进制转化为字符串
def b2mes(bin_str):
    res = ""
    tmp = re.findall(r'.{8}',bin_str)  #每8位表示一个字符
    for i in tmp:
        res += chr(int(i,2))  #将该字符串视作2进制转化为10进制
    return res

#IP盒处理
def iprpc(bin_str):
    res = ""
    for i in IP_table:
        res += bin_str[i-1]     #数组下标i-1
    return res


#IP逆盒处理
def iprrpc(bin_str):
    res = ""
    for i in IP_re_table:
        res += bin_str[i-1]
    return res

#E盒置换
def erpc(bin_str):
    res = ""
    for i in E:
        res += bin_str[i-1]
    return res


#字符串异或操作
def str_xor(my_str1,my_str2):  #str，key
    res = ""
    for i in range(0,len(my_str1)):
        xor_res = int(my_str1[i],10)^int(my_str2[i],10) #变成10进制是转化成字符串 2进制与10进制异或结果一样，都是1,0
        if xor_res == 1:
            res += '1'
        if xor_res == 0:
            res += '0'

    return res


#循环左移操作
def leftm(my_str,num):
    left_res = my_str[num:len(my_str)]
    left_res =  left_res+my_str[0:num]
    return left_res

#秘钥的PC-1置换
def key_pc1(my_key):
    res = ""
    for i in PC_1:  #PC_1盒上的元素表示位置    只循环64次
        res += my_key[i-1]     #将密钥按照PC_1的位置顺序排列，
    return res

#秘钥的PC-2置换
def key_pc2(my_key):
    res  = ""
    for i in PC_2:
        res += my_key[i-1]
    return res


# S盒过程
def s_box(my_str):
    res = ""
    c = 0
    for i in range(0,len(my_str),6):#步长为6   表示分6为一组
        now_str = my_str[i:i+6]    #第i个分组
        row = int(now_str[0]+now_str[5],2)   #b1b6 =r   第r行
        col = int(now_str[1:5],2)   #第c列
        #第几个s盒的第row*16+col个位置的元素
        num = bin(S[c][row*16 + col])[2:]   #利用了bin输出有可能不是4位str类型的值，所以才有下面的循环并且加上字符0
        for gz in range(0,4-len(num)):
            num = '0'+ num
        res += num
        c  += 1
    return res


#P盒置换
def p_box(bin_str):
    res = ""
    for i in  P:
        res += bin_str[i-1]
    return res



# F函数的实现
def fun_f(bin_str,key):
    first_output = erpc(bin_str)   #位选择函数将32位待加密str拓展位48位
    second_output = str_xor(first_output,key)  #将48位结果与子密钥Ki按位模2加    得到的结果分为8组（6*8）
    third_output = s_box(second_output)    #每组6位缩减位4位   S盒置换
    last_output = p_box(third_output)     #P盒换位处理  得到f函数的最终值
    return last_output

def gen_key(key):
    key_list = []
    divide_output = key_pc1(key)
    key_C0 = divide_output[0:28]
    key_D0 = divide_output[28:]
    sum = 1
    for i in SHIFT:   #shift左移位数
        key_c = leftm(key_C0,i)
        key_d = leftm(key_D0,i)
        key_output = key_pc2(key_c + key_d)
        print("第 %d 个子秘钥为:" % sum)
        print(key_output)wwwwwwwwwwwwwwwww
        032
1        key_list.append(key_output)

        sum+=1
    return key_list

def des(bin_mes,bin_key): #64位二进制加密的测试
    mes_ip_bin = iprpc(bin_mes)  #ip转换
    key_lst = gen_key(bin_key)   #生成子密钥
    mes_left = mes_ip_bin[0:32]
    mes_right = mes_ip_bin[32:]
    print("第 1 轮迭代的L为:" )
    print(mes_left)
    print("第 1 轮迭代的R为:" )
    print(mes_right)
    for i in range(0,15):
        mes_tmp = mes_right  #暂存右边32位
        f_result = fun_f(mes_tmp,key_lst[i])   #右32位与k的f函数值
        mes_right = str_xor(f_result,mes_left)  #f函数的结果与左边32位异或   作为下次右边32位
        mes_left = mes_tmp   #上一次的右边直接放到左边
        print("第 %d 轮迭代的L为:" % (i+2))
        print(mes_left)
        print("第 %d 轮迭代的R为:" % (i+2))
        print(mes_right)
    f_result = fun_f(mes_right,key_lst[15])  #第16次不用换位，故不用暂存右边
    mes_fin_left = str_xor(mes_left,f_result)
    mes_fin_right = mes_right
    fin_mes = iprrpc(mes_fin_left + mes_fin_right)   #ip的逆
    return fin_mes   #返回单字符的加密结果

#64位二进制解密的测试
def des_decrypt_one(bin_mess,bin_key):
    mes_ip_bin = iprpc(bin_mess)
    key_lst = gen_key(bin_key)
    lst = range(1,16)   #循环15次
    cipher_left = mes_ip_bin[0:32]
    cipher_right = mes_ip_bin[32:]
    for i in lst[::-1]:   #表示逆转列表调用
        mes_tmp = cipher_right
        cipher_right = str_xor(cipher_left,fun_f(cipher_right,key_lst[i]))
        cipher_left = mes_tmp
    fin_left = str_xor(cipher_left,fun_f(cipher_right,key_lst[0]))
    fin_right = cipher_right
    fin_output  = fin_left + fin_right
    bin_plain = iprrpc(fin_output)
    res = b2mes(bin_plain)
    return res


#简单判断以及处理信息分组
def mes_deal(bin_mess):
    ans = len(bin_mess)
    if ans % 64 != 0:
        for i in range( 64 - (ans%64)):           #不够64位补充0
            bin_mess += '0'
    return bin_mess

def mes_out(origin_mess):
    for i in range(0,len(origin_mess)):
        if not ord(origin_mess[i]):
            break
    return origin_mess[0:i]

#查看秘钥是否为64位
def input_key_judge(bin_key):   #位数不足则补0
    ans = len(bin_key)
    if len(bin_key) < 64:
        if ans % 64 != 0:
            for i in range(64 - (ans % 64)):  # 不够64位补充0
                bin_key += '0'
    return bin_key


def mes_encrypt(mes,key):
        bin_mess = mes_deal(mes2b(mes)) #得到明文的二进制比特流  64的倍数
        res = ""
        bin_key = input_key_judge(mes2b(key))   #得到密钥得二进制比特流 64的倍数
        tmp = re.findall(r'.{64}',bin_mess)    #单词加密只能实现8个字符，匹配为每64一组的列表
        for i in tmp:
            res += des(i,bin_key)  #将每个字符加密后的结果再连接起来
        return res

def mes_decrypt(mes,key):
    bin_mess = mes_deal(mes2b(mes))
    res = ""
    bin_key = input_key_judge(mes2b(key))
    tmp = re.findall(r'.{64}',bin_mess)
    for i in tmp:
        res += des_decrypt_one(i,bin_key)
    return res


def findAllFile(base):  # 获取文件内容
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f


def CryptFiles(key):
    base = './files/'
    fileslist = []
    for i in findAllFile(base):
        fileslist.append(i)

    for filename in fileslist:
        # 读取文件内容
        print("开始加密: " + filename)
        with open("./files/" + filename, encoding="utf-8", errors='ignore') as f:
            f_str = f.read()
            f.close()

            s = mes_encrypt(f_str, key)
            out_mess = b2mes(s)

            print("加密过后的内容为:" + out_mess)

            crypt_file = open('files/' + 'crypt_' + filename, 'w', encoding="utf-8")
            crypt_file.write(out_mess)

            crypt_file.close()


def DeCryptFiles(key):
    base = './files/'
    fileslist = []
    for i in findAllFile(base):
        fileslist.append(i)

    for filename in fileslist:
        # 读取文件内容
        if filename.find("crypt") == -1:
            continue
        print("开始解密: " + filename)
        with open("./files/" + filename, encoding="utf-8", errors='ignore') as f:
            f_str = f.read()
            f.close()

            s = mes_decrypt(f_str, key)

            print("解密后的信息：" + mes_out(s))


def start():
    print("请输入序号，选择对应的功能：")
    print("1.DES加密")
    print("2.DES解密")
    mode = input()
    if mode == '1':
        print("请输入DES加密秘钥：")
        key = input().replace(' ', '')
        CryptFiles(key)

    elif mode == '2':
        print("请输入你的秘钥：")
        key = input().replace(' ', '')
        DeCryptFiles(key)
    else:
        print("请重新输入！")


if __name__ == '__main__':
    while True:
        start()

