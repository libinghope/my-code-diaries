import numpy
import collections as c
#KNN的意思就是K-Nearest Neighbors，K-最近邻算法，是一种基本的分类与回归方法。

if __name__=="__main__":

    print("Start KNN")

    # Load data

    data = numpy.array([
        [154,1],
        [126,2],
        [70,2],
        [196,3],
        [161,2],
        [371,4]
    ])

    # 输入值 feature 就是特征值
    feature = data[:,0]
    # 结果值 label 每个特征对应的结果值
    label = data[:,1]
    # 想要预测的特征值
    pridict = 200
    # 计算每个特征值与预测值的差值
    distance = list(map(lambda x:abs(x-pridict),feature))
    # 按照差值从小到大排序
    sortedIndex = numpy.argsort(distance)

    sortedLabel = label[sortedIndex]
    print("最小值的索引是：{0}, 离得最近的结果是{1}".format(sortedIndex[0], sortedLabel[0]))

    # 选择最近的K个点
    K = 3
    pridictResult = c.Counter(sortedLabel[:K]).most_common(1)[0][0]

    print("预测结果是：{0}".format(pridictResult))
    print("End KNN")