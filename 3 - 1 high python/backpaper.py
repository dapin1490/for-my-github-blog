lis1 = [1, 2, "tea", 3]
a1, b1, _, c1 = lis1  # _에 "tea"가 저장됨
print(_)  # tea 출력

lis2 = [1, 2, 3, 4, 5, "apple", "tea"]
a2, b2, *_, c2 = lis2  # *이 붙었기 때문에 다른 변수에 할당하고 남은 값이 전부 _에 리스트로 저장됨
print(_)
print(c2)
