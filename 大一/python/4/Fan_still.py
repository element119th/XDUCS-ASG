
import tkinter as tk


class FanStill:
    def __init__(self):
        # 新建窗口并设置标题
        window = tk.Tk()
        window.title("Still_Fan")
        # 创建画布
        self.canvas = tk.Canvas(window, width=500, height=500, bg="white")
        # 布局画布
        self.canvas.pack()
        # 运用画圆弧画出扇叶，填充颜色
        self.canvas.create_arc(400, 400, 100, 100, start=0, extent=30, fill="blue")
        self.canvas.create_arc(400, 400, 100, 100, start=90, extent=30, fill="blue")
        self.canvas.create_arc(400, 400, 100, 100, start=180, extent=30, fill="blue")
        self.canvas.create_arc(400, 400, 100, 100, start=270, extent=30, fill="blue")
        window.mainloop()


FanStill()
