#include <iostream>
using namespace std;

/*
가로,세로를 인자로 넘겨받아 삼각형의 넓이와 직사각형의 넓이를 구하는
함수 get_area(int width,int height,int* p_area3,int* p_area4) 구현하여,
main 함수에서 해당 함수를 호출하고, 결과도 main함수에서 출력하는 프로그램을 작성하세요.
*/

void get_area(int width, int height, int* p_area3, int* p_area4);

int main()
{
	int w = 3;
	int h = 5;
	int p1;
	int p2;

	get_area(w, h, &p1, &p2);

	cout << "삼각형 : " << p1 << "\n사각형 : " << p2;

	return 0;
}

void get_area(int width, int height, int* p_area3, int* p_area4)
{
	*p_area3 = width * height / 2;
	*p_area4 = width * height;
}
