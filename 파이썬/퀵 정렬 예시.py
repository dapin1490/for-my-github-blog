# 퀵 정렬 함수
def qsort(lis, i, j):
    p = (i + j) // 2  # 기준 값 피벗
    next_i = i  # 다음 호출에 쓸 i
    next_j = j  # 다음 호출에 쓸 j

    if i >= j:  # 배열 크기가 1이라면 정렬 끝, 리턴
        return

    while i < j:  # i와 j가 만나면 중단
        while lis[i] < lis[p]:  # i 쪽에서 기준 값보다 큰 값 찾기
            i += 1
        while lis[j] > lis[p]:  # j 쪽에서 기준 값보다 작은 값 찾기
            j -= 1

        if i <= j:  # i가 왼쪽에 있고 j가 오른쪽에 있을 때에만 실행, 겹쳐도 된다.
            lis[i], lis[j] = lis[j], lis[i]  # i와 j 자리에 있는 두 요소를 서로 바꿈
            # 사용한 i와 j를 바꿔주지 않으면 무한루프가 생김
            i += 1
            j -= 1

    # 나누어진 배열 양쪽에 대한 재귀 호출
    qsort(lis, next_i, j)
    qsort(lis, i, next_j)


ar = [5, 9, 6, 9, 2, 9, 1, 3, 7, 10, 4, 8]  # 정렬할 배열
s = len(ar)  # 배열 크기

qsort(ar, 0, s - 1)  # 정렬 함수 호출

print(ar)  # 정렬한 배열 출력
