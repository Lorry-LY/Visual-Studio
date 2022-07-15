#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic13.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	//自定义滤波-均值卷积
	int k = 15;
	Mat mkernel = Mat::ones(k, k, CV_32F)/(float)((long)k*k);

	Mat det;
	filter2D(src, det, -1, mkernel, Point(-1, -1), 0, BORDER_DEFAULT);
	imshow("det", det);

	//自定义滤波-非均值卷积
	Mat robot = (Mat_<int>(2, 2) << 1, 0, 0, -1);

	Mat dst;
	filter2D(src, dst, CV_32F, mkernel, Point(-1, -1), 0, BORDER_DEFAULT);
	convertScaleAbs(dst, dst);
	imshow("dst", dst);


	waitKey(0);
	destroyAllWindows();

	return 0;
}