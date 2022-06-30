from pyope.ope import OPE, ValueRange
import numpy as np
cipher = OPE(b'long key' * 2, in_range=ValueRange(9999, 1000000),
                              out_range=ValueRange(1, 5000000))

ran = 0

def OPE_crypt(f_str):
    '''
    计算NE数据集的保序加密结果
    输出文件：Crypt_NE.txt
    '''
    m = []
    sum = 0
    for line in f_str:
        sum += 1
        print("开始第 {} 轮加密".format(sum))
        tmp_list = line.split(' ')
        tmp_list[-1] = tmp_list[-1].replace('\n', '')  # 去掉换行符
        tmp_list[0] = cipher.encrypt(int(float(tmp_list[0]) * 1000000))
        tmp_list[1] = cipher.encrypt(int(float(tmp_list[1]) * 1000000))
        m.append(tmp_list)
    with open("Crypt_NE.txt", "w") as f:
        for i in m:
            for j in i:
                f.write(str(j))
                f.write(' ')
            f.write('\n')
        f.close()

def Kd_tree(point_list, depth = 0):
    '''
    给定二维数据集，生成 kd 树
    返回 kd 树元组
    '''
    if not point_list:
            return None
    if len(point_list) == 1:
            return (point_list[0], None, None)
    # 反复切换坐标轴对数据集进行排序
    axis = depth % 2
    # 指定第 axis 个元素对数据集进行排序
    point_list.sort(key=lambda point: point[axis])
    median = len(point_list) // 2
    return (point_list[median],
            Kd_tree(point_list[:median], depth + 1),
            Kd_tree(point_list[median + 1:], depth + 1))

def get_distance(point1, point2):
    '''
    计算两点之间的距离
    '''
    return (point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2

def get_pdistance(point, kd_point, depth):
    '''
    在 axis 方向上计算 point 与 kd_point 所划分超平面的距离
    '''
    axis = depth % 2
    return abs(point[axis] - kd_point[axis])

def Nearest_inquiry(kd_tree, point, depth = 0):
    '''
    最近邻查询算法
    给定 kd 树，查询点 point 的最近邻点及其距离
    '''
    global ran
    ran += 1
    if kd_tree is None:
        return (None, float('inf'))
    axis = depth % 2
    mpoint = kd_tree[0]
    # 递归寻找较邻点
    if point[axis] <= kd_tree[0][axis]:
        near_point, near_distance = Nearest_inquiry(kd_tree[1], point, depth + 1)
    else:
        near_point, near_distance = Nearest_inquiry(kd_tree[2], point, depth + 1)
    distance = np.linalg.norm(np.array(point) - np.array(mpoint))
    if near_distance is None or distance < near_distance:
        near_distance = distance
        near_point = mpoint

    # 计算圆是否与超平面相交, 相交则递归找出子树最短距离
    pdistance = get_pdistance(point, mpoint, depth)
    if pdistance < near_distance:
        if point[axis] <= mpoint[axis]:
            pnear_point, pnear_distance = Nearest_inquiry(kd_tree[1], point, depth + 1)
        else:
            pnear_point, pnear_distance = Nearest_inquiry(kd_tree[2], point, depth + 1)
        if pnear_distance < near_distance:
            near_point = pnear_point
            near_distance = pnear_distance

    return (near_point, near_distance)

if __name__ == '__main__':
    with open("NE.txt", "r") as f:  # 打开文件
        file_str = f.readlines()  # 读取文件
        f.close()

    #OPE_crypt(file_str)

    point_list = []
    # 将文件中的数据转换为二维数据集
    with open("NE.txt", "r") as f:  # 打开文件
        c_str = f.readlines()  # 读取文件
        for line in c_str:
            ctmp_list = line.split(' ')
            ctmp_list[-1] = ctmp_list[-1].replace('\n', '')  # 去掉换行符
            ctmp_list[0] = float(ctmp_list[0])
            ctmp_list[1] = float(ctmp_list[1])
            point_list.append(ctmp_list)
        f.close()

    # 创建 kd 树
    kd_tree = Kd_tree(point_list)

    # 进行最近邻查询
    while(1):
        print("请输入查询点：")
        point = input()
        point = point.split(' ')
        point[-1] = point[-1].replace('\n', '')
        point[0] = float(point[0])
        point[1] = float(point[1])
        print("最近邻点为：", Nearest_inquiry(kd_tree, point)[0])
        print("查询总次数：{}".format(ran))
        print("是否继续查询？(y/n)")
        ran = 0
        if input() == 'n':
            break

    print("查询结束")



