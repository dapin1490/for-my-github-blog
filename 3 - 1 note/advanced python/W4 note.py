# 인수와 매개변수

# 예제 1 : f(x) = x^2 + 2x + 1
# x를 넣으면 f(x)를 return 하는 함수를 구현하라.
def f(x):
    return x ** 2 + 2 * x + 1

print(f(3))


# 가변 매개변수 : 변수에 사용하는 *과 비슷한 용도. 여러 개의 값을 한 파라미터에 받을 수 있다.
# 주의 : 함수 내에서 가변 매개변수를 여러 개 가질 수 없음
# 주의 : 가변 매개변수는 다른 매개변수보다 앞서 위치할 수 없음
def fs(num, *xs):
    ans = num * 10
    for n in xs:
        ans = (ans + n) * 10
    return ans // 10

print(fs(1, 2, 3, 4, 5, 6, 7, 8, 9))


# 예제 2 : 가변 매개변수를 이용하여 입력받은 모든 값을 출력하는 함수 구현
# 함수 내용 : 입력받은 모든 값을 곱한 값이 return되도록 함
def g(*ns):
    ans = 1
    for i in ns:
        ans *= i
    return ans

print(g(1, 5, 7, 10))


# 디폴트 매개변수 : 사용자가 인수를 넘기지 않아도 기본 값을 갖는 매개변수
# 반드시 기본값이 없는 매개변수보다 뒤에 나와야 한다.
# 세 가지 매개변수의 순서 : 일반 매개변수, 가변 매개변수, 디폴트 매개변수
# 세 가지를 혼용할 때에는 (주로 디폴트)매개변수명을 호출하여 직접 인자를 전달한다.

# 예제 3 : 두 개의 인자를 받는 함수 print_from_val(val, n) 구현
# n의 기본값 10
# 입력한 val부터 n - 1까지 출력하되 val이 n보다 크거나 같으면 오류 메시지 출력
def print_from_val(val, n = 10):
    if val >= n:
        print("input error")
        return
    else:
        for i in range(val, n):
            print(i, end=', ')
    print()

print_from_val(9)
print_from_val(10)  # input error
print_from_val(7, 11)
print_from_val(12, 11)  # input error


# 키워드 인자
# 인수들이 딕셔너리 형태로 처리됨
# 매개변수명 앞에 ** 붙임
# 다른 타입의 매개변수와 혼용 가능하지만 가장 마지막에 나와야 함
# 예시
def example(**param):
    for key, val in param.items():
        print("{} : {}".format(key, val))

example(a = 1, b = 2, c = "3")  # key는 따옴표 없이, value는 문자열이라면 따옴표 사용


# pass : 아무 짓도 안 하고 넘겨야 하지만 자리는 채워야 할 때
# 예시
for _ in range(1, 5):
    pass


# 지역변수와 전역변수
# 지역변수는 함수 내부에서 선언된 변수 또는 매개변수. 호출이 끝나면 사라짐.
# 전역변수는 프로그램 전역에서 선언된 변수. 함수 내부에서도 접근 가능하고 호출이 끝나도 사라지지 않음.
# global 변수명
# 이름은 중복될 수 없다. 다만 함수 내부에서 선언되는 지역변수와는 겹쳐도 된다.


# 함수 예시 : 도함수 구하기
def g(x):
    return 2 * x ** 3 + 3 * x + 5

def diff(x, h):
    return (g(x + h) - g(x)) / h

for h in [1e-1, 1e-2, 1e-4]:
    print('h =', h, 'diff =', diff(0, h), 'diff =', diff(1, h))


# 콜백 함수 : 다른 함수의 인자로써 넘겨진 후 특정 이벤트에 호출되는 함수
def call_5_times(func):
    for i in range(5):
        func(i)

def hello(num):
    print("hello", num)

call_5_times(hello)


# 람다식 : 약식 함수 정의
# 굳이 이름을 붙일 필요도 없는 간단한 함수나 일회용 함수에 사용할 수 있음.
# lambda para1, para2, ... : 매개변수를 이용한 표현식
# 위의 콜백함수의 예시에서, hello 함수를 따로 정의하는 대신 아래와 같이 쓸 수 있다.
call_5_times(lambda number : print("hello", number))
# 다른 코드의 중간에 써서 리턴 값을 받아야 할 때는 괄호 주의
# print((lambda x : x * x)(10))  # 이렇게 써야 람다식의 계산 결과가 출력됨


# map, filter 함수
# map : 반복 가능한 객체를 받아, 그 객체 각각에 사용자가 전달한 함수를 적용해주는 함수
# filter : map과 사용 방식은 비슷하나 map에서 함수를 전달하는 부분에 명제를 전달한다는 것이 차이.
#          전달된 명제가 참이 되는 값만 반환한다.

# 예제 4
numbers = list(range(1, 11))  # 이 리스트에 대해 람다식을 이용하여
# 홀수만 추출
odds = list(filter(lambda i : i % 2 == 1, numbers))
print(odds)
# 5 이상 9 미만 추출
ran = list(filter(lambda i : 5 <= i < 9, numbers))
print(ran)
# 제곱한 값이 50 미만 추출
sq = list(filter(lambda i : i ** 2 < 50, numbers))
print(sq)
