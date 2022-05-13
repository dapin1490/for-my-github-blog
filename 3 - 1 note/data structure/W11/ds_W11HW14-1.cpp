#include <iostream>
using namespace std;

/*
(1)
사각형의 width, height를 입력 받아, 사각형의 넓이와 둘레를 구하고자 한다.
이때, 함수는 void getRectInfo(int width, int height, int* p_area, int* p_perimeter)로 구현하여,
결과는 main()함수에서 출력되도록 한다.
*/

void getRectInfo(int width, int height, int* p_area, int* p_perimeter);

int main()
{
	int w, h;
	int area, peri;

	cout << "사각형의 width, height를 입력 : ";
	cin >> w >> h;

	getRectInfo(w, h, &area, &peri);

	printf("넓이 : %d, 둘레 : %d\n", area, peri);

	return 0;
}

void getRectInfo(int width, int height, int* p_area, int* p_perimeter)
{
	*p_area = width * height;
	*p_perimeter = width * 2 + height * 2;
	
	return;
}
