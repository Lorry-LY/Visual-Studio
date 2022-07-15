#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("X:/image/5.jpg",IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);
	imwrite("D:/test.png", src);
	waitKey(0);

	return 0;
}