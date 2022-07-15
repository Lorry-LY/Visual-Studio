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

long long m[28] = { 0 };
long long m1[28] = { 0 };
long long m2[28] = { 0 };
long long s[28] = { 0 };
long long s1[28] = { 0 };
long long s2[28] = { 0 };
double w[28] = { 0 };


void train_picture1(string file, int label)
{
	Mat image = imread(file, IMREAD_COLOR);
	
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	
	PCA pca(gray, Mat(), CV_PCA_DATA_AS_COL);
	Mat dst = Mat(Size(28, 1), IMREAD_GRAYSCALE);
	dst = pca.eigenvalues;
	
	float* row = dst.ptr<float>(0);
	for (int i = 0; i < 28; i++)
	{
		m1[i] += *row++;
	}
}

void train_picture2(string file, int label)
{
	Mat image = imread(file, IMREAD_COLOR);

	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);

	PCA pca(gray, Mat(), CV_PCA_DATA_AS_COL);
	Mat dst = Mat(Size(28, 1), IMREAD_GRAYSCALE);
	dst = pca.eigenvalues;

	float* row = dst.ptr<float>(0);
	for (int i = 0; i < 28; i++)
	{
		m2[i] += *row++;
	}
}

void getM(string className)
{
	for (int i = 0; i < 4000; i++)
	{
		string s = className + "/5/" + to_string(i) + ".bmp";
		train_picture1(s, 5);
		cout << "5已训练" << i << "张，共4000张。" << endl;
	}
	for (int i = 0; i < 28; i++)
	{
		m1[i] /= 4000;
	}
	for (int i = 0; i < 4000; i++)
	{
		string s = className + "/8/" + to_string(i) + ".bmp";
		train_picture2(s, 8);
		cout << "8已训练" << i << "张，共4000张。" << endl;
	}
	for (int i = 0; i < 28; i++)
	{
		m2[i] /= 4000;
		m[i] = m1[i] - m2[i];
	}
}

void getS(string className)
{
	cout << "正在计算..." << endl;
	for (int i = 0; i < 4000; i++)
	{
		string s = className + "/5/" + to_string(i) + ".bmp";
		Mat gray = imread(s, IMREAD_GRAYSCALE);
		PCA pca(gray, Mat(), CV_PCA_DATA_AS_COL);
		Mat dst = Mat(Size(28, 1), IMREAD_GRAYSCALE);
		dst = pca.eigenvalues;
		float* row = dst.ptr<float>(0);
		for (int i = 0; i < 28; i++)
		{
			s1[i] += (*row - m1[i]) * (*row - m1[i]) / pow(10, 5);
			row++;
		}
	}
	for (int i = 0; i < 4000; i++)
	{
		string s = className + "/8/" + to_string(i) + ".bmp";
		Mat gray = imread(s, IMREAD_GRAYSCALE);
		PCA pca(gray, Mat(), CV_PCA_DATA_AS_COL);
		Mat dst = Mat(Size(28, 1), IMREAD_GRAYSCALE);
		dst = pca.eigenvalues;
		float* row = dst.ptr<float>(0);
		for (int i = 0; i < 28; i++)
		{
			s2[i] += (*row - m2[i]) * (*row - m2[i]) / pow(10, 5);
			row++;
		}
	}
	for (int i = 0; i < 28; i++)
	{
		s[i] = s1[i] + s2[i];
	}
	cout << "计算完成..." << endl;
}

void getW()
{
	for (int i = 0; i < 28; i++)
	{
		w[i] = s[i] * m[i];
	}
}


bool test_picture(string file, int label)
{
	Mat gray = imread(file, IMREAD_GRAYSCALE);
	PCA pca(gray, Mat(), CV_PCA_DATA_AS_COL);
	Mat dst = Mat(Size(28, 1), IMREAD_GRAYSCALE);
	dst = pca.eigenvalues;
	//cout << dst << endl;
	//normalize(dst, dst, 0, 255);
	//cout << dst << endl;
	float* row = dst.ptr<float>(0);
	long long sum = 0.0;
	for (int i = 0; i < 28; i++)
	{
		sum += w[i] * *row++;
	}
	if (sum < 0)
	{
		if (label == 5)return false;
		else return true;
	}
	else
	{
		if (label == 8)return false;
		else return true;
	}
}

int test_class(string className)
{
	int numberRight = 0;
	int flag = 0;
	for (int i = 4000; i < 4300; i += flag)
	{
		if (flag)
		{
			string s = className + "/5/" + to_string(i) + ".bmp";
			if (test_picture(s, 5))numberRight++;
			flag = 0;
		}
		else
		{
			string s = className + "/8/" + to_string(i) + ".bmp";
			if (test_picture(s, 8))numberRight++;
			flag = 1;
		}
		if (!(i % 50))
		{
			string str = "已测试" + to_string(i * 2 - 8000) + "次，共600张";
			cout << str << endl;
		}
	}
	return numberRight;
}


int main(int argc, char** argv)
{
	//cout << getFileNumber("D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages/1/0.bmp");
	
	cout << "训练开始。" << endl;

	string trainPath = "D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages";
	getM(trainPath);
	getS(trainPath);
	getW();
	cout << "最后w训练结果" << endl << "[";
	for (int i = 0; i < 28; i++)
	{
		cout << w[i] << " ";
	}
	cout << "]" << endl;

	cout << "测试开始。" << endl;

	int number = test_class(trainPath);
	cout << "测试正确" + to_string(number) + "张，共500张，成功率：" + to_string(number / (double)500);


	return 0;
}

