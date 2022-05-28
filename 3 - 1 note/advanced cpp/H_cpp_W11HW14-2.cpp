#include <iostream>
#include <algorithm>
using namespace std;

/*
사각형의 x, y(왼쪽꼭지점 위치), w, h (너비, 높이)를 member variable로 하는
Rect 클래스를 만들고, 아래 자료를 넣은 후,
한번은 넓이가 넓은 순으로 정렬하여 보여주고,
한번은 둘레 길이가 넓은 순으로 정렬하여 보여주는 프로그램을 작성하세요.
1, 1, 100, 50 / 2, 2, 50, 100 / 1, 5, 60, 60 / 2, 7, 70, 40 / 3, 3, 50, 75
*/

class Rect {
	int info[4];

public:
	Rect() {
		for (int i = 0; i < 4; i++)
			info[i] = NULL;
	}
	Rect(int a, int b, int c, int d) {
		info[0] = a, info[1] = b;
		info[2] = c, info[3] = d;
	}

	int* getInfo() { return info; }

	int getArea() { return info[2] * info[3]; }
	int getRound() { return 2 * (info[2] + info[3]); }

	void display() {
		printf("point : (%d, %d), length : (%d, %d)\n", info[0], info[1], info[2], info[3]);
	}
};

bool cmp_area(Rect a, Rect b) { return a.getArea() > b.getArea(); }
bool cmp_round(Rect a, Rect b) { return a.getRound() > b.getRound(); }

int main()
{
	Rect rs[5] = { Rect(1, 1, 100, 50), Rect(2, 2, 50, 100), Rect(1, 5, 60, 60), Rect(2, 7, 70, 40), Rect(3, 3, 50, 75) };

	sort(rs, rs + 5, cmp_area);
	printf("넓이순 정렬\n");
	for (int i = 0; i < 5; i++)
		rs[i].display();

	sort(rs, rs + 5, cmp_round);
	printf("\n둘레순 정렬\n");
	for (int i = 0; i < 5; i++)
		rs[i].display();

	return 0;
}
