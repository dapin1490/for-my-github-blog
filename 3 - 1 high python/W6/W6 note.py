# 절차 지향 프로그래밍
    # 일련의 동작을 순서에 맞추어 단계적으로 실행하도록 명령어를 나열
    # 데이터를 정의하는 방법보다는 명령어의 순서와 흐름에 중점
    # 수행할 작업을 직관적으로 예상할 수 있어 규모가 작을 때는 이해하기가 쉽지만
    # 클 경우 복잡도가 증가하여 확장하기 어려움
# 객체 지향 프로그래밍
    # 객체 단위로 프로그래밍하며, 객체는 상태 (Field)와 동작 (Method)을 기반으로 표현

# 객체 : 상태와 동작을 가진 자료 형태
# 클래스 : 객체를 만들기 위한 형틀
# 인스턴스 : 생성자를 사용하여 만들어진 객체. 특정 클래스로부터 나온 객체임을 나타내기 위한 말.
    # 예를 들어 붕어빵은 붕어빵틀 클래스에서 나온 인스턴스이지만, 호똑틀에서 나온 인스턴스는 아니다.


# id 연산자 : 동일한 객체인지를 판별하는 연산자
# id() 함수 : 객체를 입력값으로 받아 객체의 고유 값을 반환하는 함수
a = 111
b = 222
c = 222
d = "text"
e = d
print(a, "id =", id(a))
print(b, "id =", id(b))
print(c, "id =", id(c))
print(d, "id =", id(d))
print(e, "id =", id(e))


# 클래스 선언
# 생성자 : 클래스 이름과 같은 함수
    # 클래스 내부의 함수는 첫 번째 매개변수로 self를 입력함
    # -> self가 안 들어가면 객체를 통한 함수 호출이 불가하다
# 메소드 : 클래스가 가지고 있는 함수
# 필드 : 클래스에 속한 변수
'''
class Example:
    def __init__(self, para):
        self.factor1 = para
        self.factor2 = "초기값"

ex = Example(1)
'''

# EX 1
'''
다음 내용을 구현하는 Calculator 클래스를 만드시오.

# 필드
AddCount: Add 메서드가 수행된 횟수
MinCount: Min 메서드가 수행된 횟수
MulCount: Mul 메서드가 수행된 횟수
DivCount: Div 메서드가 수행된 횟수

# 메서드
Add(param1, param2): 덧셈
Min(param1, param2): 뺄셈
Mul(param1, param2): 곱셈
Div(param1, param2): 나누기
ShowCount(): 덧셈, 뺄셈, 곱셈, 나누기가 수행된 횟수 출력
'''
class Calculator:
    # 생성자
    def __init__(self):
        self.AddCount = 0  # Add가 수행된 횟수
        self.MinCount = 0
        self.MulCount = 0
        self.DivCount = 0
    
    def Add(self, para1, para2):
        self.AddCount += 1
        return para1 + para2
    
    def Min(self, par1, par2):
        self.MinCount += 1
        return par1 - par2
    
    def Mul(self, p1, p2):
        self.MulCount += 1
        return p1 * p2
    
    def Div(self, p1, p2):
        self.DivCount += 1
        return p1 / p2
    
    def ShowCount(self):
        print("덧셈 횟수 :", self.AddCount)
        print("뺄셈 횟수 :", self.MinCount)
        print("곱셈 횟수 :", self.MulCount)
        print("나눗셈 횟수 :", self.DivCount)

cal = Calculator()
print(cal.Add(3, 5))
print(cal.Min(3, 5))
print(cal.Mul(3, 5))
print(cal.Div(3, 5))
cal.ShowCount()


# isinstance() : 객체가 어떤 클래스로부터 만들어졌는지 확인. 상속도 확인 가능하다고 함
print(isinstance(cal, Calculator))


import copy
# 얕은 복사 : 주소 복사. 원본 데이터가 변경되면 같이 변경됨
# 깊은 복사 : 값 복사. 원본 데이터가 변경되어도 영향 받지 않음. 원본 데이터와 다른 주소를 갖는다.
a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
b = copy.copy(a)  # shallow copy
a[1].append(10)
print(a)
print(b)
b[1].append("abc")
print(a)
print(b)
c = [['a', 'b', 'c'], ['d', 'e', 'f']]
d = copy.deepcopy(c)  # deep copy
c[1].append('G')
print(c)
print(d)


# 특별한 이름의 메소드
    # __이름__ 형태
    # 특수한 상황에서 자동으로 호출됨
    # 예시, Ex 2 : student class ex.py 참고


# 클래스 변수
    # 클래스 내에 선언되는 변수. 클래스 선언문 바로 아래에 선언.
    # 접근 : 클래스명.변수명
    # 인스턴스 각각의 변수(self.변수명)는 객체마다 다르지만 클래스 변수는 모든 객체가 공유함
    # 예시, EX 3 : shape class ex.py 참고
