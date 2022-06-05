#include <iostream>
using namespace std;

/*
(1) 코드에 (2)를 적용하여 코드를 완성하세요.
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

void swap(MyRect* p_b, MyRect* p_a);
void Sort_Rect(MyRect* p_arr, int n, bool (*cmp)(MyRect, MyRect) = (&cmp_area));

int main()
{
    MyRect rs[5] = { MyRect(1, 1, 100, 50), MyRect(2, 2, 50, 100), MyRect(1, 5, 60, 60), MyRect(2, 7, 70, 40), MyRect(3, 3, 50, 75) };

    Sort_Rect(rs, 5);

    printf("넓이 기준 내림차순 정렬\n");
    for (int i = 0; i < 5; i++)
        rs[i].display();

    return 0;
}

void swap(MyRect* p_b, MyRect* p_a)
{
    MyRect t = *p_a;
    *p_a = *p_b;
    *p_b = t;

    return;
}

void Sort_Rect(MyRect* p_arr, int n, bool (*cmp)(MyRect, MyRect))
{
    for (int i = 0; i < n - 1; i++) {
        int idx = i;

        for (int j = i + 1; j < n; j++) {
            if (cmp(*(p_arr + j), *(p_arr + idx)))
                idx = j;
        }

        swap((p_arr + i), (p_arr + idx));
    }

    return;
}
