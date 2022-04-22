#include <iostream>
#include <algorithm> // swap
using namespace std;

int main()
{
	/*
    아래 성적을 2차원 배열에 초기화 하고,
    총점이 높은 순서대로 화면에 성적을 출력하는 프로그램을 작성하시오.
    
    1반 성적: 70 90 100
    2반 성적: 90 95 92
    3반 성적: 80 85 87

    <<출력예시>>
    95 92 90
    100 90 70
    87 85 80
	*/

	int ar[][3] = { {70, 90, 100}, {90, 95, 92}, {80, 85, 87} };
	int sum_key, sum_value, max_sum, max_idx;

	for (int i = 0; i < 3; i++) { // 반별 정렬
		for (int j = 0; j < 3 - 1; j++) {
			int idx = j;

			for (int k = j + 1; k < 3; k++) {
				if (ar[i][k] > ar[i][idx]) {
					idx = k;
				}
			}

			int temp = ar[i][j];
			ar[i][j] = ar[i][idx];
			ar[i][idx] = temp;
		}
	}

	for (int i = 0; i < 3 - 1; i++) { // 반 총합 정렬
		sum_key = 0;

		for (int a = 0; a < 3; a++)
			sum_key += ar[i][a];

		max_sum = sum_key;

		for (int j = i + 1; j < 3; j++) {
			sum_value = 0;
			for (int k = 0; k < 3; k++)
				sum_value += ar[j][k];

			if (sum_value > max_sum) {
				max_sum = sum_value;
				max_idx = j;
			}
		}

		swap(ar[i], ar[max_idx]);
	}

	for (int i = 0; i < 3; i++) { // 결과 출력
		for (int j = 0; j < 3; j++) {
			cout << ar[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}