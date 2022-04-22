# 5번 : 코드 실행 결과 예측
# 문제 코드
def fun_ex1(*args):
    sum = 0
    for i in range(0, len(args)):
        if type(args[i]) == int:
            sum += args[i]
    return sum

print(fun_ex1(1, 2, 'hello', '-6', 4.0, int(-2.5)))