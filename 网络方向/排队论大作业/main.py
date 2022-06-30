import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from mpl_toolkits.mplot3d.axes3d import Axes3D

def get_matrix(n):
    #生成一步转移矩阵
    list = []
    for i in range(n):
        sum = 0
        r = np.random.random(n)
        for j in range(n):
            sum += r[j]
        for j in range(n):
            r[j] /= sum
        list.append(r)

    return list


def get_secondVaule(array, n):
    #求次大(绝对值)特征值
    value, evector = np.linalg.eig(array)
    value.sort()
    r = []
    for i in range(n):
        if type(value[i]) != np.float64:
            return 0
        if abs(value[i] - 1) > 1e-10:
            r.append(value[i])

    if abs(r[len(r)-1]) < abs(r[0]):
        return r[0]

    return r[len(r)-1]

def get_round(array):
    #求收敛轮数
    n = 0
    r = array
    while(1):
        n += 1
        r = np.dot(r, array)
        t = np.dot(r, array) == r
        if False not in t:
            return n
        if n > 100:
            return 0


if __name__ == '__main__':
    x = []
    y = []
    z = []
    for i in range(2, 9):
        print("测试第{}维矩阵".format(i))
        for j in range(100):
            print("计算矩阵{}".format(j + 1))
            while(1):
                array = get_matrix(i)
                value = get_secondVaule(array, i)
                if not value:
                    continue
                round = get_round(array)
                if not round:
                    continue
                x.append(value)
                y.append(i)
                z.append(round)
                break

    '''
    k = []
    d = []  
    for i in range(7):
        t = i*100
        xt = x[t:t + 100]
        yt = y[t:t + 100]
        d.append(i + 2)
        model = LinearRegression()
        xt = np.array(xt)
        yt = np.array(yt)
        model.fit(xt.reshape(-1, 1), yt.reshape(-1, 1))
        k.append(r2_score(yt, model.predict(xt.reshape(-1, 1)).reshape(1, -1)[0]))

    print(d)
    print(k)
    plt.bar(d, k, width=0.6)
    plt.xlabel("Dimension of Array")
    plt.ylabel("R^2 of Linear regression curve")
    #plt.ylim(0, 140)
    plt.title("Relationship between Dimension and R^2")
    plt.show()
    '''

    '''
    # 绘制最佳拟合线
    model = LinearRegression()
    xt = np.array(x[400:500])
    yt = np.array(y[400:500])
    model.fit(xt.reshape(-1, 1), yt.reshape(-1, 1))
    line_xticks = xt
    line_yticks = model.predict(xt.reshape(-1, 1))
    plt.scatter(xt, yt, color='g', label="train data")
    plt.plot(xt, line_yticks, color='black', linewidth=3, label="best line")
    # 添加图标标签
    plt.text(0.2, 60, "y = {:.2f}x + {:.2f}".format(float(model.coef_), float(model.intercept_)), size=15, color="r", style="italic")
    plt.legend(loc=2)
    plt.xlabel("The Second largest eigenvalue of Array")
    plt.ylabel("Convergence rounds")
    plt.title("Linear regression curve when dimension = 6")

    # 显示图像
    plt.show()
    '''


    fig = plt.figure(figsize=(12, 8))
    ax3 = plt.axes(projection='3d')
    ax3.view_init(elev=10., azim=300)
    ax3.set_xlim(-1, 1)
    ax3.scatter(x, y, z)
    #ax3.set_xlabel('The Second largest eigenvalue of Array', fontdict={'size': 25})
    #ax3.set_ylabel('Matrix dimension', fontdict={'size': 25})
    #ax3.set_zlabel('Convergence rounds', fontdict={'size': 25})
    #ax3.set_title('Array Analysis', fontdict={'size': 15})
    plt.show()










