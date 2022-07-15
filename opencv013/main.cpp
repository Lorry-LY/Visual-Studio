#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("X:/question1/Pic1_3.bmp", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);


	//robot梯度算子计算
	Mat robot_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);
	Mat robot_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);

	Mat grad_x, grad_y;
	filter2D(src, grad_x, CV_32F, robot_x, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, grad_y, CV_32F, robot_y, Point(-1, -1), 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, grad_x);
	convertScaleAbs(grad_y, grad_y);
	Mat result;
	add(grad_x, grad_y, result);
	cvtColor(result, result, COLOR_BGR2BGRA);
	//threshold(result, result, 100, 255, CV_THRESH_BINARY);
	equalizeHist(result, result);
	imshow("robot", result);

	//Sobel算子
	Mat sobel_x, sobel_y, result2;
	Sobel(src, sobel_x, CV_32F, 1, 0, 3, 1.0, 0, BORDER_DEFAULT);
	Sobel(src, sobel_y, CV_32F, 1, 0, 3, 1.0, 0, BORDER_DEFAULT);
	convertScaleAbs(sobel_x, sobel_x);
	convertScaleAbs(sobel_y, sobel_y);
	//add(sobel_x, sobel_y, result2);
	addWeighted(sobel_x, 0.5, sobel_y, 0.5, 0, result2);
	//threshold(result2, result2, 100, 255, CV_THRESH_BINARY);
	imshow("Sobel", result2);

	//Scharr算子
	Mat Scharr_x, Scharr_y, result3;
	Scharr(src, Scharr_x, CV_32F, 1, 0, 3, 1.0, 0);
	Scharr(src, Scharr_y, CV_32F, 1, 0, 3, 1.0, 0);
	convertScaleAbs(Scharr_x, Scharr_x);
	convertScaleAbs(Scharr_y, Scharr_y);
	addWeighted(Scharr_x, 0.3, Scharr_y, 0.3, 0, result3);
	//threshold(result3, result3, 100, 255, CV_THRESH_BINARY);
	imshow("Scharr", result3);


	waitKey(0);
	destroyAllWindows();

	return 0;
}