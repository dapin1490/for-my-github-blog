# 2번 : 리스트 함수와 반복문을 이용해 주석에 적힌 대로 리스트 만들어내기
s = [4, 1, 6, 7, 6]
s.append(s[len(s) - 1])  # s = [4, 1, 6, 7, 6, 6]
s.reverse()  # s = [6, 6, 7, 6, 1, 4]
s = s[0:3] + s[4:]  # s = [6, 6, 7, 1, 4]
s.insert(3, 7)  # s = [6, 6, 7, 7, 1, 4]
s.sort()  # s = [1, 4, 6, 6, 7, 7]
s_re_el = []
for n in s:  # 꼭 한 줄일 필요는 없으나 반드시 s와 for 이용
    if s_re_el.count(n) == 0:
        s_re_el.append(n)
# s_re_el = [1, 4, 6, 7]