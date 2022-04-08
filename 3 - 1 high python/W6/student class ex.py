# 예제 소스 출처 : https://www.hanbit.co.kr/store/books/look.php?p_code=B2587075793

# EX 1
# 클래스를 선언합니다.
class Student:
    # 생성자
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science

    # 총점 계산
    def get_sum(self):
        return self.korean + self.math + self.english + self.science

    # 평균 계산
    def get_average(self):
        return self.get_sum() / 4

    # 총점과 평균 출력
    def to_string(self):
        return "{}\t{}\t{}".format(self.name, self.get_sum(), self.get_average())

    
    # EX 2
    # 특별한 이름의 메소드
    def __str__(self, student): # stu(객체 이름)
        return "{}\t{}\t{}".format(self.name, self.stu_sum(student),self.stu_avg(student))

    def stu_sum(self):
        return self.korean + self.math + self.english + self.science
    
    def stu_avg(self):
        return self.stu_sum()/4
    
    def stu_print(self): # 객체 이름.stu_print()
        return "{}\t{}\t{}".format(self.name, self.stu_sum(),self.stu_avg())
    
    def __eq__(self, value): # 총점이 같은지 비교
        return self.stu_sum() == value.stu_sum()
    
    def __ne__(self, value):
        return self.name != value.name
    
    def __gt__(self, value):  # 국어 점수 비교
        return self.korean > value.korean
    
    def __ge__(self, value):  # 수학 점수 비교
        return self.math >= value.math
    
    def __lt__(self, value):  # 평균 비교
        return self.stu_avg() < value.stu_avg()
    
    def __le__(self, value):  # 총점 비교
        return self.stu_sum() <= value.stu_sum()


# EX 1
# 학생 리스트를 선언합니다.
students = [
    Student("윤인성", 87, 98, 88, 95),
    Student("연하진", 92, 98, 96, 98),
    Student("구지연", 76, 96, 94, 90),
    Student("나선주", 98, 92, 96, 92),
    Student("윤아린", 95, 98, 98, 98),
    Student("윤명월", 64, 88, 92, 92)
]

# 학생을 한 명씩 반복합니다.
print("이름", "총점", "평균", sep="\t")
for student in students:
    # 출력합니다.
    print(student.to_string())


# EX 2
# 특별한 이름의 메소드
student_a = Student("윤인성", 96, 98, 92, 98)
student_b = Student("연하진", 92, 98, 96, 98)

print(student_a == student_b)  # 객체를 비교할 때 == 연산자를 사용한다면 __eq__를 보고
print(student_a != student_b)  # !=연산자를 사용한다면 __ne__를 보고
print(student_a > student_b)
print(student_a >= student_b)
print(student_a < student_b)
print(student_a <= student_b)
