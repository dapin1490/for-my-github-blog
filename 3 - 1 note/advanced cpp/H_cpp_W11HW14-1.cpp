#include <iostream>
using namespace std;

/*
int aa[6] = {88, 90, 70, 95, 100, 66}; 을 main()에서 선언하고,
void sort(int* p_aa, int n, int order) 를 만들어
order가 1이면 오름차순 0이면 내림 차순으로 정렬하고
최종 결과는 main()에서 출력하도록 프로그램을 작성하세요.
*/

void sort(int* p_aa, int n, int order);

int main()
{
	int aa[6] = { 88, 90, 70, 95, 100, 66 };

	sort(aa, 6, 1);
	cout << "오름차순 정렬\n";
	for (int i = 0; i < 6; i++)
		cout << aa[i] << " ";

	sort(aa, 6, 0);
	cout << "\n\n내림차순 정렬\n";
	for (int i = 0; i < 6; i++)
		cout << aa[i] << " ";

	return 0;
}

void sort(int* p_aa, int n, int order)
{
	for (int i = 0; i < n - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < n; j++) {
			switch (order) {
			case 0:
				idx = *(p_aa + j) > *(p_aa + idx) ? j : idx;
				break;
			case 1:
				idx = *(p_aa + j) < *(p_aa + idx) ? j : idx;
				break;
			}
		}

		int t = *(p_aa + i);
		*(p_aa + i) = *(p_aa + idx);
		*(p_aa + idx) = t;
	}

	return;
}
