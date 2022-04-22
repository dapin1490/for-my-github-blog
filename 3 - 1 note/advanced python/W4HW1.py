# 1번
'''
아래와 같은 코드가 존재한다. 현재까지 배운 내용을 활용하여서 3줄로 코드 최적화를 하여
제출하시요. 다만 하기 조건을 따르시요. (1점)

> print내에서 format 활용 필수

> 예시 코드 생략
'''
# 제출
x = int(input("입력 숫자1:"))
y = int(input("입력 숫자2:"))
a = int(input("비교 숫자:"))
print("내가 계산한 {}의 {} 덧셈 결과값은 {}이며 실제 {}와 비교 시 동일 여부는 {}이다.".format(x, y, x + y, a, a == (x + y)))

# 해답
x, y, a = map(int, input("입력숫자1/2, 비교 숫자를 차례대로 입력하시요.").split())
b = (a == x + y)
print("내가 계산한 {}의 {}의 덧셈결과값은 {} 이며 실제 {}와 비교시 동일여부는 {}이다".format(x, y, x + y, a, b))


# 2번
'''
입력값1을 입력값2로 제곱하여 출력하는 코드를 생성하고자 한다. <Fill in the blank.> 부분을
업데이트해서 제출 하시오. 다만 하기 조건을 따르시요. (1점)
> def를 활용한 함수 생성 불가능
> 이중 스타 사용 불가능 (예: **)
> 문자열 입력시 에러 핸들링 가능 필수
'''
# 제출
x = input("입력값 1:")
y = input("입력값 2:")
z = 1
try:
    x = int(x)
    y = int(y)
except ValueError:
    print("INPUT ERROR")
else:
    for _ in range(y):
        z *= x
    print("x의 y 제곱 결과값은", z, "이다.")

# 해답
x = input("입력값 1:")
y = input("입력값 2:")

flag = True
try:
    x_int = int(x)
    y_int = int(y)
    z = 1
    for idx in range(0, y_int):
        z = z*x_int
except:
    print("에러로 작동이 불능합니다. 다시 입력 부탁드립니다.")
    exit(0)
else:
    print("성공적으로 마무리 하였습니다.")

print("x의 y제곱 결과값은", z, "이다.")


# 3번
'''
입력값1 부터 입력값2 까지 숫자 카운트를 print로 진행하는 코드를 만들고자 한다. 해당 코
드를 만들어서 제출하시요. 다만 하기 조건을 따르시요. (1점)

> 입력값1/2 부재시 기본값으로 각각 1, 100 정의 필수
> 정확하게 입력값1부터 입력값2까지 출력 필수
> 입력값 1이 입력값2보다 크면 프로그램 종료 혹은 에러처리 필수
> 문자값 입력시 에러 처리 필수
> sleep 함수 이용 불필요
'''
# 제출
def print_count(a = 1, b = 100):
    try:
        a = int(a)
        b = int(b)
    except ValueError:
        print("INPUT ERROR")
        return
    
    if a > b:
        print("first number must be less than second number")
        return
    
    for i in range(a, b + 1):
        print(i)

n1 = input("입력값 1 : ")
n2 = input("입력값 2 : ")
print_count(n1, n2)  # 숫자를 제대로 입력했다면 한 줄에 하나씩 n1부터 n2까지 출력, 그렇지 않다면 입력 오류 문구 출력됨
print_count(80)  # 80부터 100까지 출력
print_count(5, 2)  # 대소관계가 올바르지 않아 오류 문구를 출력하고 종료
print_count(101)  # 101은 a로 전달되고, b는 아무런 인수도 전달되지 않아 기본값인 100이기 때문에 대소관계 오류 문구 출력됨
print_count()  # 1부터 100까지 출력

# 해답
def count_f(num1=1,num2=100):
    for idx in range(num1,num2+1):
        print(idx)


x = input("입력값 1:")
y = input("입력값 2:")


# 4번
'''
하기와 같은 함수를 포함한 코드가 존재한다. lambda를 활용하여서 동일한 결과값을 출력하
는 코드를 단 3줄로 정리하여 제출하시요. (1점)

> 코드 생략
'''
# 제출
x = int(input("입력값 1 : "))
y = int(input("입력값 2 : "))
print("제곱 결과값은", (lambda x, y : x ** y)(x, y), "이며 덧셈 결과값은", (lambda x, y : x + y)(x, y), "이다.")

# 해답
num_cal = lambda x,y: (x ** y, x + y)
b, c = num_cal(2, 100)
print("제곱 결과값은", b,"이며 덧셈 결과값은 ", c,"이다.")
