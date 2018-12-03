#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture testCamera;
    testCamera.open(0);
    int n = 100;
    while (n)
    {
        Mat src;
        testCamera >> src;
        imshow("test", src);
        waitKey(30);
        n--;
    }
    return 0;
}