#include <iostream>
using namespace std;

/*
int aa[5] = {100,89,90,99,102}를 main()함수에서 선언하고,
최대값과 최소값을 구해주는 void 타입의 함수
void getMaxMin (int* p_aa, int* p_max, int* p_min)로 구현하여,
결과는 main()함수에서 출력되도록 한다.
*/

void getMaxMin(int* p_aa, int* p_max, int* p_min);

int main()
{
	int aa[5] = { 100, 89, 90, 99, 102 };
	int maxi, mini;

	getMaxMin(aa, &maxi, &mini);

	printf("max : %d, min : %d", maxi, mini);

	return 0;
}

void getMaxMin(int* p_aa, int* p_max, int* p_min)
{
	*p_max = p_aa[0];
	*p_min = p_aa[0];

	for (int i = 1; i < 5; i++) {
		if (p_aa[i] > *p_max)
			*p_max = p_aa[i];
		if (p_aa[i] < *p_min)
			*p_min = p_aa[i];
	}

	return;
}