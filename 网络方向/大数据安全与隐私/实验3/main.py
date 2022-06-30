import pandas as pd

k_num = 5
# 属性列名
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
# 非数值型数据
categorical = set((
    'workclass',
    'education',
    'marital-status',
    'occupation',
    'relationship',
    'sex',
    'native-country',
    'race',
    'income',
))

# 准标识符集
feature_columns = [
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
    'native-country'
]
# 敏感数据
sensitive_column = 'income'


df = pd.read_csv("adult.data.txt", sep=", ", header=None, names=names, index_col=False, engine='python')
# 转化非数值型数据为分类类型，提高索引速度
for name in categorical:
    df[name] = df[name].astype('category')

#print(df.head(20))

# 计算分区中所有列的跨度，数值型为差值，非数值型为分类类型的个数
def get_spans(df, partition, scale=None):
    spans = {}
    for column in df.columns:
        if column in categorical:
            span = len(df[column][partition].unique())
        else:
            span = df[column][partition].max() - df[column][partition].min()
        if scale is not None:
            span = span / scale[column]
        spans[column] = span
    return spans

# 对某列的所有取值分割为左右两部分,返回左右两部分的索引值
def split(df, partition, column):
    dfp = df[column][partition]
    if column in categorical:
        values = dfp.unique()
        lv = set(values[:len(values) // 2])
        rv = set(values[len(values) // 2:])
        return dfp.index[dfp.isin(lv)], dfp.index[dfp.isin(rv)]
    else:
        median = dfp.median()
        dfl = dfp.index[dfp < median]
        dfr = dfp.index[dfp >= median]
        return (dfl, dfr)

# 判断数据是否满足k匿名要求, 即准标识符集是否至少含有k个记录（预先索引后）
def is_k_anonymous(df, partition, sensitive_column, k=5):
    if len(partition) < k:
        return False
    return True

# 分割数据集索引值直至满足k匿名要求的较小值
def partition_dataset(df, feature_columns, sensitive_column, scale, is_valid):
    global k_num
    finished_partitions = []
    partitions = [df.index]
    while partitions:
        partition = partitions.pop(0)
        spans = get_spans(df[feature_columns], partition, scale)
        for column, span in sorted(spans.items(), key=lambda x: -x[1]):
            lp, rp = split(df, partition, column)
            if not is_valid(df, lp, sensitive_column, k_num) or not is_valid(df, rp, sensitive_column, k_num):
                continue
            partitions.extend((lp, rp))
            break
        else:
            finished_partitions.append(partition)
    return finished_partitions

# 聚合准标识符集, 非数值型数据聚合为一个列, 数值型聚合为均值
def agg_categorical_column(series):
    return [','.join(set(series))]

def agg_numerical_column(series):
    return series.mean()

def build_anonymized_dataset(df, partitions, feature_columns, sensitive_column, max_partitions=None):
    aggregations = {}
    for column in feature_columns:
        if column in categorical:
            aggregations[column] = agg_categorical_column
        else:
            aggregations[column] = agg_numerical_column
    rows = []
    sum= 0
    for i, partition in enumerate(partitions):
        sum += 1
        if i % 1000 == 0 and i:
            print("聚合完成 {} 次分割...".format(i))
        if max_partitions is not None and i > max_partitions:
            break
        # 聚合分割行
        grouped_columns = df.loc[partition].agg(aggregations, squeeze=False)
        # 聚合后加入敏感值计数列
        sensitive_counts = df.loc[partition].groupby(sensitive_column).agg({sensitive_column: 'count'})
        df2 = grouped_columns.to_frame()
        grouped_columns = pd.DataFrame(df2.values.T, columns=df2.index)
        values = grouped_columns.iloc[0].to_dict()
        for sensitive_value, count in sensitive_counts[sensitive_column].items():
            if count == 0:
                continue
            values.update({
                sensitive_column: sensitive_value,
                'count': count,
            })
            rows.append(values.copy())
    print("聚合完成 {} 次分割...".format(sum))
    return pd.DataFrame(rows)



if __name__ == '__main__':
    k_num = int(input("请输入 k 匿名的 k 值: "))
    full_spans = get_spans(df, df.index)
    finished_partitions = partition_dataset(df, feature_columns, sensitive_column, full_spans, is_k_anonymous)
    dfn = build_anonymized_dataset(df, finished_partitions, feature_columns, sensitive_column)
    dfn = dfn.apply(lambda x: x.explode().astype(str).groupby(level=0).agg(", ".join))
    dfn = dfn.sort_values(feature_columns + [sensitive_column])
    dff = dfn.iloc[:, [0, -1]]
    dff.to_csv('k_result.csv', sep=',')
