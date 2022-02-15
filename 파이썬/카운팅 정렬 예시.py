# 파이썬 카운팅 정렬
# 리스트 선언 및 초기화
ar = [3, 4, 2, 6, 8, 2, 9, 0, 4, 8, 7, 5, 2, 4, 0]  # 정렬할 배열
cn = [0] * 10  # 원소의 종류별 개수를 저장, 누적할 배열
cnt = 0  # 정렬을 위한 모든 연산의 횟수를 세기 위한 변수

# 정렬 전 리스트 출력
print("정렬 전 리스트\n{}\n".format(ar))

# 카운팅 정렬 실행
# 원소 개수 세기
for i in range(len(ar)):
    cn[ar[i]] += 1
    cnt += 1

# 원소 개수 누적하기
for i in range(1, len(cn)):
    cn[i] += cn[i - 1]  # 앞에서부터 이전 원소를 합해가면 원소 개수가 누적 개수가 된다
    cnt += 1

sorted_ar = [0] * len(ar)  # 원소를 정렬해 넣을 새 배열
for i in range(len(ar)):
    cn[ar[i]] -= 1  # 누적된 원소 개수를 먼저 1 줄이고
    idx = cn[ar[i]]  # 그 값을 인덱스로 하여
    sorted_ar[idx] = ar[i]  # 새 배열에 저장
    cnt += 1

# 정렬 후 리스트 출력
print("정렬 후 리스트\n{}\n".format(sorted_ar))

# 총 비교 횟수 출력
print("총 비교 횟수 : {}".format(cnt))
