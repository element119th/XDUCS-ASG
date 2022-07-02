
import tkinter as tk


class Calculate:
    def __init__(self):
        # 创建一个窗口
        window = tk.Tk()
        # 设置窗口标题
        window.title("Investment Calculator")
        # 分别创建四个标签，并设置好位置
        tk.Label(window, text="Investment Amount").grid(row=0, padx='10', pady='5')
        tk.Label(window, text="Years").grid(row=1, padx='10', pady='5')
        tk.Label(window, text="Annual Interest Rate").grid(row=2, padx='10', pady='5')
        tk.Label(window, text="Future Value").grid(row=3, padx='10', pady='5')
        # 设置三个文本框和一个标签
        self.amount = tk.StringVar()
        tk.Entry(window, justify='right', textvariable=self.amount).grid(row=0, column=1, padx='10')
        self.years = tk.StringVar()
        tk.Entry(window, justify='right', textvariable=self.years).grid(row=1, column=1)
        self.rate = tk.StringVar()
        tk.Entry(window, justify='right', textvariable=self.rate).grid(row=2, column=1)
        self.value = tk.StringVar()
        tk.Label(window, state='disabled', cursor='arrow', textvariable=self.value).grid(row=3, column=1)
        # 设置按钮
        calculate = tk.Button(window, text="Calculate", command=self.compute)
        calculate.grid(row=4, column=1)
        window.mainloop()

    # 按钮命令函数
    def compute(self):
        value = float(self.amount.get()) * ((1 + float(self.rate.get()) / 100) ** float(self.years.get()))
        self.value.set(format(value, "10.2f"))


Calculate()
