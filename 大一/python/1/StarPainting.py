
import turtle   # 导入turtle

turtle.title("五角星绘制")
turtle.speed(5)  # 调节画笔速度
turtle.bgcolor('#10aec2')  # 画布背景颜色
turtle.pencolor('#93d5dc')  # 画笔颜色


for i in range(5):  # for循环画五角星
    turtle.forward(100)
    turtle.right(144)

turtle.done()  # 画图界面暂停而不退出,方便截图
