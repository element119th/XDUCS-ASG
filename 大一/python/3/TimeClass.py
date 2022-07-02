
import time

# 获取当前格林威治时间
currentTime = time.time()
totalSeconds = int(currentTime)
currentSecond = totalSeconds % 60
totalMinutes = totalSeconds // 60
currentMinute = totalMinutes % 60
totalHours = totalMinutes // 60
currentHour = totalHours % 24


class Time:
    # 构造方法初始化
    def __init__(self):
        self.__hour = currentHour
        self.__minute = currentMinute
        self.__second = currentSecond

    # 小时访问器
    def getHour(self):
        return self.__hour

    # 分钟访问器
    def getMinute(self):
        return self.__minute

    # 秒钟访问器
    def getSecond(self):
        return self.__second

    # 时间修改器
    def setTime(self, clapseTime):
        if clapseTime < 0:
            print("输入流逝时间错误，请重新输入：")
        else:
            timed = currentTime + clapseTime
            totalSeconds2 = int(timed)
            currentSecond2 = totalSeconds2 % 60
            totalMinutes2 = totalSeconds2 // 60
            currentMinute2 = totalMinutes2 % 60
            totalHours2 = totalMinutes2 // 60
            currentHour2 = totalHours2 % 24
            print("The hour:minute:second for the elapsed time is", currentHour2, ":", currentMinute2, ":",
                  currentSecond2)


time_test = Time()
print("Current time is", currentHour, ":", currentMinute, ":", currentSecond)
time_elapsed = int(input("Enter the elapsed time:"))
time_test.setTime(time_elapsed)
