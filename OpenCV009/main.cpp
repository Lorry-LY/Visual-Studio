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
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	Mat color = imread("C:/Users/87419/Desktop/Pa/pic13.jpg");
	Mat lut = Mat::zeros(256, 1, CV_8UC3);
	for (int i = 0; i < 256; i++)
	{
		lut.at<Vec3b>(i, 0) = color.at<Vec3b>(10, i);
	}
	Mat des = Mat::zeros(src.size(), CV_8SC3);
	applyColorMap(src, des, COLORMAP_BONE);

	imshow("result", des);

	waitKey(0);
	destroyAllWindows();

	return 0;
}