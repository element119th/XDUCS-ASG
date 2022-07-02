
import math


def isprimeandpalindrome():  # 判断是否为回文素数
    n = 2  # 1既不是素数也不是合数，从2开始即可
    count = 0  # 用于计数，合计多少个回文素数
    while count < 100:
        if isprime(n) and ispalindrome(n):  # 如果既是素数又是回文数，那么就是回文素数
            count += 1
            print(count, ":", n)
        n += 1


def isprime(n):  # 判断是否为素数
    for i in range(2, int(math.sqrt(n)) + 1):  # 直接到根下n即可，但是由于int直接舍去小数，故需要+1
        if n % i == 0:
            return 0
        i += 1
    return 1


def ispalindrome(n):  # p判断是否为回文数
    m = str(n)  # 切片需要tuple或list，用强制类型转化转把int换成str
    if m == m[::-1]:  # 使用切片，逆序比较
        return 1
    return 0


isprimeandpalindrome()
