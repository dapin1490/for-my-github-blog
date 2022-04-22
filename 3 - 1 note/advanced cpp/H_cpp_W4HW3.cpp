#include <iostream>
using namespace std;

void get_max_min(int* p_arr, int* p_max, int* p_min);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*
    과제2를  void get_max_min(int* p_arr, int* p_max, int* p_min) 함수를 구현하여 푸세요.
    max와 min은 main 함수에서 출력되어야 함.
    */

    /* <과제 2>
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

	int arr[5];
	int maxi, mini;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	get_max_min(arr, &maxi, &mini);

	cout << "최댓값 : " << maxi << " 최솟값 : " << mini;

	return 0;
}

void get_max_min(int* p_arr, int* p_max, int* p_min)
{
	*p_max = *(p_arr + 0);
	*p_min = *(p_arr + 0);

	for (int i = 0; i < 5; i++) {
		if (*(p_arr + i) > *p_max)
			*p_max = *(p_arr + i);
		if (*(p_arr + i) < *p_min)
			*p_min = *(p_arr + i);
	}

    return;
}