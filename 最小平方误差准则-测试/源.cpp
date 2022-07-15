#include<iostream>
#include<io.h>
#include<opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<opencv2/core/core.hpp>
#include <string>
#include <fstream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string path = "D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages";
	Mat w = Mat::zeros(Size(785,1),CV_64F);
	double* row = w.ptr<double>(0);
	ifstream f("D:\\testW.txt");
	if (f)
	{
		for (int i = 0; i < 785; i++)
		{
			double temp;
			f >> temp;
			*row++ = temp;
		}
		f.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return 0;
	}
	//normalize(w, w, 1, -1);
	cout << w;
	//Mat src = Mat::zeros(Size(785, 1), CV_64F);
	//Mat b = imread("D:/testD.png", IMREAD_GRAYSCALE);
	int RightNumber = 0;
	for (int i = 4000; i < 4250; i++)
	{
		string s5 = path + "/5/" + to_string(i) + ".bmp";
		Mat m5 = imread(s5, IMREAD_GRAYSCALE);
		double* w_row = w.ptr<double>(0);
		double sum = 0;
		for (int row = 0; row < 28; row++)
		{
			uchar* curr_row = m5.ptr<uchar>(row);
			for (int col = 0; col < 28; col++)
			{
				uchar pv = *curr_row++;
				sum += pv * *w_row++;
			}
		}
		if (sum > 0)RightNumber++;
	}
	for (int i = 4000; i < 4250; i++)
	{
		string s8 = path + "/8/" + to_string(i) + ".bmp";
		Mat m8 = imread(s8, IMREAD_GRAYSCALE);
		double* w_row = w.ptr<double>(0);
		double sum = 0;
		for (int row = 0; row < 28; row++)
		{
			uchar* curr_row = m8.ptr<uchar>(row);
			for (int col = 0; col < 28; col++)
			{
				uchar pv = *curr_row++;
				sum += pv * *w_row++;
			}
		}
		if (sum < 0)RightNumber++;
	}
	cout << "测试正确率：" << RightNumber/500.0 << endl;

	return 0;
}