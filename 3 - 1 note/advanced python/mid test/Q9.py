class Student:
    def __init__(self, name, korean, math):
        self.name = name
        self.korean = korean
        self.math = math
    
    def stu_sum(self):
        return self.korean + self.math
    
    def __ge__(self, value):
        return self.stu_sum() >= value.stu_sum()
    
    def __lt__(self, value):
        return self.math < value.math
    
    def __ne__(self, value):
        return self.korean != value.math


stu_a = Student("이준세", 95, 90)
stu_b = Student("파이썬", 90, 95)

print(stu_a >= stu_b)
print(stu_a < stu_b)
print(stu_a != stu_b)
