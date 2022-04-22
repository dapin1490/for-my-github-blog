"""
# W8 중간고사 메모

- 오픈북인가? -> 예
- 실시간 회의 병행하나? -> 예
- 과제 풀이 하나? -> 답지 제공 예정
- 코딩 문제도 lms 시험란에 코드 복붙하나? -> 예
- 교수님 공지 : 풀 수 있는 문제 위주로 빨리 푸는 게 좋다. 복붙 금지 문제 있음.

- 시험 전 파일 입출력 실습 한 번 해보는 것을 권장
"""

# Garbage collector 가비지 컬렉터
# 사용하지 않는 데이터를 메모리에서 제거
# 변수에 저장하지 않을 경우 객체가 생성되자마자 제거됨
# 변수에 저장하면 프로그램이 종료될 때까지 제거하지 않음.
class Garbaga_Collector_EX:
    def __init__(self, name):
        self.name = name
        print("object \"{}\" initialized".format(self.name))
    
    def __del__(self):
        print("object \"{}\" deleted".format(self.name))

print("W7 #1 : Garbage collector 가비지 컬렉터")
Garbaga_Collector_EX("Garbaga_Collector_EX_1")
Garbaga_Collector_EX("Garbaga_Collector_EX_2")
gcex_1 = Garbaga_Collector_EX("GCEX_1")
gcex_2 = Garbaga_Collector_EX("GCEX_2")
print("using objects...")
print("delete objects")
del gcex_1  # 직접 삭제하지 않으면 모든 프로그램이 실행된 후 마지막에 삭제됨
del gcex_2
print("\n")


# 프라이빗 변수와 게터, 세터
# 프라이빗 변수 : __변수명 형태(언더바 2개)로 필드 변수 이름 선언
    # 클래스 외부의 접근을 방지하지만 굳이 접근할 수는 있음
        # 인스턴스명._클래스명__변수명
        # 클래스명과 변수명 사이에는 점 없이 이어서 써야 함
# 게터(get), 세터(set)
    # 프라이빗 변수 값 추출하거나 변경할 목적으로 간접적으로 속성에 접근하도록 하는 함수
    # 개발자가 의도하지 않은 방향의 값이 사용되는 것을 막을 수 있음
import math

class Circle:
    def __init__(self, radi):
        self.__radius = radi  # 프라이빗 변수로 선언됨
    
    def set_radius(self, value):
        if value >= 0:
            self.__radius = value
        else:
            raise TypeError("Value Error : radius cannot be under 0")
    
    def get_radius(self):
        return self.__radius
    
    def get_circumference(self):
        return 2 * math.pi * self.__radius
    
    def get_area(self):
        return math.pi * (self.__radius ** 2)

print("W7 #2 : 프라이빗 변수와 게터, 세터")
print("\n반지름의 길이가 50인 Circle 객체 생성")
c1 = Circle(50)
print("circumference :", round(c1.get_circumference(), 3))
print("area :", round(c1.get_area(), 3))
print("access private variable :", c1._Circle__radius)
print("\nCircle 객체의 반지름 변경 : 50 -> 100")
c1.set_radius(100)
print("circumference :", round(c1.get_circumference(), 3))
print("area :", round(c1.get_area(), 3))
print("access private variable :", c1._Circle__radius)
# print("\n부적절한 객체 값 변경 시도")
# c1.set_radius(-3)
print("\n")


# 상속
# 선언 방법 : class 자식클래스명(부모클래스명)
# 자식 클래스는 부모 클래스의 멤버 함수 사용 가능. 오버라이딩 가능.
    # 다만 자식 클래스가 오버라이딩한 함수를 부모 클래스의 것으로 호출하는 것은 불가능
# isinstance() 함수로 상속 관계도 확인할 수 있다.
    # 자식 클래스의 인스턴스와 부모 클래스를 인자로 전달하면 True 반환
    # 부모 클래스의 인스턴스와 자식 클래스 전달하면 False 반환
# 덤 : 파이썬은 메소드 오버로딩을 지원하지 않으며, 필요하다면 선택문을 이용해 분기해야 한다.
    # 참고 https://www.delftstack.com/ko/howto/python/python-function-overloading/

class Animal:
    def __init__(self, kind, hometown):
        self.kind = kind
        self.hometown = hometown
    def introduce(self):
        print("I like {}. My hometown is {}.".format(self.kind, self.hometown))

class Domesticani(Animal):
    def __init__(self, kind, hometown, year):
        super().__init__(kind, hometown)
        self.year = year
    def introduce(self):
        print("I like {}. My hometown is {}. Birth year is {}".format(self.kind, self.hometown, self.year))

print("W7 #3 : 상속")
obj1 = Animal("dog", "NY")
print("\nAnimal object initialized")
print("print >> I like {}. My hometown is {}.".format(obj1.kind, obj1.hometown))
print("class function >> ", end="")
obj1.introduce()

obj2 = Domesticani("cat", "UK", 2017)
print("\nDomesticani object initialized")
print("print >> I like {}. My hometown is {}. Birth year is {}".format(obj2.kind, obj2.hometown, obj2.year))
print("class function >> ", end="")
obj2.introduce()

print("\nisinstance(obj1, Domesticani) >> {}".format(isinstance(obj1, Domesticani)))
print("\n")


# 다중 상속 : 자식 클래스가 부모 클래스를 여러 개 가질 수 있음
# 자식 클래스의 인스턴스는 부모 클래스의 함수를 모두 사용할 수 있음
# 오버라이딩된 함수를 호출하면 먼저 상속받은 클래스 우선으로 실행됨

# 다중상속을 받은 클래스가 super()로 생성자를 실행하면
# 뒤에서부터 거슬러 올라가기 때문에 먼저 상속받은 클래스가 마지막에 생성됨.
# 그리고 상위 클래스 중복 생성을 방지할 수 있음.

class Human:
    def __init__(self, name, year):
        self.name = name
        self.byear = year
        print("Human object initialized")
    def get_age(self):
        return 2022 - self.byear
    def human_do(self):
        print("human breathe")
    def do(self):
        print("breathe")

class Student(Human):
    def __init__(self, name, year):
        super().__init__(name, year)
        print("Student object initialized")
    def set_school(self, school):
        self.school = school
    def stu_do(self):
        print("student study")
    def do(self):
        print("study")

class Worker(Human):
    def __init__(self, name, year):
        super().__init__(name, year)
        print("Worker object initialized")
    def set_workplace(self, place):
        self.workplace = place
    def worker_do(self):
        print("worker work")
    def do(self):
        print("work")

class StudyWorker(Student, Worker):
    def __init__(self, name, year):
        super().__init__(name, year)
        print("StudyWorker object initialized")
    def sw_do(self):
        print("StudentWorker study and work")

print("W7 #4 : 다중 상속")
sw = StudyWorker("A", 2001)
print(sw.get_age())
sw.human_do()
sw.stu_do()
sw.worker_do()
sw.sw_do()
sw.do()

