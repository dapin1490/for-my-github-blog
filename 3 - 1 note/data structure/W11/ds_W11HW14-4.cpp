#include <iostream>
using namespace std;

/*
F0 = 1, F1 = 1, F2 = 1, Fn = 3 * Fn-1 + 2 * Fn-2 + Fn-3 을
reucursion 방식으로 fibo_recursion()을 구현하고
iteration 방식으로 fibo_iteration()을 구현해서,
각 방식에 대해서 F100를 화면에 출력하세요.
*/

long long fibo_recursion(long long n);
long long fibo_iteration(long long n);

int main()
{
	// 오버플로우 발생하여 정답 출력 불가
	// printf("reucursion : %lld", fibo_recursion(100)); // 재귀 호출이 너무 많아 실행하지 않고 주석으로 남김
	printf("iteration : %lld", fibo_iteration(100));

	return 0;
}

long long fibo_recursion(long long n)
{
	if (n <= 2)
		return 1;
	else
		return 3 * fibo_recursion(n - 1) + 2 * fibo_recursion(n - 2) + fibo_recursion(n - 3);
}

long long fibo_iteration(long long n)
{
	long long f0 = 1, f1 = 1, f2 = 1;
	long long ans;

	if (n <= 2)
		return 1;
	
	ans = 0;
	for (int i = 3; i <= n; i++) {
		ans = 3 * f2 + 2 * f1 + f0;
		f0 = f1;
		f1 = f2;
		f2 = ans;
	}

	return ans;
}
