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
	Mat edges,result;
	Canny(src, edges, t1, t1 * 3, 3, false);
	bitwise_and(src, src, result, edges);
	imshow("edges", result);
}


int main(int argc, char** argv)
{
	src = imread("C:/Users/87419/Desktop/Pa/pic30.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);


	//Canny Demo
	createTrackbar("threshold value:", "test opencv setup", &t1, 100, canny_demo);
	canny_demo(0, 0);



	waitKey(0);
	destroyAllWindows();

	return 0;
}