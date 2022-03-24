#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*
    정수 n을 입력받아 n개의 정수형 동적 배열을 생성하고 n개의 정수를 입력받아
    최대값과 최소값을 출력하는 프로그램을 작성하시오.

    <화면예시>
    n=5
    15
    90
    8
    36
    25 
    최대값: 90 최소값: 8
    */

	int* p;
	int cnt;
	int maxi, mini;

	cout << "n=";
	cin >> cnt;

	p = (int*)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "번째 숫자 : ";
		cin >> *(p + i); // 1과 i를 구분하자
	}

	maxi = *p;
	mini = *p;
	for (int i = 0; i < cnt; i++) {
		if (*(p + i) > maxi)
			maxi = *(p + i);
		if (*(p + i) < mini)
			mini = *(p + i);
	}

	cout << "최댓값 : " << maxi << " 최솟값 : " << mini;

	free(p); // 이게 제일 중요

	return 0;
}