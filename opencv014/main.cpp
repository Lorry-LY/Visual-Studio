#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic26.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("ͼƬ����rʧ�ܡ�\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);


	//������˹�ݶ����Ӽ���
	Mat dst;
	Laplacian(src, dst, -1, 3, 1.0, 0, BORDER_DEFAULT);
	imshow("14", dst);

	//��
	Mat sh_op = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	Mat result;
	filter2D(src, result, CV_32F, sh_op, Point(-1, -1), 0, BORDER_DEFAULT);
	convertScaleAbs(result, result);
	imshow("result", result);

	

	


	waitKey(0);
	destroyAllWindows();

	return 0;
}