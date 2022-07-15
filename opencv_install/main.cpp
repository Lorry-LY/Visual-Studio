#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread(argv[1]);
	if (src.empty())
	{
		printf("ͼƬ����rʧ�ܡ�\n");
		return -1;
	}

	namedWindow("test opencv setup",cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	waitKey(0);

	return 0;
}


//int main(int argc, char** atgv)
//{
//	Mat src = imread("D:/MSVC_2019/background.png");
//
//	if (src.empty())
//	{
//		printf("null\n");
//		return -1;
//	}
//	namedWindow("test opencv setup", WINDOW_AUTOSIZE);
//	imshow("test opencv setup", src);
//
//	waitKey(0);
//	return 0;
//}





