
import threading
import tkinter as tk
import time

# 新建窗口，设置标题
window = tk.Tk()
window.title("Rotating_Fan")
# 新建画布，设置画布，布局画布
canvas = tk.Canvas(window, width=500, height=500, bg="white")
canvas.pack()
# 先画出静态的风扇
canvas.create_arc(400, 400, 100, 100, start=0, extent=30, fill="red")
canvas.create_arc(400, 400, 100, 100, start=90, extent=30, fill="red")
canvas.create_arc(400, 400, 100, 100, start=180, extent=30, fill="red")
canvas.create_arc(400, 400, 100, 100, start=270, extent=30, fill="red")

# 设置一个全局变量，方便用
start0 = 0


# 画风扇函数
def draw():
    global start0
    start0 += 10
    # 删掉原来的，重新画
    canvas.delete('all')
    canvas.create_arc(400, 400, 100, 100, start=start0, extent=30, fill="red")
    canvas.create_arc(400, 400, 100, 100, start=start0 + 90, extent=30, fill="red")
    canvas.create_arc(400, 400, 100, 100, start=start0 + 180, extent=30, fill="red")
    canvas.create_arc(400, 400, 100, 100, start=start0 + 270, extent=30, fill="red")


# 延迟函数
def delay():
    while 1:
        time.sleep(0.1)
        draw()


t = threading.Thread(target=delay)
t.start()
window.mainloop()
t.join()
