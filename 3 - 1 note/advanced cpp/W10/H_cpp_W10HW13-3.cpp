#include <iostream>
using namespace std;

/*
(1) 코드에 (2)를 적용하여 코드를 완성하세요.
*/

void swap(int* p_a, int* p_b);
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

void swap(int* p_a, int* p_b)
{
	int temp = *p_a;
	*p_a = *p_b;
	*p_b = temp;
	return;
}

void sort_asc(int* p_aa, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < n; j++) {
			if (*(p_aa + j) < *(p_aa + idx))
				idx = j;
		}

		swap((p_aa + i), (p_aa + idx));
	}

	return;
}
