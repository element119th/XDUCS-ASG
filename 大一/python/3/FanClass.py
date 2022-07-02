
SLOW = 1
MEDIUM = 2
FAST = 3


class Fan:
    # 构造方法初始化
    def __init__(self):
        self.__speed = SLOW
        self.__on = False
        self.__radius = 5.0
        self.__color = "blue"

    # 速度访问器
    def get_speed(self):
        return self.__speed

    # 速度修改器
    def set_speed(self, newSpeed):
        if SLOW <= newSpeed <= FAST:
            self.__speed = newSpeed
        else:
            print("风速输入有误，请重新输入：Error!")

    # 开关访问器
    def get_on(self):
        return self.__on

    # 开关修改器
    def set_on(self, newOn):
        self.__on = newOn

    # 半径访问器
    def get_radius(self):
        return self.__radius

    # 半径修改器
    def set_radius(self, newRadius):
        self.__radius = newRadius

    # 颜色访问器
    def get_color(self):
        return self.__color

    # 颜色修改器
    def set_color(self, newColor):
        self.__color = newColor


# 创建一个实例
Fan1 = Fan()
Fan2 = Fan()


def print_info(fan):
    print("风扇速度为:", fan.get_speed())
    print("风扇开关情况为:", fan.get_on())
    print("风扇半径为:", fan.get_radius())
    print("风扇颜色为:", fan.get_color())


def menu():
    while True:
        choice1 = int(input("菜单：\n0.创建新的风扇;\n1.获取当前风扇信息;\n2.设置新的风扇属性;\n3.退出\n请输入序号继续："))
        if choice1 == 1:
            print_info(Fan1)
        elif choice1 == 2:
            while True:
                choice3 = int(input("菜单：\n1.设置风扇速度；\n2.设置风扇开关；\n3.设置风扇半径；\n4.设置风扇颜色。\n5.退出\n请输入序号继续："))
                match choice3:
                    case 1:
                        speed = int(input("请输入风扇速度："))
                        Fan1.set_speed(speed)
                        print("修改后风扇速度为:", Fan1.get_speed())
                    case 2:
                        on = bool(input("请输入风扇开关：(True 或 False)"))
                        Fan1.set_on(on)
                        print("修改后风扇开关情况为:", Fan1.get_on())
                    case 3:
                        radius = float(input("请输入风扇半径："))
                        Fan1.set_radius(radius)
                        print("修改后风扇半径为:", Fan1.get_radius())
                    case 4:
                        color = input("请输入风扇颜色：")
                        Fan1.set_color(color)
                        print("修改后风扇颜色为:", Fan1.get_color())
                if choice3 == 5:
                    break
        elif choice1 == 0:
            speed2, on2, radius2, color2 = map(str, input("请输入风扇属性:").split(',', 4))
            Fan2.set_speed(int(speed2))
            Fan2.set_on(bool(on2))
            Fan2.set_radius(float(radius2))
            Fan2.set_color(str(color2))
            print_info(Fan2)
        else:
            break


menu()
