
# 创建一个Stack类
class Stack:
    # 初始化
    def __init__(self):
        self.__elements = []

    # 判断是否为空
    def isEmpty(self):
        if len(self.__elements) == 0:
            return True
        else:
            return False

    # 返回栈顶元素但不删除
    def peek(self):
        return self.__elements[len(self.__elements) - 1]

    # 放入一个元素
    def push(self, value):
        self.__elements[len(self.__elements)] = value

    # 删除栈顶元素，并返回
    def pop(self):
        temp = self.__elements[len(self.__elements) - 1]
        self.__elements.pop()
        return temp

    # 返回栈中元素个数
    def getSize(self):
        return len(self.__elements)
