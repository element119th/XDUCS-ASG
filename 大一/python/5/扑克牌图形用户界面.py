
import random
from tkinter import *

class DeckOfCardsGUI:
    def __init__(self):
        # 创建一个窗口，设置窗口名称
        window = Tk()
        window.title("随机选牌")
        # 创建一个图片列表，存储图片
        self.imageList = []
        for i in range(1, 53):
            self.imageList.append(PhotoImage(file="card/" + str(i) + ".gif"))
        # 创建一个框架，作为容器
        frame = Frame(window)
        frame.pack()
        # 标签列表
        self.labelList = []
        for i in range(4):
            self.labelList.append(Label(frame, image=self.imageList[i]))
            self.labelList[i].pack(side=LEFT)
        # 创建一个shuffle的按钮，功能是洗牌
        Button(window, text="Shuffle", command=self.shuffle).pack()
        # 循环
        window.mainloop()

    def shuffle(self):
        random.shuffle(self.imageList)
        for i in range(4):
            self.labelList[i]["image"] = self.imageList[i]

DeckOfCardsGUI()
