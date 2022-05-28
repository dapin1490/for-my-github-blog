#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*
사각형의 x, y(왼쪽꼭지점 위치), w, h(너비, 높이)를 vx, vy(움직이는 속도)
member variable로 하는 Rect 클래스를 만들고,
(3)의 예제 코드에 Rect 클래스의 객체를 선언하여 적용하는 프로그램을 작성하세요.
*/

class Rect {
    int x, y;
    int w, h;
    int vx, vy;

public:
    Rect() {
        x = NULL, y = NULL;
        w = NULL, h = NULL;
        vx = NULL, vy = NULL;
    }
    Rect(int a, int b, int c, int d) {
        x = a, y = b;
        w = c, h = d;
        vx = NULL, vy = NULL;
    }
    Rect(int a, int b, int c, int d, int e, int f) {
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
    int x = 0, y = 0, w = 100, h = 100;
    int vx = 3, vy = 3;

    ::Rect rc = ::Rect(x, y, w, h, vx, vy);

    Mat rawimg, drawimg;

    std::cout << "Hello World!\n";
    cout << "OpenCV Version : " << CV_VERSION << endl;

    namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
    rawimg = imread("test.jpg", IMREAD_COLOR);
    imshow("img-raw", rawimg);
    waitKey(1000);

    while (1)
    {
        rawimg.copyTo(drawimg);

        if (i % 2 == 1)
            rectangle(drawimg, rc, Scalar(255, 255, 255), 1, 8, 0);
        else
            rectangle(drawimg, rc, Scalar(0, 0, 0), 1, 8, 0);

        imshow("img-raw", drawimg);
        waitKey(1000);
        i++;
        rc.move();
    }

    return 0;
}
