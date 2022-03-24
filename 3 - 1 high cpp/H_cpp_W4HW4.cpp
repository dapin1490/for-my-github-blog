#include <iostream>
using namespace std;

void get_circle_info(double r, double* p_circumference, double* p_area);

const double PI = 3.14;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*
    반지름을 입력받아 원주와 원의 넓이를 구하는 프로그램을 작성하시오.
    이때, 원주율은 3.14를 사용하고,
    void get_circle_info(double r, double* p_circumference, double* p_area) 함수를 구현하여,
    원주와 원의 넓이는 main 함수에서 출력하도록 하세요.
    */

	double r;
	double cf; // 원주
	double area; // 넓이

	cin >> r;

	get_circle_info(r, &cf, &area);

	cout << "원주 : " << cf << " 넓이 : " << area << "\n";

	return 0;
}

void get_circle_info(double r, double* p_circumference, double* p_area)
{
	*p_circumference = 2 * PI * r;
	*p_area = PI * r * r;

	return;
}