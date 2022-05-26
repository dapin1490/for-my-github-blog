#include <iostream>
using namespace std;

/*
recursion 방식의 합병 정렬 코드를 활용하여, iteration 방식으로 구현하시오.
(Hint : int list[] = { 21, 10, 12, 20, 25, 13, 15, 22 };을 시작하면,
처음에 2개씩 묶어서 정렬하면 (10, 21), (12, 20), (13, 25), (15, 22) 가 됩니다.
그 다음에는 4개씩 묶어서…)
*/

int main()
{
	int list[] = { 21, 10, 12, 20, 25, 13, 15, 22 };
	int n = sizeof(list) / sizeof(int);
	int m = 1;
	int left, right, mid;
	int* ms = new int[n] {0};

	while (m <= n) {
		m *= 2;

		for (left = 0; left <= n - m; left += m) {
			right = left + m - 1;
			mid = (left + right) / 2;

			int i = left;
			int j = (left + right) / 2 + 1;
			int k = left;

			while (i <= mid && j <= right) {
				if (list[i] <= list[j])
					ms[k++] = list[i++];
				else
					ms[k++] = list[j++];
			}

			if (i > mid) { // 남아 있는 값들을 일괄 복사
				for (int l = j; l <= right; l++)
					ms[k++] = list[l];
			}
			else { // 남아 있는 값들을 일괄 복사
				for (int l = i; l <= mid; l++)
					ms[k++] = list[l];
			}

			// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
			for (int l = left; l <= right; l++) {
				list[l] = ms[l];
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << list[i] << " ";

	delete[] ms;

	return 0;
}