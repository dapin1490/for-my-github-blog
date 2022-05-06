#include <iostream>
using namespace std;

/*
누적합을 재귀호출 방식으로 구현하되, 아래와 같이 중간과정이 출력되도록 프로그램을 작성하시오.
예시>
숫자=4
sum(4~1) = 4 * sum(3~1)
sum(3~1) = 3 * sum(2~1)
sum(2~1) = 2 * sum(1)
sum(1) = 1
sum(4~1) = 10
*/

int nsum(int start = 1); // 디폴트 매개변수는 함수를 두 번 선언했을 경우 두 선언 중 한 쪽에만 정의할 수 있다. 두 선언에서 모두 정의하면 오류난다.

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cout << "sum(4~1) = " << nsum(4);

	return 0;
}

int nsum(int start)
{
	if (start <= 1) {
		cout << "sum(1) = 1\n";
		return 1;
	}
	else {
		cout << "sum(" << start << "~1) = " << start << " + sum(" << start - 1 << "~1)\n";
		return start + nsum(start - 1);
	}
}
