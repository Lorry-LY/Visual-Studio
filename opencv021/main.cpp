#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;
Mat src;
int t1 = 50;
void canny_demo(int, void*)
{
	Mat edges, result;
	Canny(src, edges, t1, t1 * 3, 3, false);
	bitwise_and(src, src, result, edges);
	imshow("edges", result);
}


int main(int argc, char** argv)
{
	src = imread("C:/Users/87419/Desktop/Pa/pic30.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);


	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);

	//均值法
	Scalar m = mean(gray);
	threshold(gray, binary, m[0], 255, THRESH_BINARY);
	imshow("binary", binary);

	//最小累累方差求取最佳数值的方法
	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	imshow("BINARY2", binary);


	//三角法
	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);
	imshow("BINARY3", binary);


	waitKey(0);
	destroyAllWindows();

	return 0;
}