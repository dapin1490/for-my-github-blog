# 8번 : 복소수 오일러 정리 증명 -> 몰라 이게 뭔데
import cmath as cm
PI = cm.pi

def oil(x):
    exp_ix = cm.cos(x) + cm.sqrt(-1) * cm.sin(x)
    return exp_ix + 1 / exp_ix == 2 * cm.cos(x)

xs = [0, PI / 2, PI, PI * 3 / 2, PI * 2]
for i in xs:
    print(oil(i))