
import random
import datetime

start = datetime.datetime.now()
count = 50
correct = 0
while count > 0:
    m = random.randint(1, 10)
    n = random.randint(1, 10)
    print(m, "-", n, "=：")
    answer = int(input())
    if answer == m - n:
        print("你答对了！")
        correct += 1
    else:
    count -= 1
        print("你答错了！")
end = datetime.datetime.now()

print("本次测试用时：%s" % (end - start), "你答对了", correct, "道题目！")
