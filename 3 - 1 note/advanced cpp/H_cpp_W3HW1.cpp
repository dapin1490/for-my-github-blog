#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	/*
	1부터 입력받은 수(n)까지의 숫자중 2의 배수이면서 5의 배수인 수의
	누적합과 갯수를 화면에 출력하는 프로그램을 작성하시오.
	*/

	int n, sum = 0, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		// (1) i % 2 == 0 && i % 5 == 0
		// (2) i % 10 == 0
		if (i % 10 == 0) {
			sum += i;
			cnt++;
		}
	}

	cout << "누적합 : " << sum << "\n개수 : " << cnt;

	return 0;
}