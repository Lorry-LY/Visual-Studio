
#include<iostream>
#include"math.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	double W[3];


	W[1] = 0.5;
	W[2] = 0.5;


	double X[4][3] = { -1,1,1,
		-1,-0.5,-1,
		-1,3,1,
		-1,-2,-1 };
	double d[4] = { 1,-1,1,-1 };
	double e[4];
	double E[10] = { 0,0,0,0,0,0,0,0,0,0 };
	double b = 6;

	W[0] = b;
	cout << "初始化权值矩阵为:" << endl << W[0] << "  " << W[1] << "  " << W[2] << endl;
	double l = 0.1;

	double Y[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		Y[i] = W[0] * X[i][0] + W[1] * X[i][1] + W[2] * X[i][2];

		if (Y[i] >= 0)
			Y[i] = 1;
		else
			Y[i] = -1;

		e[i] = abs(d[i] - Y[i]);
	}
	E[0] = e[0] + e[1] + e[2] + e[3];
	cout << "误差变化如下：" << endl << "E{0]=" << E[0] << endl;

	int n = 0;
	while (E[n] > 0)
	{
		n++;
		for (int i = 0; i < 4; i++)
		{

			W[1] = W[1] + l * (d[i] - Y[i]) * X[i][1];
			W[2] = W[2] + l * (d[i] - Y[i]) * X[i][2];
			//cout<<W[1]<<endl<<W[2]<<endl;
			Y[i] = W[0] * X[i][0] + W[1] * X[i][1] + W[2] * X[i][2];
			if (Y[i] >= 0)
				Y[i] = 1;
			else
				Y[i] = -1;

			e[i] = abs(d[i] - Y[i]);

		}

		E[n] = e[0] + e[1] + e[2] + e[3];


		cout << "E[" << n << "]=" << E[n] << endl;

	}
	cout << "所求权值矩阵W[]=" << endl;

	for (int j = 0; j < 3; j++)
		cout << W[j] << " ";
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (Y[i] == 1)
			cout << "第" << i << "组属于第一类" << endl;
		if (Y[i] == -1)
			cout << "第" << i << "组属于第二类" << endl;
	}

	cout << "ok" << endl;


	Mat img(400, 400, CV_8UC3, Scalar(130, 240, 205));//3通道图像
	line(img, Point(200, 0), Point(200, 400), Scalar(0, 0, 0));
	line(img, Point(0, 200), Point(400, 200), Scalar(0));
	for (int i = 0; i < 4; i++)
	{
		//putText(img,"(X[i][1],200-40*X[i][2]",Point(200+40*X[i][1],200-40*X[i][2]),CV_FONT_HERSHEY_COMPLEX,1,Scalar(220,0,150));
		circle(img, Point(200 + 40 * X[i][1], 200 - 40 * X[i][2]), 1, Scalar(220, 0, 150), 1, 8, 0);
	}
	line(img, Point(200, 200 - 40 * b / W[2]), Point(200 + 40 * b / W[1], 200), Scalar(220, 20, 230));
	namedWindow("line Image");
	imshow("line Image", img);
	imwrite("img.bmp", img);
	Mat test(400, 400, CV_8UC3, Scalar(130, 240, 205));//3通道图像
	line(test, Point(20, 400 - 20), Point(20, 0), Scalar(0));//因为mat型图像的原点在右上角，所以比较麻烦，要通过计算转换
	line(test, Point(20, 400 - 20), Point(400, 400 - 20), Scalar(0));


	for (int i = 0; i < 9; i++)
	{
		line(test, Point(20 * (i + 1), 380 - 20 * E[i]), Point(20 * (i + 2), 380 - 20 * E[i + 1]), Scalar(220, 0, 150));
	}

	// Display the test image
	namedWindow("E Image");
	imshow("E Image", test);
	imwrite("test.bmp", test);
	waitKey();
	return 0;
}
