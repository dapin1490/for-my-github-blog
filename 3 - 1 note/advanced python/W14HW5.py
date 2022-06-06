import pandas as pd
import numpy as np

def make_sample(dt, cnt):
    return dt.iloc[0:cnt, :]

def sample_mean(sam, n, m):
    cols = list(sam.columns)
    for i in range(3):
        m[n][i] = sam[cols[i]].sum() / sam[cols[i]].count()
    return

def sample_v(sam, n, m, v):
    cols = list(sam.columns)
    for i in range(3):
        sam[str(i + 3)] = (sam[cols[i]] - m[n][i]) ** 2
        v[n][i] = sam[str(i + 3)].sum() / sam[str(i + 3)].count()
    return

def sample_max_min(sam, n, mx, mn):
    cols = list(sam.columns)
    for i in range(3):
        mx[n][i] = sam[cols[i]].max()
        mn[n][i] = sam[cols[i]].min()
    return

def sample_top5(sam, n, tn, ts):
    cols = list(sam.columns)
    for i in range(3):
        sam = sam.sort_values(cols[i])
        for j in range(5):
            idx = int(sam[cols[i]].count() * 0.01 * tn[j])
            ts[n][i][j] = sam.iloc[(idx - 1):idx, i:(i + 1)].values
    return

stat_dist_csv = "stat_dist.csv"
samples = [10, 20, 30, 50, 100]
tops = [10, 30, 50, 70, 90]
data = pd.read_csv(stat_dist_csv)
data = data.sample(frac=1)
colum = list(data.columns)

means = np.zeros((5, 3))  # 평균
stds = np.zeros((5, 3))  # 표준편차 : 편차의 제곱의 평균의 제곱근
vrs = np.zeros((5, 3))  # 분산 : 편차의 제곱의 평균
maxs = np.zeros((5, 3))  # 최댓값
mins = np.zeros((5, 3))  # 최솟값
top5 = np.zeros((5, 3, 5))  # 5분위


for i in range(5):
    sp = make_sample(data, samples[i])
    sample_mean(sp, i, means)
    sample_v(sp, i, means, vrs)
    sample_max_min(sp, i, maxs, mins)
    sample_top5(sp, i, tops, top5)

stds = vrs ** 0.5

print("평균")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        print(f"{colum[j]} : {means[i][j]}")
    print()

print("\n표준편차")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        print(f"{colum[j]} : {stds[i][j]}")
    print()

print("\n분산")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        print(f"{colum[j]} : {vrs[i][j]}")
    print()

print("\n최고")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        print(f"{colum[j]} : {maxs[i][j]}")
    print()

print("\n최저")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        print(f"{colum[j]} : {mins[i][j]}")
    print()

print("\n5분위")
for i in range(5):
    print(f"sample count : {samples[i]}")
    for j in range(3):
        for k in range(5):
            print(f"{colum[j]}, {tops[k]}% : {top5[i][j][k]}")
        print()
    print()
