import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

names = (
    'age',
    'workclass',
    'fnlwgt',
    'education',
    'education-num',
    'marital-status',
    'occupation',
    'relationship',
    'race',
    'sex',
    'capital-gain',
    'capital-loss',
    'hours-per-week',
    'native-country',
    'income',
)

# 读入原数据
df = pd.read_csv("adult.data.txt", sep=", ", header=None, names=names, index_col=False, engine='python')
avg_age_1 = df['age'].mean()

# 读入 k 匿名处理数据
dfk = pd.read_csv("k_result.csv", sep=",", index_col=False, engine='python')
dfk = dfk.iloc[:, [1, -1]]

# 读入 k 匿名处理删除数据
dfkd = pd.read_csv("k_result_delete.csv", sep=",", index_col=False, engine='python')
dfkd = dfkd.iloc[:, [1, -1]]

#设置数据规模
range = len(df)

#加入拉普拉斯噪声
def add_laplace_noise(data_list, μ=0, b=1):
    laplace_noise = np.random.laplace(μ, b, len(data_list)) # 为原始数据添加μ为0，b为1的噪声
    res = np.append((laplace_noise+data_list.T[0]),data_list.T[1]).T
    return res.reshape(2,len(data_list)).T
def age_mean(a):
    sage = 0
    scnt = 0
    for row in a:
        sage += row[0]*row[1]
        scnt += row[1]
    return sage/scnt

data1 = dfk.to_numpy()
data2 = dfkd.to_numpy()
print("原数据集年龄均值：" + str(avg_age_1))
x1 = age_mean(data1)
# 根据数据规模进行差分隐私处理
noise_list = add_laplace_noise(data1, b=10000/range)
print("差分隐私处理(加入拉普拉斯噪声)后的年龄均值：" + str(age_mean(noise_list)))
y1 = age_mean(noise_list)

# 对比删除数据集的年龄均值
print("删除一条数据后数据集年龄均值：" + str(age_mean(data2)))
x2 = age_mean(data2)
noise_list = add_laplace_noise(data2, b=10000/range)
print("差分隐私后的均值：" + str(age_mean(noise_list)))
y2 = age_mean(noise_list)

# 分别对差分隐私处理前后的数据进行差分攻击
ans1 = x1*32561-x2*32560
ans2 = y1*32561-y2*32560
origin_data = 37
print("根据删除前后K匿名数据集的推出删除的年龄数据:", ans1)
print("根据加入噪声后K匿名数据集的推出删除的年龄数据:", ans2)
print("差分隐私后推测年龄误差率: {} %".format((ans2 - origin_data)/origin_data*100))

# 使用条形图展示结果
plt.bar(['Origin data', 'diff-privacy result', 'non-diff result'], [ans1, ans2, origin_data])
plt.show()
