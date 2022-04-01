# lambda와 reduce
from functools import reduce
# reduce()는 리스트의 아이템들을 누적해서 하나의 값으로 리턴해주는 함수로 lambda와 함께 사용할 수 있음
# reduce()의 첫 번째 인자로 lambda를 전달하고, 두 번째 인자에 리스트를 전달함

# EX 1
# (1) factorial을 구하는 익명함수를 구현하시오. (factorial(n) = 1 x 2 x … n)
n = int(input("EX 1 - 1.\ninput n : "))
print(reduce(lambda x, y : x * y, range(1, n + 1)))

# (2) 특정 값까지의 모든 홀수만 곱하는 (혹은 짝수만 곱하는) 익명함수를 구현하시오.
print("\nEX 1 - 2.\n\n(1)")
print(reduce(lambda x, y : x * y, filter(lambda a : a % 2 == 1, range(1, n + 1))))
# 문제 수정 : n번째 홀수까지 곱하라
print("\n(2)")
print(reduce(lambda x, y : x * (2 * x + 1), range(1, n + 1)))

# (3) list_number = [18,65,54,39,81,39,45,55,90] 중 9로 나누어지는 수를 전부 더하시오
print("\nEX 1 - 3")
list_number = [18, 65, 54, 39, 81, 39, 45, 55, 90]
print(reduce(lambda x, y : x + y, filter(lambda a : a % 9 == 0, list_number)))

# 람다 활용 (4)
# sort
lis1 = [("egg", 4), ("apple", 6), ("banana", 7), ("peach", 7)]
lis1.sort(key = lambda x : x[0])
print(lis1)
lis1.sort(key = lambda x : x[1])
print(lis1)
# conditional
start_with_L = lambda x : True if x.startswith('L') else False
print(start_with_L('Lee'))
print(start_with_L('Kim'))
# other
def dof(f, val):
    return f(val)

func = lambda x : x ** 2
print(func(5))
print(dof(func, 5))


"""
라이브러리, 모듈, 패키지
라이브러리 > 패키지 > 모듈 > 클래스 > 함수 > 변수

모듈 : 어떤 기능을 위해 만든 코드의 집합. 쉽게 말해 py 파일
패키지 : 모듈의 모임
라이브러리 : 모듈과 패키지를 포함한 가장 넓은 개념

표준 라이브러리 참고 링크
https://docs.python.org/3/library/
"""
# 내장 함수 예시
print(eval("3 + 5"))
print(sorted([5, 9, 3, 4, 7, 2]))

# itertools
from itertools import permutations  # 순열
from itertools import combinations  # 조합
data = ['A', 'B', 'C']
print(list(permutations(data, 3)))  # 순열 순서쌍 출력
print(list(combinations(data, 2)))  # 조합 순서쌍 출력

# 명령어
# import : load module
# import - as : load module with custom name
# from - import : load module partially. can call val, func, class, or *
# from - import - as : load module partially with custom name

# math module
import math
# floor : 내림
# ceil : 올림
# fabs : 절댓값
print(math.fabs(-273))
# 참고 : https://docs.python.org/3/library/math.html#module-math

# EX 2
# gcd : 최대공약수
# (1) (12, 18, 40)의 최소 공배수와 (36, 20, 15)의 최소 공배수를 구한 후 이의 최대 공약수를 계산
print("\nEX 2 - 1.")
print(math.gcd(math.lcm(12, 18, 40), math.lcm(36, 20, 15)))
# (2) 13.7의 올림값과 4의 음이 아닌 제곱근이 같은지 bool값을 계산
print("\nEX 2 - 2.")
issame = math.ceil(13.7) == math.isqrt(4)
print(issame)
# (3) math 모듈 함수를 사용하여 13.7의 소수 부분을 구하시오
print("\nEX 2 - 3.")
print(math.modf(13.7)[0])

# 기타 모듈
# sys(시스템 관련), os(운영체제 관련), datetime(날짜 및 시각), time(시간 관련 기능) 등

# EX 3
# 파이썬을 이용하여 로또 숫자를 정해주는 프로그램을 구하려 한다.
# 1~45까지 중 6개의 숫자를 임의로 고른다. 6개의 숫자는 중복이 되면 안 된다.
# random 모듈의 randint를 활용할 것
import random

lotto = []
while len(lotto) < 6:
    num = random.randint(1, 45)
    print("pick lotto :", num)
    if num not in lotto:
        lotto.append(num)

print(lotto)

# 모듈 만들기
# 동일 폴더 안에 모듈테스트용 파이썬 파일과 import할 메인 파이썬 파일 작성

# EX 4
# 두 개의 파일을 만든다.
# 한 파일 (md_test_fact.py)은 factorial 함수를 구현한다.
# 다른 파일 (main.py)에서 md_test_fact.py 파일을 import하여 factorial 함수가 제대로 동작하는지 확인한다.
import md_test_fact as mtf

print(mtf.factorial(5))
