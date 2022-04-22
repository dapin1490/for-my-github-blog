class Shapes:
    num_circle = 0
    num_triangle = 0
    num_square = 0

    def __init__(self, shp, num_shp):
        self.shape = shp
        self.num_shape = num_shp
        
        if self.shape == 1:
            Shapes.num_circle += num_shp
        elif self.shape == 2:
            Shapes.num_triangle += num_shp
        elif self.shape == 3:
            Shapes.num_square += num_shp
    
    def get_total_num_shape(self):
        return Shapes.num_circle + Shapes.num_triangle + Shapes.num_square

    def Show_shape(self):
        if self.shape == 1:
            print("circle")
        elif self.shape == 2:
            print("triangle")
        elif self.shape == 3:
            print("square")
    
    def Show_total(self):  # 여기에 self를 안 쓰면 객체명으로 함수를 호출했을 때 오류 발생
        print("total shapes :", self.get_total_num_shape())
        print("circle :", Shapes.num_circle)
        print("triangle :", Shapes.num_triangle)
        print("square :", Shapes.num_square)


s_list = [Shapes(1, 2), Shapes(2, 1), Shapes(3, 4)]
for s in s_list:
    s.Show_shape()
    # s.Show_total()  # 오류 발생 -> 함수 파라미터에 self 쓰면 해결됨

# Shapes.Show_total()  # self가 없는 클래스 함수에만 사용 가능
s_list[0].Show_total()  # 오류 발생 -> 함수 파라미터에 self 쓰면 해결됨
