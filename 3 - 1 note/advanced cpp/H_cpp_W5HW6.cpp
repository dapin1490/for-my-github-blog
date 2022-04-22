#include <iostream>
using namespace std;

int main()
{
    /*
    다음의 중간고사 성적을  88,90,70,95,100,66  포인터 동적할당을 통해 입력하고, 
    선택정렬을 이용하여 내림차순으로 정렬하여 화면에 출력하시오.

    <<화면 예시>>
    학생수=6
    88
    90
    70
    95
    100
    66
    내림차순 정렬: 100 95 90 88 70 66
    */
    
    int* p;
	int n;

	cout << "학생수=";
	cin >> n;

	p = (int*)malloc(sizeof(int) * n); // 배열 동적 할당

	for (int i = 0; i < n; i++) {
		cin >> *(p + i); // 학생의 점수 입력받기
	}

	// 선택 정렬
	for (int i = 0; i < n - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < 5; j++) {
			if (*(p + j) > *(p + idx)) {
				idx = j;
			}
		}

		int temp = *(p + i);
		*(p + i) = *(p + idx);
		*(p + idx) = temp;
	}

	cout << "\n내림차순 정렬\n";
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}

	free(p); // 이게 제일 중요

	return 0;
}