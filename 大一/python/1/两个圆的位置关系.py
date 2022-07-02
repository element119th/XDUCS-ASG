
import math


x1, y1 = map(int, input("请输入第一个圆的坐标：").split(',', 2))
r1 = int(input("请输入第一个圆的半径："))
x2, y2 = map(int, input("请输入第二个圆的坐标：").split(',', 2))
r2 = int(input("请输入第二个圆的半径："))
d = math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
rmax = r1 + r2
rmin = abs(r1 - r2)

if d > rmax:
    print("这两个圆相离。")
elif d == rmax:
    print("这两个圆外切。")
elif d > rmin:
    print("这两个圆相交。")
elif d == rmin:
    print("这两个圆内切。")
elif r1 > r2:
    print("圆1内含圆2。")
else:
    print("圆2内含圆1。")
