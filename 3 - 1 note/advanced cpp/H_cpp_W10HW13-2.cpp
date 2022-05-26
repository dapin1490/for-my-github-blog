#include <iostream>
using namespace std;

/*
main()에서 2개의 정수를 입력받아, 출력한 후
void swap(int* p_a, int* p_b)를 적용한 후 a, b가 바뀐 값을 출력하세요
*/

void swap(int* p_a, int* p_b);

int main()
{
	int a, b;
	cin >> a >> b;

	printf("a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("a : %d, b : %d\n", a, b);
	
	return 0;
}

void swap(int* p_a, int* p_b)
{
	int temp = *p_a;
	*p_a = *p_b;
	*p_b = temp;
	return;
}
