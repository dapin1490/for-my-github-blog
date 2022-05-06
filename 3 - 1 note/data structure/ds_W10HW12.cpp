#include <iostream>
using namespace std;

/*
[과제 11]
아래 정의 된 피보나치 수열을 recursion으로 구현하고, F8을 화면에 출력하세요.

F0 = 1
F1 = 1
Fn = 2*Fn-1 + Fn-2

[과제 12]
과제11을 iteration 형태로 구현하시오.
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
	int f0, f1, ans;

	f0 = 1, f1 = 1, ans = 0;
	
	if (n <= 1)
		return 1;
	else {
		for (int i = 2; i <= n; i++) {
			ans = 2 * f1 + f0;
			f0 = f1;
			f1 = ans;
		}
		return ans;
	}
}
