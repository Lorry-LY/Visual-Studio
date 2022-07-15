#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic56.jpg",IMREAD_UNCHANGED);
	if (src.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	//ÕºœÒ»°∑¥
	Mat m1;
	Mat mask = Mat::zeros(src.size(), CV_8UC1);
	int height = src.rows / 2;
	int weight = src.cols / 2;
	int dim = src.channels();
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < weight; col++)
		{
			mask.at<uchar>(row, col) = 255;
		}
	}
	imshow("mask", mask);
	bitwise_not(src, m1, mask);
	imshow("not", m1);

	Mat m2;
	bitwise_and(src, src, m2 , mask);
	imshow("and", m2);

	Mat m3;
	bitwise_or(src, m1, m3, Mat());
	imshow("or", m3);

	waitKey(0);

	return 0;
}