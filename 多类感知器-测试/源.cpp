#include<iostream>
#include<io.h>
#include<opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<opencv2/core/core.hpp>
#include <string>
#include <fstream>
#include"mnist.h"
using namespace std;
using namespace cv;

typedef struct wNode {
	int left = -1;
	int right = -1;
	wNode* leftChild = NULL;
	wNode* rightChild = NULL;
	Mat w = Mat::zeros(Size(785, 1), CV_32FC1);
};

Mat images = Mat::zeros(10000, 784, CV_8UC1);
Mat labels = Mat::zeros(10000, 1, CV_8UC1);

/*
void add()
{
	for (int i = 0; i < 785; i++)
	{
		w[i] += x[i] * c;
	}
}

void train(int i, bool isLeft)
{
	uchar* row_i = images.ptr<uchar>(i);
	double sum = 0.0;
	for (int i = 0; i < 784; i++)
	{
		//cout << (float)*row;
		x[i] = *row_i++ * (isLeft ? 1 : -1);
		sum += x[i] * w[i];
	}
	x[784] = (isLeft ? 255 : -255);
	sum += w[784] * x[784];
	if (sum <= 0)
	{
		add();
	}
}

void train1479_082356(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train1479_082356第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 1:case 4:case 7:case 9:
				train(i, true);
				break;
			case 0:case 8:case 2:case 3:case 5:case 6:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train1479_082356完成。" << endl;
}

void train08_2356(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train08_2356第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 0:case 8:
				train(i, true);
				break;
			case 2:case 3:case 5:case 6:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train08_2356完成。" << endl;
}

void train23_56(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train23_56第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 2:case 3:
				train(i, true);
				break;
			case 5:case 6:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train23_56完成。" << endl;
}

void train4_179(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train4_179第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 4:
				train(i, true);
				break;
			case 1:case 7:case 9:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train4_179完成。" << endl;
}

void train1_79(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train1_79第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 1:
				train(i, true);
				break;
			case 7:case 9:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train1_79完成。" << endl;
}

void train79(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train79第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 7:
				train(i, true);
				break;
			case 9:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train79完成。" << endl;
}

void train08(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train08第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 0:
				train(i, true);
				break;
			case 8:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train08完成。" << endl;
}

void train23(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train23第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 2:
				train(i, true);
				break;
			case 3:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train23完成。" << endl;
}

void train56(wNode& wn)
{
	int number = P;
	while (number--)
	{
		cout << "正在进行train56第" << P - number << "次训练。。。" << endl;
		for (int i = 0; i < 60000; i++)
		{
			int label = labels.at<int>(i, 0);
			switch (label)
			{
			case 5:
				train(i, true);
				break;
			case 6:
				train(i, false);
				break;
			default:
				break;
			}
		}
	}
	float* row = wn.w.ptr<float>(0);
	for (int i = 0; i < 785; i++)
	{
		*row++ = w[i];
	}
	cout << "train56完成。" << endl;
}*/


int test(int i,wNode wn)
{
	double sum = 0.0;
	float* cur_row = images.ptr<float>(i);
	for (int j = 0; j < 784; j++)
	{
		double dd = wn.w.at<float>(0, j);
		sum += dd * *cur_row++;
	}
	sum += 255 * wn.w.at<float>(0, 784);
	if (sum >= 0 && wn.left == -1)
	{
		return test(i,*wn.leftChild);
	}
	if (sum < 0 && wn.right == -1)
	{
		return test(i,*wn.rightChild);
	}
	if (sum >= 0)return wn.left;
	if (sum < 0)return wn.right;
}

int main(int argc, char** argv)
{
	//cout << getFileNumber("D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages/1/0.bmp");
	cout << "测试开始。" << endl;

	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_test\\mnist_test_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_test.txt";

	Read_test_image(trainImageFiltPath, 10000, 0, &images);
	//cout << images;
	Read_txt(fileName, &labels);

	images.convertTo(images, CV_32FC1);
	labels.convertTo(labels, CV_32SC1);

	wNode w79 = { 7,9 };
	wNode w08 = { 0,8 };
	wNode w23 = { 2,3 };
	wNode w56 = { 5,6 };
	wNode w1_79 = { 1,-1, NULL,&w79 };
	wNode w4_179 = { 4,-1, NULL,&w1_79 };
	wNode w23_56 = { -1,-1, &w23,&w56 };
	wNode w08_2356 = { -1,-1, &w08,&w23_56 };
	wNode w1479_082356 = { -1,-1, &w4_179,&w08_2356 };

	ifstream f("D:\\resultW.txt");
	if (f)
	{
		for (int i = 0; i < 785; i++)
		{
			f >> w1479_082356.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w08_2356.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w23_56.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w4_179.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w1_79.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w56.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w23.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w08.w.at<float>(0, i);
		}
		for (int i = 0; i < 785; i++)
		{
			f >> w79.w.at<float>(0, i);
		}
		f.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return 0;
	}

	//cout << labels;
	int number = 0;
	for (int i = 0; i < 10000; i++)
	{
		int label=test(i,w1479_082356);
		int* cur_label = labels.ptr<int>(i);
		cout << "真实值为：" << *cur_label << ",预测结果为：" << label;
		if (label == *cur_label)
		{
			cout << "  预测正确。" << endl;
			number++;
		}else {
			cout << "  预测错误。" << endl;
		}
	}

	cout << "正确率：" << number / 10000.0 << endl;


	return 0;
}

