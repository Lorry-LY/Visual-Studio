#include<iostream>
#include<io.h>
#include<opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<opencv2/core/core.hpp>
#include <string>
#include <fstream>
using namespace std;
using namespace cv;

double x[785] = { 0 };
double w[785] = { 0 };
const float c = 0.1;

void add()
{
	for (int i = 0; i < 785; i++)
	{
		w[i] += x[i] * c;
	}
}

bool train_picture(string file, int label)
{
	Mat image = imread(file, IMREAD_COLOR);
	////梯度计算
	////robot梯度算子计算
	//Mat robot_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);
	//Mat robot_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);

	//Mat grad_x, grad_y;
	//filter2D(image, grad_x, CV_32F, robot_x, Point(-1, -1), 0, BORDER_DEFAULT);
	//filter2D(image, grad_y, CV_32F, robot_y, Point(-1, -1), 0, BORDER_DEFAULT);
	//convertScaleAbs(grad_x, grad_x);
	//convertScaleAbs(grad_y, grad_y);
	//Mat src;
	//add(grad_x, grad_y, src);
	//imshow("result", result);
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	Mat dst = Mat(Size(784, 1), IMREAD_GRAYSCALE);
	uchar* result_row = dst.ptr<uchar>(0);
	for (int row = 0; row < 28; row++)
	{
		uchar* curr_row = gray.ptr<uchar>(row);
		for (int col = 0; col < 28; col++)
		{
			uchar pv = *curr_row++;
			*result_row++ = pv;
		}
	}
	//cout << dst;
	uchar* row = dst.ptr<uchar>(0);
	double sum = 0.0;
	for (int i = 0; i < 784; i++)
	{
		//cout << (float)*row;
		x[i] = *row++ * (label == 5 ? 1 : -1);
		sum += x[i] * w[i];
	}
	x[784] = (label == 5 ? 255 : -255);
	sum += w[784] * x[784];
	if (sum <= 0)
	{
		add();
		return false;
	}
	return true;
}

int train_class(string className)
{
	int number = 20;
	int numberRight = 0;
	while (number--)
	{
		cout << "正在进行第" << 20-number << "次训练。。。" << endl;
		numberRight = 0;
		int flag = 0;
		for (int i = 0; i < 4000; i += flag)
		{
			if (flag)
			{
				string s = className + "/5/" + to_string(i) + ".bmp";
				if (train_picture(s, 5))numberRight++;
				flag = 0;
			}
			else
			{
				string s = className + "/8/" + to_string(i) + ".bmp";
				if (train_picture(s, 8))numberRight++;
				flag = 1;
			}
		}
	}
	cout << numberRight;
	return numberRight;
}


bool test_picture(string file, int label)
{
	Mat gray = imread(file, IMREAD_GRAYSCALE);
	Mat dst = Mat(Size(784, 1), IMREAD_GRAYSCALE);
	uchar* result_row = dst.ptr<uchar>(0);
	for (int row = 0; row < 28; row++)
	{
		uchar* curr_row = gray.ptr<uchar>(row);
		for (int col = 0; col < 28; col++)
		{
			float pv = *curr_row++;
			*result_row++ = pv;
		}
	}
	uchar* row = dst.ptr<uchar>(0);
	double sum = 0.0;
	for (int i = 0; i < 784; i++)
	{
		x[i] = *row++ * (label == 5 ? 1 : -1);
		sum += x[i] * w[i];
	}
	x[784] = (label == 5 ? 255 : -255);
	sum += w[784] * x[784];
	if (sum >= 0)return true;
	else return false;
}

int test_class(string className)
{
	int numberRight = 0;
	int flag = 0;
	for (int i = 4000; i < 4250; i++)
	{
		string s = className + "/5/" + to_string(i) + ".bmp";
		if (test_picture(s, 5))numberRight++;
	}
	for (int i = 4000; i < 4250; i++)
	{
		string s = className + "/8/" + to_string(i) + ".bmp";
		if (test_picture(s, 8))numberRight++;
	}
	return numberRight;
}


int main(int argc, char** argv)
{
	//cout << getFileNumber("D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages/1/0.bmp");
	for (int i = 0; i < 785; i++)
	{
		w[i] = 1;
	}

	cout << "训练开始。" << endl;

	string trainPath = "D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages";
	int number = train_class(trainPath);
	cout << "识别成功" + to_string(number) + "张，共8000张，成功率：" + to_string(number / (double)8000);

	cout << "最后w训练结果" << endl << "[";
	for (int i = 0; i < 785; i++)
	{
		cout << w[i] << " ";
	}
	cout << "]" << endl;

	cout << "测试开始。" << endl;

	number = test_class(trainPath);
	cout << "测试正确" + to_string(number) + "张，共500张，成功率：" + to_string(number / (double)500);


	return 0;
}

