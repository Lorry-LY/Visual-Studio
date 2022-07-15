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

	//高斯模糊
	Mat dst;
	GaussianBlur(src, dst, Size(5, 5), 0);
	imshow("gaussina", dst);

	//盒子模糊
	Mat box;
	boxFilter(src, box, -1, Size(5, 5), Point(-1, -1), true, BORDER_DEFAULT);
	imshow("box", box);


	waitKey(0);
	destroyAllWindows();

	return 0;
}