#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <algorithm>
using namespace cv;
using namespace std;

/*
사각형의 x, y(왼쪽꼭지점 위치), w, h(너비, 높이)를 member variable로 하는
MyRect 클래스를 만들고, 아래 자료를 넣은 후,
넓이가 넓은 순으로 정렬하여 하는 프로그램을 만드세요.
이때 void Sort_Rect(MyRect* p_arr, int n) 함수를 만들어 정렬하고, opencv 코드를 이용하여,
왼쪽에서 오른쪽 순서로 x, y를 변경하여 해당하는 사각형을 겹치지 않게 출력하세요.
1, 1, 100, 50 / 2, 2, 50, 100 / 1, 5, 60, 60 / 2, 7, 70, 40 / 3, 3, 50, 75
*/

class MyRect {
public:
    int x, y;
    int w, h;
    int vx, vy;

    MyRect() {
        x = NULL, y = NULL;
        w = NULL, h = NULL;
        vx = NULL, vy = NULL;
    }
    MyRect(int a, int b, int c, int d) {
        x = a, y = b;
        w = c, h = d;
        vx = NULL, vy = NULL;
    }
    MyRect(int a, int b, int c, int d, int e, int f) {
        x = a, y = b;
        w = c, h = d;
        vx = e, vy = f;
    }

    void move() { x += vx, y += vy; }

    int getArea() { return w * h; }
    int getRound() { return 2 * (w + h); }

    void display() {
        printf("point : (%d, %d), length : (%d, %d)\n", x, y, w, h);
    }
};

bool cmp_area(MyRect a, MyRect b) { return a.getArea() > b.getArea(); }
bool cmp_round(MyRect a, MyRect b) { return a.getRound() > b.getRound(); }
void Sort_Rect(MyRect* p_arr, int n) { sort(p_arr, p_arr + n, cmp_area); }

int main()
{
    MyRect rs[5] = { MyRect(1, 1, 100, 50), MyRect(2, 2, 50, 100), MyRect(1, 5, 60, 60), MyRect(2, 7, 70, 40), MyRect(3, 3, 50, 75) };
    Sort_Rect(rs, 5);

    for (int i = 1; i < 5; i++) {
        rs[i].x = rs[i - 1].x + rs[i - 1].w;
        rs[i].y = rs[i - 1].y + rs[i - 1].h;
    }

    int i = 0;
    int mx = 640, my = 480;

    Mat rawimg, drawimg;

    rawimg = Mat(my, mx, CV_8UC3, Scalar(100, 100, 0));
    imshow("img-raw", rawimg);
    waitKey(1000);

    rawimg.copyTo(drawimg);
    while (i < 5)
    {
        if (i % 2 == 1)
            rectangle(drawimg, cv::Rect(rs[i].x, rs[i].y, rs[i].w, rs[i].h), Scalar(25, 255, 25), 1, 8, 0);
        else
            rectangle(drawimg, cv::Rect(rs[i].x, rs[i].y, rs[i].w, rs[i].h), Scalar(255, 255, 255), 1, 8, 0);

        imshow("img-raw", drawimg);
        waitKey(1000);
        i++;
    }

    return 0;
}
