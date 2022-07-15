#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic49.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	//imshow("test opencv setup", src);
	Mat image = src.clone();

	//Ω∑—Œ‘Î…˘
	RNG rng(123450);
	int  h = src.rows;
	int w = src.cols;
	int nums = 10000;
	for (int i = 0; i < nums; i++)
	{
		int x = rng.uniform(0, w);
		int y = rng.uniform(0, h);
		if (i % 2 == 1)
		{
			src.at<Vec3b>(y, x) = Vec3b(255, 255, 255);
		}
		else
		{
			src.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
		}

	}
	imshow("Ω∑—Œ‘Î…˘", src);

	//∏ﬂÀπ‘Î…˘
	Mat noise = Mat::zeros(image.size(), image.type());
	randn(noise, Scalar(10, 20, 30), Scalar(60, 40, 30));
	Mat dst;
	add(image, noise, dst);
	imshow("∏ﬂÀπ‘Î…˘", dst);


	waitKey(0);
	destroyAllWindows();

	return 0;
}