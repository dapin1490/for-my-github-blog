#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*
과제15의 4번의 충돌 관련 코드를 MyRect의 멤버 함수로 구현해서 동일한 기능을 수행하도록 하시오
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

int main()
{
    int i = 0;
    int mw = 640, mh = 480;

    ::MyRect rc = ::MyRect(1, 1, 32, 32, 3, 3);

    Mat rawimg, drawimg;

    rawimg = Mat(mh, mw, CV_8UC3, Scalar(100, 100, 0));
    imshow("img-raw", rawimg);
    waitKey(1000);

    while (i < 1000)
    {
        rawimg.copyTo(drawimg);
        
        if (i % 2 == 1)
            rectangle(drawimg, cv::Rect(rc.x, rc.y, rc.w, rc.h), Scalar(25, 255, 25), 1, 8, 0);
        else
            rectangle(drawimg, cv::Rect(rc.x, rc.y, rc.w, rc.h), Scalar(255, 255, 255), 1, 8, 0);

        imshow("img-raw", drawimg);
        waitKey(1000);
        i++;
        rc.move(mw, mh);
    }

    return 0;
}
