/* 유클리드 호제법 : 최대공약수를 구할 수 있다
최소공배수 : 두 수의 곱 ÷ 최대공약수 */

#include <iostream>
using namespace std;

int euclidean(int big, int small);

int main() { 
	
	int a, b;
	cout << "두 수 입력 : ";
	cin >> a >> b;
	cout << "\n" << a << "와 " << b << "의 최대공약수는 " << euclidean(a, b) << "이다." << endl;

	
	return 0;
}

int euclidean(int big, int small)
{
	if (big < small) { // 대소관계 정리
		int temp = big;
		big = small;
		small = temp;
	}

	int last = 1; // 매 연산마다 나머지를 저장함

	while (true)
	{
		if (big % small == 0)
			break;
		last = big % small;
		big = small;
		small = last;
	}

	return small;
}
