# 1번
'''
다음 조건을 만족하는 함수를 구현하시오. (1점)
- 함수의 이름은 fun_ex1
- 함수의 인수의 개수는 정해져 있지 않음  # -> 가변 매개변수
- 들어오는 매개변수 중 정수형을 모두 선택하여 전부 더한 값을 return함 (단, 정수형이 없는 경우 0을 return)
'''
# 제출
def fun_ex1(*ns):
    ans = 0
    for i in ns:
        if type(i) == int:
            ans += i
    return ans

print("# 1 test")
print("# 1 input : (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, \"asd\", \"123\", 3.0)")
print(fun_ex1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, "asd", "123", 3.0), end="\n\n")

# 해답
def fun_ex1_sol(*args):
    sum = 0
    for i in range(0, len(args)):
        if type(args[i]) == int:
            sum += args[i]
    return sum


# 2번
'''
수업시간에 배운 도함수에 이어 정적분을 계산하는 함수를 구현하려고 한다. (2점)
- 함수의 이름은 fun_int
- 함수를 호출할 때 매개변수는 자연수만 넣으며 다음과 같이 구성된다.
-- 디폴트 매개변수 start = 0, end = 1
-- 일반 매개변수 N
-- 가변 매개변수 (가변 매개변수는 계산하고자 하는 다항식의 계수)
- 적분값은 다음과 같이 계산한다. (수식 생략)
- 예를 들어 fun_int(10, 1, 2, 3, start = 0, end = 1)을 넣는다면
  (수식 생략)의 함수에 대하여 start부터 end까지의 적분값을 구하되
  10개의 구간으로 나누어 구분구적법을 취하는 것 
- 필요시 math 모듈의 함수를 사용하여도 상관없으나, 위의 구분구적법 부분은 반드시 구현을 할 것
'''
# 제출
# f(x) 구현
def f(x, a):  # x는 입력값, a는 계수(들) -> 튜플 타입
    ans = 0
    for i in range(len(a)):
        ans += a[i] * x ** i
    return ans

def fun_int(N, *ns, start = 0, end = 1):
    # 필요한 것 : f(x) 구현, 구간을 정해진 개수로 나누어 한 구간의 길이 구하기, 시그마 연산 구현
    i = start
    ans = 0
    # 시그마 연산 구현
    for k in range(N):
        x = start + i * (end - start) / N
        ans = ans + f(x, ns) * (end - start) / N
        i += 1
        # print("i = {}\nans = {}".format(i, ans))
    # 결과 반환
    return round(ans, 10)  # 부동소수점 때문에 round() 사용

print("# 2 test")
print("# 2 input : (10, 1, 2, 3, start = 0, end = 1)")
print(fun_int(10, 1, 2, 3, start = 0, end = 1), end="\n\n")  # N이 커질수록 3에 수렴해야 맞음
print("# 2 input : (10, 1, start = 0, end = 1)")
print(fun_int(10, 1, start = 0, end = 1), end="\n\n")  # 답은 1

# 해답
import math
def fun_int_sol(N, *F, start=0, end=1):
    result = 0
    for i in range(0, N):
        x = start + (i*(end-start))/N
        fx = 0
        for j in range(0, len(F)):
            fx += F[j]*math.pow(x,j)
        sub_result = fx * ((end-start)/N)
        result += sub_result
    return result


# 3번
'''
다음 함수들은 딥러닝 활성화함수 (activation function)로 많이 사용되는 함수들이다.
다음 함수들의 정의를 찾은 후 각 함수의 정의에 따라 값을 return하는 함수를 구현하시오.
(단, Numpy 등의 라이브러리는 사용 불가능하며 math 모듈에 있는 함수는 사용 가능하며,
math 모듈에 있는 함수는 https://docs.python.org/3/library/math.html 에서 확인 가능하다.) (1점)

- sigmoid, tanh, ReLU, Leaky ReLU 
'''
# 제출
import math

ne = math.e  # 수학 상수 e

# sigmoid 시그모이드
def ex_sigmoid(x):
    return ne ** x / (ne ** x + 1.0)

# tanh 하이퍼볼릭 탄젠트
def ex_tanh(x):
    return (1.0 - ne ** (-x)) / (1.0 + ne ** (-x))

# ReLU 렐루
def ex_ReLU(x):
    return max(0.0, x)

# Leaky ReLU 리키 렐루
def ex_Leaky_ReLU(x, a):  # x는 입력값, a는 입력값이 0보다 작을 때의 가중치
    if x >= 0.0:
        return x
    else:
        return a * x

print("# 3 test")
print("# 3 input : -2, -1, 0, 1, 2")

for i in range(-2, 3):
    print("sigmoid({}) = {:.3f}".format(i, ex_sigmoid(i)))
    print("tanh({}) = {:.3f}".format(i, ex_tanh(i)))
    print("ReLU({}) = {}".format(i, ex_ReLU(i)))
    print("Leaky ReLU({}, 0.2) = {}".format(i, ex_Leaky_ReLU(i, 0.2)))
    print("\n")

# 해답
import math
def sigmoid_sol(x):
    result = 1 / (1 + math.exp(-x))
    return result

def tanh_sol(x):
    result = (math.exp(x) - math.exp(-x)) / (math.exp(x) + math.exp(-x))
    return result

def ReLU_sol(x):
    if x > 0:
        return x
    else:
        return 0

def Leaky_ReLU_sol(x,a):
    if x > 0:
        return x
    else:
        return a*x