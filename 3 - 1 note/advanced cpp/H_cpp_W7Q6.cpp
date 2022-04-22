/*
수학점수 배열 int math[6] = {88,90,70,95,100,66} 를 main()에 선언하고,
배열의 주소를 포인터로 받아서 정렬하는 void sort(int* p_math)를 호출하여
오름 차순으로 정렬하고, 최종 결과는 main()에서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

void sort(int* p_math) {
	for (int i = 0; i < 6 - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < 6; j++) {
			if (*(p_math + j) > *(p_math + idx))
				idx = j;
		}

		int temp = *(p_math + i);
		*(p_math + i) = *(p_math + idx);
		*(p_math + idx) = temp;
	}
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int math[6] = { 88, 90, 70, 95, 100, 66 };

	sort(math);

	for (int i = 0; i < 6; i++)
		cout << math[i] << " ";

	return 0;
}
