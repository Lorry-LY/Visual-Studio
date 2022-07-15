#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic32.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("ͼƬ����rʧ�ܡ�\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);


	//������˹�ݶ����Ӽ���
	Mat dst,blur_imgae,sums;
	Laplacian(src, dst, -1, 3, 1.0, 0, BORDER_DEFAULT);
	imshow("14", dst);
	GaussianBlur(src, blur_imgae, Size(3, 3), 0);
	addWeighted(blur_imgae, 1.0, dst, -0.7, 0, sums);
	imshow("sums", sums);
	






	waitKey(0);
	destroyAllWindows();

	return 0;
}