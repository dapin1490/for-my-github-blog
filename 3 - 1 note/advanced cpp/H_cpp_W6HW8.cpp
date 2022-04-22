#include <iostream>
using namespace std;

int main()
{
	/*
	과제6과 동일한 예시를 다른 방식의 선택정렬로 정렬하시오 (동적할당 안 해도 됨).
	다른 방식이란, 교안의 선택 정렬은 배열의 앞부분부터 업데이트를 하고 있습니다.
	뒷부분부터 업데이트 하여 동일한 결과를 얻도록 프로그램을 작성하시오.
	*/

	int ar[6] = { 88, 90, 70, 95, 100, 66 };
	int n;

	n = 6;

	// 선택 정렬
	for (int i = n - 1; i > 0; i--) {
		int idx = i;

		for (int j = i - 1; j >= 0; j--) {
			if (ar[j] < ar[idx]) {
				idx = j;
			}
		}

		int temp = ar[i];
		ar[i] = ar[idx];
		ar[idx] = temp;
	}

	cout << "내림차순 정렬\n";
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}