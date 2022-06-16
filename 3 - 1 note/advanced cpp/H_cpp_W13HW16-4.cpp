#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
using namespace cv;
using namespace std;

/*
(3)을 기반으로 MyRect의 객체 5개를 멤버 변수로 하고, 위치와 크기는 랜덤하게 초기화한 후,
동일한 기능을 수행하도록 하시오.
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

    void setVect(int nvx, int nvy) {
        vx = (vx > 0) ? nvx : -nvx;
        vy = (vy > 0) ? nvy : -nvy;
    }

    void move() { x += vx, y += vy; }
    void move(int mw, int mh) {
        move();

        if (x <= 0 || y <= 0 || x + w >= mw || y + h >= mh) {
            if (x + w >= mw)
                vx = abs(vx) * -1;
            if (y + h >= mh)
                vy = abs(vy) * -1;
            if (x <= 0)
                vx = abs(vx);
            if (y < 0)
                vy = abs(vy);

            move();
        }
    }

    int getArea() { return w * h; }
    int getRound() { return 2 * (w + h); }

    void display() {
        printf("point : (%d, %d), length : (%d, %d)\n", x, y, w, h);
    }
};

class MyGameTable : public MyRect {
public:
    MyRect table;
    MyRect* object = NULL;
    int n = NULL;

    MyGameTable() { table = MyRect(); }
    MyGameTable(int a, int b, int c, int d) { table = MyRect(a, b, c, d); }
    MyGameTable(int a, int b, int c, int d, int e, int f) { table = MyRect(a, b, c, d, e, f); }
    ~MyGameTable() { delete[] object; }

    void setObjectCount(int n) {
        if (n == NULL) {
            cout << "error: object count cannot be NULL\n";
            return;
        }
        this->n = n;
        object = new MyRect[n];
    }

    void makeObjectAll(MyRect* ar) { *object = *ar; }
};

bool cmp_area(MyRect a, MyRect b) { return a.getArea() > b.getArea(); }
bool cmp_round(MyRect a, MyRect b) { return a.getRound() > b.getRound(); }
void Sort_Rect(MyRect* p_arr, int n) { sort(p_arr, p_arr + n, cmp_area); }

int main()
{
    srand((unsigned int)time(NULL)); // 랜덤 시드를 랜덤하게 설정
    // 참고 : https://blockdmask.tistory.com/308
    
    MyRect rs[5];
    for (int i = 0; i < 5; i++) {
        rs[i] = MyRect(rand() % 11, rand() % 11, rand() % 131 + 20, rand() % 131 + 20, rand() % 50 + 1, rand() % 50 + 1);
    }
    
    Sort_Rect(rs, 5);

    for (int i = 1; i < 5; i++) {
        rs[i].x = rs[i - 1].x + rs[i - 1].w;
        rs[i].y = rs[i - 1].y + rs[i - 1].h;
    }

    int i = 0;
    int mw = 640, mh = 480;

    MyGameTable gt = MyGameTable(0, 0, mw, mh);

    Mat rawimg, drawimg;

    // std::cout << "Hello World!\n";
    // cout << "OpenCV Version : " << CV_VERSION << endl;

    rawimg = Mat(gt.table.h, gt.table.w, CV_8UC3, Scalar(100, 100, 0));
    imshow("img-raw", rawimg);
    waitKey(50);

    while (i < 500)
    {
        rawimg.copyTo(drawimg);

        for (int j = 0; j < 5; j++) {
            if (i % 2 == 1)
                rectangle(drawimg, cv::Rect(rs[j].x, rs[j].y, rs[j].w, rs[j].h), Scalar(25, 255, 25), 1, 8, 0);
            else
                rectangle(drawimg, cv::Rect(rs[j].x, rs[j].y, rs[j].w, rs[j].h), Scalar(255, 255, 255), 1, 8, 0);

            imshow("img-raw", drawimg);

            if (rand() % 5 == 0)
                rs[j].setVect(rand() % 50 + 1, rand() % 50 + 1);
            rs[j].move(mw, mh);
        }

        waitKey(50);
        i++;
    }

    return 0;
}
