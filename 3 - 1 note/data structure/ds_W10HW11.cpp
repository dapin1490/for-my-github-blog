#include <iostream>
using namespace std;

/*
아래 정의 된 피보나치 수열을 recursion으로 구현하고, F8을 화면에 출력하세요.

F0 = 1
F1 = 1
Fn = 2*Fn-1 + Fn-2
*/

int f(int n);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cout << f(8);

	return 0;
}

int f(int n)
{
	if (n <= 1)
		return 1;
	else
		return 2 * f(n - 1) + f(n - 2);
}
