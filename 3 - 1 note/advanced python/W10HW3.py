'''
하기 리스트를 입력값으로 하여
1) 정수별로 카운트를 하는 함수를 만들고,
2) 각 정수별로 카운트된 값을 바 형식으로 출력하는 그림을 png 형태로 저장하는 함수를 파이썬으로 작성하시요. (4점)
[0, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 2, 4, 4, 3, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 3, 4, 4, 1, 3, 4, 4, 2, 4, 2, 2, 4, 4, 2, 4, 3, 4, 4, 2, 4, 4, 2, 4, 4, 3, 4, 3, 4, 2, 4, 0, 3, 1, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 3, 2, 3, 4, 4, 4, 3]
'''

import numpy as np
import matplotlib.pyplot as plt


# (1) 정수별로 카운트를 하는 함수
def int_count(in_list):
    int_range = list(set(in_list))  # set으로 중복 제거 후 list로 만듦
    int_range.sort()  # [0, 1, 2, 3, 4]
    int_length = len(int_range)
    count_list = np.zeros(int_length)

    for n in in_list:
        # 입력 리스트에 포함된 정수가 연속되지 않거나 음수가 있을 수 있으므로
        # n을 count_list의 인덱스에 바로 대입하지 않고 int_range 리스트의 인덱스를 이용한다.
        count_list[int_range.index(n)] += 1
    
    return int_range, count_list


# (2) 각 정수별로 카운트된 값을 바 형식으로 출력하는 그림을 png 형태로 저장하는 함수
# 그래프의 제목과 축 이름을 한글로 쓰면 그림에 네모 형태로밖에 나오지 않아 영어로 썼습니다.
def save_count_bar(x, y):
    plt.bar(x, y)
    plt.title("count each integer in bar format", fontdict={"fontsize":15})
    plt.xlabel("integer that exists in the list", fontdict={"fontsize":10})
    plt.ylabel("the number of each integer", fontdict={"fontsize":10})
    plt.savefig('count_integer_bar.png')
    return


input_list = [0, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 2, 4, 4, 3, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 3, 4, 4, 1, 3, 4, 4, 2, 4, 2, 2, 4, 4, 2, 4, 3, 4, 4, 2, 4, 4, 2, 4, 4, 3, 4, 3, 4, 2, 4, 0, 3, 1, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 3, 2, 3, 4, 4, 4, 3]
int_range, count_list = int_count(input_list)
save_count_bar(int_range, count_list)
