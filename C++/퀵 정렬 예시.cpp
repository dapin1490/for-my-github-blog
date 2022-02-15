#include <iostream>
#include <algorithm> // swap 함수를 사용하기 위함
using namespace std;

// 퀵 정렬 함수
void qsort(int list[], int i, int j);

int main()
{
	int s = 12; // 배열 크기
	int ar[] = { 5, 9, 6, 9, 2, 9, 1, 3, 7, 10, 4, 8 }; // 정렬할 배열
	
	qsort(ar, 0, s - 1); // 정렬 함수 호출

	for (int i = 0; i < s; i++) // 정렬한 배열 출력
		cout << ar[i] << " ";
	
	return 0;
}

// 퀵 정렬 함수
void qsort(int list[], int i, int j) // 배열은 기본적으로 참조 전달이기 때문에 &를 붙이면 안 된다
{
	int p = (i + j) / 2; // 기준 값 피벗
	int ni = i; // 다음 호출에 쓸 i
	int nj = j; // 다음 호출에 쓸 j

	if (i >= j) // 배열 크기가 1이라면 정렬 끝, 리턴
		return;

	while (i < j) { // i와 j가 만나면 중단
		while (list[i] < list[p]) // i 쪽에서 기준 값보다 큰 값 찾기
			i++;

		while (list[j] > list[p]) // j 쪽에서 기준 값보다 작은 값 찾기
			j--;

		if (i <= j) { // i가 왼쪽에 있고 j가 오른쪽에 있을 때에만 실행, 겹쳐도 된다.
			swap(list[i], list[j]); // i와 j 자리에 있는 두 요소를 서로 바꿈
			// 사용한 i와 j를 바꿔주지 않으면 무한루프가 생김
			i++;
			j--;
		}
	}

	// 나누어진 배열 양쪽에 대한 재귀 호출
	qsort(list, ni, j);
	qsort(list, i, nj);
}
