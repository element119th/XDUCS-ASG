
import math
import turtle as t

t.title("sin的图像")
t.speed(0)
t.setup(width=800, height=650)

# x轴
t.penup()
t.goto(-350, 0)
t.pendown()
t.goto(350, 0)
t.penup()
t.goto(340, 10)
t.pendown()
t.goto(350, 0)
t.goto(340, -10)

# 画x轴上的-2pi和2pi
t.penup()
t.goto(-100*math.pi, -15)
t.pendown()
t.write("-2\u03c0")
t.penup()
t.goto(100*math.pi, -15)
t.pendown()
t.write("2\u03c0")

# y轴
t.penup()
t.goto(0, -300)
t.pendown()
t.goto(0, 300)
t.penup()
t.goto(10, 290)
t.pendown()
t.goto(0, 300)
t.goto(-10, 290)

# sin图像
t.penup()
t.goto(-350, 25 * math.sin(-350 / 50) * 2 * math.pi)
t.pendown()
for x in range(-350, 350):
    t.goto(x, 25 * math.sin(x / 50) * 2 * math.pi)
t.done()
