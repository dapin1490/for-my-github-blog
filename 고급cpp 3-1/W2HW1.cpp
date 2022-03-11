#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// A
	int sumA = n * (n + 1) / 2;
	
	// B
	int sumB = 0;
	for (int i = 1; i <= n; i++) {
		sumB += i;
	}

	// C
	int sumC = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sumC += 1;
		}
	}

	cout << "A : " << sumA << "\n";
	cout << "B : " << sumB << "\n";
	cout << "C : " << sumC;

	return 0;
}