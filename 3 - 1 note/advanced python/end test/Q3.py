'''
준세는 선배한테 x가 아주 작을 때는 y=log(1+x)와 y=x가 거의 유사하다는 얘기를 듣고 고급파이썬프로그래밍 학생들에게 Python을 이용하여 그래프를 그려달라고 부탁하기고 하였다.
Numpy와 Matplotlib를 활용하여, 다음 조건을 만족하는 그래프를 구현하시오.
(기록자 주: 오타도 그대로 썼음)

조건:
x는 0부터 2.0까지 51개의 등간격으로 찍을 것
log(1+x)에서 log는 자연로그. (hint: np.log()를 활용할 것)
figure의 size는 (7,6)
y=log(1+x)는 파란색 실선, y=x는 붉은색 실선으로 하나의 axe 안에 중첩되어 그릴 것
xlabel은 x, ylabel은 values, title은 function comparison으로 입력할 것
legend는 upper left에 y=log(1+x), y=x가 나오도록 할 것
'''

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2.0, 51)
y_log = np.log(1 + x)
y_x = x

plt.figure(figsize=(7, 6))

plt.plot(x, y_log, "-b")
plt.plot(x, y_x, "-r")
plt.xlabel("x")
plt.ylabel("values")
plt.title("function comparison")
plt.legend(["y = log(1+x)", "y = x"], loc="upper left")

plt.show()

# 출력 이미지 생략
