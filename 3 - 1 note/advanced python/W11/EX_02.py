import numpy as np
import matplotlib.pyplot as plt

# 이미지 표시 : 보여주기
arr1 = plt.imread('/kaggle/input/220513-img-sample/3.27 flower.jpg')
# print(arr1, end="\n\n")
# [픽셀 값 배열 생략] (960, 720, 3) 가로 960, 세로 720, RGB 칼라 이미지

plt.imshow(arr1)
print(arr1.shape, end="\n\n")
plt.show()

# 이미지 클리핑 : 특정 영역만 잘라서 보여주기
arr2 = arr1[300:700, 300:650, :]  # 가로줄 범위, 세로줄 범위, 색상 차원 지정(R, G, B 중 1개만 혹은 셋 다. 일부만 넣으면 오류 남)
plt.imshow(arr2)
plt.show()

# 이미지 반전 : 축에 대해 뒤집기
arr3 = np.flip(arr1, axis=1)  # 0 : 상하반전, 1 : 좌우반전
plt.imshow(arr3)
plt.show()

# 이미지 grayscale : 이미지 흑백화하기
def rgb2gray(rgb):
    r, g, b = rgb[:, :, 0], rgb[:, :, 1], rgb[:, :, 2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b
    return gray

arr4 = rgb2gray(arr1)
plt.imshow(arr4, cmap = "gray")
plt.show()

# ------------------------

# 한 figure에 모아서 보기

plt.figure(figsize=(20, 20))

plt.subplot(2, 2, 1) # row의 개수, column의 개수, 몇 번째
plt.imshow(arr1)
plt.xlabel("1. original", fontdict={"fontsize":20})

plt.subplot(2, 2, 2)
plt.imshow(arr2)
plt.xlabel("2. clip", fontdict={"fontsize":20})

plt.subplot(2, 2, 3)
plt.imshow(arr3)
plt.xlabel("3. flip", fontdict={"fontsize":20})

plt.subplot(2, 2, 4)
plt.imshow(arr4, cmap = "gray")
plt.xlabel("4. grayscale", fontdict={"fontsize":20})

plt.show()
