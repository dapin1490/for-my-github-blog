# 입력문과 출력문
# print() : 결과 값을 콘솔 창에 출력하는 표준 출력 함수
# sep : 출력할 때, 출력 값들 사이에 넣어줄 구분자. 기본값: 띄어쓰기
# end : 마지막 문자열을 출력하고 그 다음에 출력할 문자. 기본값: 줄바꿈
print("#", "입력문과", "출력문", sep="_", end="\n\n")  # "#_입력문과_출력문" 출력 후 두 줄 내림

# format() 활용
# 변수가 들어갈 곳에 중괄호를 넣고 마지막에 .format(변수)를 쓴다.
# 중괄호 안에 숫자가 없다면 순서대로,
# 숫자가 있다면 format 함수로 전해지는 객체들의 위치를 가리키는데 사용된다.
print("year : {}".format(2022), "month : {}".format(4), "day : {}".format(19), sep="\n", end="\n\n")

# format() 숫자 출력
import math
form_number = math.pi
print("그냥 출력\n{}".format(form_number))
print("소수점 자릿수 맞춤, 빈 자리 공백(가운데 정렬은 아닌 것 같은데 뒤에 더 붙는 문자열이 없다면 한 칸 비는 것 같음), 자릿수가 우선\n{:7.2f}".format(form_number))
print("왼쪽 정렬, 0 패딩\n{:0<8.2f}".format(form_number))
print("오른쪽 정렬, 0 패딩\n{:0>8.2f}".format(form_number))
print("오른쪽 정렬, * 패딩\n{:*>8.2f}".format(form_number))
print("\n")

# input() 입력문
# 기본적으로 문자열로 저장됨
# 프롬프트 문구 삽입 가능
# a = input("아무거나 입력 : ")

# split()과 map()
# split() : ()안의 값을 기준으로 분리하여 저장, 기본값: space
# map() : split의 결과를 int나 float으로 변환
# a, b, c = map(int, input("아무 숫자 세 개 입력 : ").split())


# 파일 입출력
# 파일을 닫아야 하는 이유 : 운영체제가 할당한 자원을 반환하고, 버퍼링된 데이터를 출력한다.
    # 프로그램을 종료해도 이름 변경, 이동 등에 문제가 발생하기도 한다.
f = open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", 'w', encoding='utf-8')  # 파일을 열어 객체 생성 후 변수에 저장
f.write("파일 입출력 예제\n")
f.close()  # 파일 닫기

# open() 파라미터
# file : 파일 경로
# mode : 파일 사용 모드
    # r: 파일을 읽기 위한 옵션
    # w: 쓰기모드, 파일에 내용을 쓸 때 사용하는 옵션.
        # 이미 파일이 존재하면 내용을 삭제 후 내용을 쓰게 되며,
        # 존재하지 않는다면 새롭게 파일을 생성하고 내용을 작성
    # a: 쓰기모드이며, 파일에 내용을 추가로 쓸 때 사용하는 옵션. (이어쓰기)
    # x: 파일이 없으면 파일을 생성 후 쓰기모드로 열리며, 파일이 있다면 에러를 발생시킨다.
# encoding
    # 파이썬은 기본적으로 텍스트 파일을 ANSI로 작성되었다고 가정하고 cp949라는 코덱으로 파일을 연다.
    # UTF8 방식으로 저장된 텍스트의 경우 open()함수에서 encoding 인자를 제대로 넣지 않으면
    # 아래와 같은 에러가 발생할 수 있음.
    # UnicodeDecodeError: 'cp949' codec can't decode byte 0xed in position 0: illegal multibyte sequence
with open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", 'a', encoding='utf-8') as f:
    f.write("이준세" + '\n')
    f.write("김준영")
    f.write("\n")
    f.write("유재현" + '\n')

with open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", 'r', encoding='utf-8') as f:
    data = f.read()

print(data)
print(data.split("\n"))  # 줄바꿈 기준으로 데이터를 분할해 리스트로 만듦
print(data.split("\n")[0], data.split("\n")[-1])

f = open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", 'a', encoding='utf-8')
f.write("\n대학교")
f.close()

# mode='x' : 파일이 이미 있기 때문에 오류 발생 -> 중요한 파일의 손상을 방지할 수 있음
# f = open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", 'x', encoding='utf-8')
# f.close()

with open("../study-note/3 - 1 high python/W3/file_in_out_ex.txt", encoding='utf-8') as f:
    data = f.read().splitlines()  # 줄 단위로 읽은 결과를 리스트 방식으로 저장할 때 사용

print(data)
