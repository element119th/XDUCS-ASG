
import math


class Complex:
    # 初始化
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b

    # 获取实部
    def getRealPart(self):
        return self.a

    # 获取虚部
    def getImaginaryPart(self):
        return self.b

    # 计算并返回和
    def __add__(self, num1):
        num2 = Complex()
        num2.a = self.a + num1.a
        num2.b = self.b + num1.b
        return num2

    # 计算并返回差
    def __sub__(self, num1):
        num2 = Complex()
        num2.a = self.a - num1.a
        num2.b = self.b - num1.b
        return num2

    # 计算并返回乘积
    def __mul__(self, num1):
        num2 = Complex()
        num2.a = self.a * num1.a - self.b * num1.b
        num2.b = self.a * num1.b + num1.a * self.b
        return num2

    # 计算并返回商
    def __truediv__(self, num1):
        num2 = Complex()
        num2.a = (self.a * num1.a + self.b * num1.b) / (num1.a * num1.a + num1.b * num1.b)
        num2.b = (self.b * num1.a - self.a * num1.b) / (num1.a * num1.a + num1.b * num1.b)
        return num2

    # 计算并返回模
    def __abs__(self):
        return math.sqrt(self.a * self.a + self.b * self.b)

    # 获取字符串形式的复数
    def __str__(self):
        if self.b == 0:
            return self.a
        elif self.b > 0:
            return "{}+{}i".format(self.a, self.b)
        else:
            return "{}{}i".format(self.a, self.b)


if __name__ == '__main__':
    # 读取两个复数
    a1, b1 = map(float, input("Enter the first complex number：").split(',', 2))
    a2, b2 = map(float, input("Enter the second complex number：").split(',', 2))
    number1 = Complex(a1, b1)
    number2 = Complex(a2, b2)
    # 输出
    print("({}) + ({}) = ({})".format(number1.__str__(), number2.__str__(), number1.__add__(number2).__str__()))
    print("({}) - ({}) = ({})".format(number1.__str__(), number2.__str__(), number1.__sub__(number2).__str__()))
    print("({}) * ({}) = ({})".format(number1.__str__(), number2.__str__(), number1.__mul__(number2).__str__()))
    print("({}) / ({}) = ({})".format(number1.__str__(), number2.__str__(), number1.__truediv__(number2).__str__()))
    print("|{}| = {}".format(number1.__str__(), number1.__abs__()))
