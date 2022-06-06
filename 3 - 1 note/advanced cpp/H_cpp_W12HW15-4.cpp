#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*
사각형의 x, y(왼쪽꼭지점 위치), w, h (너비, 높이)를 vx, vy(움직이는 속도)
member variable로 하는 MyRect 클래스를 만들고
(x, y, w, h, vx, vy) = (1, 1, 32, 32, 3, 3)인 인스턴스를 생성한 후,
(x, y, w, h) = (0, 0, 640, 480) 직사각형의 위를 움직이는 프로그램을 만듭니다.
경계선을 닿거나 침범하면 속도의 방향이 반대가 되도록 하세요.
(x, y, w, h) = (0, 0, 640, 480) 직사각형을 화면에 출력을 위해
https://nextus.tistory.com/14 을 참조하세요.
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

int main()
{
    int i = 0;
    int mx = 640, my = 480;

    ::MyRect rc = ::MyRect(1, 1, 32, 32, 3, 3);

    Mat rawimg, drawimg;

    std::cout << "Hello World!\n";
    cout << "OpenCV Version : " << CV_VERSION << endl;

    namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
    rawimg = Mat(my, mx, CV_8UC3, Scalar(100, 100, 0));
    imshow("img-raw", rawimg);
    waitKey(1000);

    while (i < 2000)
    {
        rawimg.copyTo(drawimg);

        if (i % 2 == 1)
            rectangle(drawimg, cv::Rect(rc.x, rc.y, rc.w, rc.h), Scalar(25, 255, 25), 1, 8, 0);
        else
            rectangle(drawimg, cv::Rect(rc.x, rc.y, rc.w, rc.h), Scalar(255, 255, 255), 1, 8, 0);

        imshow("img-raw", drawimg);
        waitKey(1000);
        i++;
        rc.move();

        if (rc.x <= 0 || rc.y <= 0 || rc.x + rc.w >= mx || rc.y + rc.h >= my) {
            if (rc.x + rc.w >= mx)
                rc.vx = abs(rc.vx) * -1;
            if (rc.y + rc.h >= my)
                rc.vy = abs(rc.vy) * -1;
            if (rc.x <= 0)
                rc.vx = abs(rc.vx);
            if (rc.y < 0)
                rc.vy = abs(rc.vy);

            rc.move();
        }
    }

    return 0;
}
