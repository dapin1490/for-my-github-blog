# 10번 : 클래스 구현
class Triangle:
    num_tri = 0
    num_set = 0

    def __init__(self, a, b, c):
        if (a <= 0 or b <= 0 or c <= 0) or ((a + b + c) - max(a, b, c) <= max(a, b, c)):
            print("잘못된 입력값입니다.")
        else:
            self.__a = a
            self.__b = b
            self.__c = c
            Triangle.num_tri += 1
            print("{} 번째 삼각형입니다.".format(Triangle.num_tri))

    def get_len(self):
        return self.__a, self.__b, self.__c
    
    def set_len(self, a, b, c):
        if (a <= 0 or b <= 0 or c <= 0) or ((a + b + c) - max(a, b, c) <= max(a, b, c)):
            print("잘못된 입력값입니다.")
        else:
            self.__a = a
            self.__b = b
            self.__c = c
            Triangle.num_set += 1
            print("{} 번째 변경입니다.".format(Triangle.num_set))  # 문제에 써있는 출력문구와 출력예시의 문구가 다른데, 문제에 쓰인 문구를 우선하여 작성했음.

tri1 = Triangle(1, 1, 1)
tri2 = Triangle(1, 0.5, 0.5)
tri3 = Triangle(1, 1, 1)
tri3.set_len(1, 0.5, 1)
tri3.set_len(1, 0.5, 1)
tri3.set_len(1, 0, 0)
print(tri3.get_len())