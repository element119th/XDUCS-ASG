
# 父类
class GeometricObject:
    # 初始化
    def __init__(self):
        self.__color = "green"
        self.__filled = True

    # 创建一个带有指定颜色的填充的对象
    def GeometricObject(self, color, filled):
        self.__color = color
        self.__filled = filled

    # 获取颜色
    def getColor(self):
        return self.__color

    # 配置颜色
    def setColor(self, color):
        self.__color = color

    # 获取填充情况
    def isFilled(self):
        return self.__filled

    # 设置是否填充
    def setFilled(self, filled):
        self.__filled = filled

    # 返回对象字符串
    def __str__(self):
        return "color:", self.__color, "filled:", self.__filled


import math


# 继承父类GeometricObject
class Circle(GeometricObject):
    # 初始化
    def __init__(self):
        self.__radius = 1.0
        # 父类的初始化
        super().__init__()

    # 创建一个带有半径，颜色，填充的对象
    def Circle(self, radius, color, filled):
        self.__radius = radius
        # 使用父类的方法设置属性
        super().setColor(color)
        super().setFilled(filled)

    # 获取半径
    def getRadius(self):
        return self.__radius

    # 配置半径
    def setRadius(self, radius):
        self.__radius = radius

    # 获取面积
    def getArea(self):
        return math.pi * self.__radius * self.__radius

    # 获取周长
    def getPerimeter(self):
        return 2 * math.pi * self.__radius

    # 获取直径
    def getDiameter(self):
        return 2 * self.__radius

    # 打印对象属性
    def printCircle(self):
        print(self.__str__(), "radius:", str(self.__radius))

    # 返回对象的字符串，用到了方法覆盖
    def __str__(self):
        return super().__str__(), "radius:", self.__radius


# Rectangle类继承父类GeometricObject
class Rectangle(GeometricObject):
    # 初始化
    def __init__(self):
        self.__width = 1.0
        self.__height = 1.0
        # 父类的初始化
        super().__init__()

    # 创建一个带有宽，高，颜色，填充的对象
    def Rectangle(self, width, height, color, filled):
        self.__width = width
        self.__height = height
        # 父类方法配置属性
        super().setColor(color)
        super().setFilled(filled)

    # 获取宽度
    def getWidth(self):
        return self.__width

    # 配置宽度
    def setWidth(self, width):
        self.__width = width

    # 获取高度
    def getHeight(self):
        return self.__height

    # 配置高度
    def setHeight(self, height):
        self.__height = height

    # 获取面积
    def getArea(self):
        return self.__height * self.__width

    # 获取周长
    def getPerimeter(self):
        return 2 * (self.__height + self.__width)

    # 返回对象字符串，用到了方法覆盖
    def __str__(self):
        return super().__str__(), "height:", self.__height, "width:", self.__width
