#include <iostream>
using namespace std;

/*
사각형의 x, y(왼쪽꼭지점 위치), w, h (너비, 높이)를 member variable로 하는
MyRect 클래스를 만들고, 아래 자료를 넣은 후,
한번은 넓이가 넓은 순으로 정렬하여 하는 프로그램을 만드세요.
이때 void Sort_Rect(MyRect* p_arr, int n) 함수를 만들어 정렬하고,
최종 결과는 main에서 출력하세요.
1, 1, 100, 50 / 2, 2, 50, 100 / 1, 5, 60, 60 / 2, 7, 70, 40 / 3, 3, 50, 75
*/

class MyRect {
    int x, y;
    int w, h;

public:
    MyRect() {
        x = NULL, y = NULL;
        w = NULL, h = NULL;
    }
    MyRect(int a, int b, int c, int d) {
        x = a, y = b;
        w = c, h = d;
    }

    int getArea() { return w * h; }
    int getRound() { return 2 * (w + h); }

    void display() {
        printf("point : (%d, %d), length : (%d, %d)\n", x, y, w, h);
    }
};

bool cmp_area(MyRect a, MyRect b) { return a.getArea() > b.getArea(); }
bool cmp_round(MyRect a, MyRect b) { return a.getRound() > b.getRound(); }
void Sort_Rect(MyRect* p_arr, int n, bool (*cmp)(MyRect, MyRect)=(&cmp_area));

int main()
{
    MyRect rs[5] = { MyRect(1, 1, 100, 50), MyRect(2, 2, 50, 100), MyRect(1, 5, 60, 60), MyRect(2, 7, 70, 40), MyRect(3, 3, 50, 75) };
    
    Sort_Rect(rs, 5);

    printf("넓이 기준 내림차순 정렬\n");
    for (int i = 0; i < 5; i++)
        rs[i].display();

    return 0;
}

void Sort_Rect(MyRect* p_arr, int n, bool (*cmp)(MyRect, MyRect))
{
    for (int i = 0; i < n - 1; i++) {
        int idx = i;

        for (int j = i + 1; j < n; j++) {
            if (cmp(*(p_arr + j), *(p_arr + idx)))
                idx = j;
        }

        MyRect t = *(p_arr + i);
        *(p_arr + i) = *(p_arr + idx);
        *(p_arr + idx) = t;
    }

    return;
}
