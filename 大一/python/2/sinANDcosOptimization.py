
from Optimization import drawline
from Optimization import write_text
from Optimization import draw_arrowhead

import turtle as t
import math

t.title("sin和cos的图像2.0")
t.speed(0)
t.setup(width=800, height=650)

drawline(-350, 0, 350, 0)
draw_arrowhead(350, 0, 0)
drawline(0, -300, 0, 300)
draw_arrowhead(0, 300, 1)
write_text(-100*math.pi, -15, "-2\u03c0")
write_text(100*math.pi, -15, "2\u03c0")

# sin图像
t.penup()
t.goto(-350, 25 * math.sin(-350 / 50) * 2 * math.pi)
t.pendown()
t.pencolor("blue")
for x in range(-350, 350):
    t.goto(x, 25 * math.sin(x / 50) * 2 * math.pi)
# cos图像
t.penup()
t.goto(-350, 25 * math.cos(-350 / 50) * 2 * math.pi)
t.pendown()
t.pencolor("red")
for x in range(-350, 350):
    t.goto(x, 25 * math.cos(x / 50) * 2 * math.pi)
t.done()