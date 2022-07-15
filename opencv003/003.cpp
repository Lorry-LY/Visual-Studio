#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src1 = imread("D:/opencv/opencv/sources/samples/data/WindowsLogo.jpg",IMREAD_UNCHANGED);
	Mat src2 = imread("D:/opencv/opencv/sources/samples/data/LinuxLogo.jpg", IMREAD_UNCHANGED);
	/*if (src1.empty()||src2.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("input1", cv::WINDOW_AUTOSIZE);
	imshow("input1", src1);
	namedWindow("input2", cv::WINDOW_AUTOSIZE);
	imshow("input2", src2);
	moveWindow("input2", 800, 300);

	Mat dst1;
	add(src1, src2, dst1);
	imshow("des1", dst1);

	Mat dst2;
	subtract(src1, src2, dst2);
	imshow("dst2", dst2);

	Mat dst3;
	multiply(src1, src2, dst3);
	imshow("dst3", dst3);

	Mat dst4;
	divide(src1, src2, dst4);
	imshow("dst4", dst4);*/

	Mat src = imread("C:/Users/87419/Desktop/Pa/pic56.jpg", IMREAD_UNCHANGED);
	imshow("input", src);
	Mat black = Mat::zeros(src.size(), src.type());
	black = Scalar(60, 60, 60);
	Mat dest1;
	subtract(src, black, dest1);
	imshow("result", dest1);

	Mat dest2;
	addWeighted(src, 1.2, black, 0.5, 0.0, dest2);
	imshow("result2", dest2);

	waitKey(0);
	destroyAllWindows();
	return 0;
}