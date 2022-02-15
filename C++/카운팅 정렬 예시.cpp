#include <iostream>
#include <array>
using namespace std;

int main()
{
	int ar[] = { 3, 4, 2, 6, 8, 2, 9, 0, 4, 8, 7, 5, 2, 4, 0 }; // 정렬할 배열
	int cn[10] = { 0 }; // 원소의 종류별 개수를 저장, 누적할 배열
	int cnt = 0; // 정렬을 위한 모든 연산의 횟수를 세기 위한 변수

	// 보여주기용 출력문
	cout << "The array before sort\n{ ";
	for (int i = 0; i < 14; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[14] << " }\n";

	// 카운팅 정렬
	// 원소 개수 세기
	for (int i = 0; i < 15; i++) {
		cn[ar[i]]++;
		cnt++;
	}

	// 원소 개수 누적하기
	for (int i = 1; i < 10; i++) {
		cn[i] += cn[i - 1]; // 앞에서부터 이전 원소를 합해가면 원소 개수가 누적 개수가 된다
		cnt++;
	}

	int sortedAr[15] = { 0 }; // 원소를 정렬해 넣을 새 배열
	for (int i = 0; i < 15; i++) {
		cn[ar[i]]--; // 누적된 원소 개수를 먼저 1 줄이고
		int idx = cn[ar[i]]; // 그 값을 인덱스로 하여
		sortedAr[idx] = ar[i]; // 새 배열에 저장
		cnt++;
	}

	// 보여주기용 출력문
	cout << "\nThe array after sort\n{ ";
	for (int i = 0; i < 15 - 1; i++) {
		cout << sortedAr[i] << ", ";
	}
	cout << sortedAr[15 - 1] << " }";

	cout << "\n\ntotal acting count : " << cnt;

	return 0;
}
