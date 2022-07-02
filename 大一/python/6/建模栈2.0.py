
# 创建一个Stack类
class Stack:
    # 初始化
    def __init__(self):
        self.__elements = []

    # 判断是否为空
    def isEmpty(self):
        return len(self.__elements) == 0

    # 返回栈顶元素但不删除
    def peek(self):
        if self.isEmpty():
            return None
        return self.__elements[len(self.__elements) - 1]

    # 放入一个元素
    def push(self, value):
        self.__elements.append(value)

    # 删除栈顶元素，并返回
    def pop(self):
        if self.isEmpty():
            return None
        return self.__elements.pop()

    # 返回栈中元素个数
    def getSize(self):
        return len(self.__elements)
