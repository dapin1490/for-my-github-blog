#include <iostream>
using namespace std;

/*
int aa[6] = 88,90,70,95,100,66; 을 main()에서 선언하고,
void sort_asc(int* p_aa, int n) 를 만들어 오름차순으로 소팅을 한 후,
최종 결과는 main()에서 출력하도록 프로그램을 작성하세요.
*/

void sort_asc(int* p_aa, int n);

int main()
{
	int aa[6] = { 88, 90, 70, 95, 100, 66 };
	int n = 6;

	sort_asc(aa, n);

	for (int i = 0; i < n; i++)
		cout << aa[i] << " ";

	return 0;
}

void sort_asc(int* p_aa, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < n; j++) {
			if (*(p_aa + j) < *(p_aa + idx))
				idx = j;
		}

		int temp = *(p_aa + i);
		*(p_aa + i) = *(p_aa + idx);
		*(p_aa + idx) = temp;
	}

	return;
}
