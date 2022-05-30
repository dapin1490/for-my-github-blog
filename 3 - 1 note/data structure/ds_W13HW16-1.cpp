#include <iostream>
using namespace std;

/*
int aa[5] = {100, 89, 90, 99, 102}를 main()함수에서 선언하고,
숫자를 서로 바꿔주는(a->c, c->b, b->a) void 타입의 함수
void getMix(int* p_a, int* p_b, int* p_c)로 구현하여,
결과는 main()함수에서 출력되도록 한다.
*/

void getMix(int* p_a, int* p_b, int* p_c);

int main()
{
	int aa[5] = { 100, 89, 90, 99, 102 };

	for (int i = 0; i < 5; i++)
		cout << aa[i] << " ";
	cout << "\n";

	getMix(&aa[0], &aa[1], &aa[2]);

	for (int i = 0; i < 5; i++)
		cout << aa[i] << " ";

	return 0;
}

void getMix(int* p_a, int* p_b, int* p_c)
{
	int a = *p_a;
	*p_a = *p_c;
	*p_c = *p_b;
	*p_b = a;
	return;
}
