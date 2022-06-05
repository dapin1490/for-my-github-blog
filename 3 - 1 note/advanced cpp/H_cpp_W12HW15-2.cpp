#include <iostream>
using namespace std;

/*
main()에서 MyRect 클래스를 인스턴스를 2개 생성하여(1, 1, 100, 50 / 2, 2, 50, 100),
출력한 후 void swap(MyRect* p_b, MyRect* p_a)를 적용한 후 a, b가 바뀐 값을 출력하세요.
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

void swap(MyRect* p_b, MyRect* p_a);

int main()
{
    MyRect a(1, 1, 100, 50);
    MyRect b(2, 2, 50, 100);

    a.display();
    b.display();

    swap(&a, &b);

    a.display();
    b.display();
    
    return 0;
}

void swap(MyRect* p_b, MyRect* p_a)
{
    MyRect t = *p_a;
    *p_a = *p_b;
    *p_b = t;

    return;
}
