#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

void add_noise(Mat src, Mat image)
{
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
	imshow("椒盐噪声", src);

	//高斯噪声
	Mat noise = Mat::zeros(image.size(), image.type());
	randn(noise, Scalar(10, 20, 30), Scalar(60, 40, 30));
	Mat dst;
	add(image, noise, dst);
	imshow("高斯噪声", dst);
}


int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic48.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);
	Mat image = src.clone();

	//中值滤波
	add_noise(src, image);


	Mat dst;
	medianBlur(src, dst, 5);
	imshow("中值滤波", dst);

	//高斯滤波
	Mat des;
	GaussianBlur(image, des, Size(5, 5), 0);
	imshow("高斯滤波", des);


	//双边滤波---用于美颜
	Mat d;
	bilateralFilter(image, d, 0, 100, 0, BORDER_DEFAULT);
	imshow("双边滤波", d);


	//非局部均值去噪
	fastNlMeansDenoisingColored(src, d, 3, 100, 7, 21);
	fastNlMeansDenoising(image, dst);
	imshow("fastColor", d);
	imshow("fastGray", dst);



	waitKey(0);
	destroyAllWindows();

	return 0;
}