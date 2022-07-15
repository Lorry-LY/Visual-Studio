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

double x[785] = { 0 };
double w[785] = { 0 };
const float c = 0.1;
const int P = 100;

typedef struct wNode {
	wNode* leftChild = NULL;
	wNode* rightChile = NULL;
	Mat w = Mat::zeros(Size(785, 1), CV_32FC1);
};

Mat images = Mat::zeros(60000, 784, CV_8UC1);
Mat labels = Mat::zeros(60000, 1, CV_8UC1);


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
		//cout << "正在进行train1479_082356第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train08_2356第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train23_56第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train4_179第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train1_79第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train79第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train08第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train23第" << P - number << "次训练。。。" << endl;
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
		//cout << "正在进行train56第" << P - number << "次训练。。。" << endl;
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
}

void initW()
{
	for (int i = 0; i < 785; i++)
	{
		w[i] = 1;
	}
}

int main(int argc, char** argv)
{
	//cout << getFileNumber("D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages/1/0.bmp");
	cout << "训练开始。" << endl;

	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_train.txt";

	Read_train_image(trainImageFiltPath, 60000, 0, &images);
	Read_txt(fileName, &labels);

	images.convertTo(images, CV_32FC1);
	labels.convertTo(labels, CV_32SC1);

	wNode w79;
	wNode w08;
	wNode w23;
	wNode w56;
	wNode w1_79 = { NULL,&w79 };
	wNode w4_179 = { NULL,&w1_79 };
	wNode w23_56 = { &w23,&w56 };
	wNode w08_2356 = { &w08,&w23_56 };
	wNode w1479_082356 = { &w4_179,&w08_2356 };

	initW();
	train1479_082356(w1479_082356);
	//cout << w1479_082356.w;
	initW();
	train08_2356(w08_2356);

	initW();
	train23_56(w23_56);

	initW();
	train4_179(w4_179);

	initW();
	train1_79(w1_79);

	initW();
	train56(w56);

	initW();
	train23(w23);

	initW();
	train08(w08);

	initW();
	train79(w79);

	ofstream f("D:\\resultW.txt");
	if (f)
	{
		for (int i = 0; i < 785; i++)
		{
			f << w1479_082356.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w08_2356.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w23_56.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w4_179.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w1_79.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w56.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w23.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w08.w.at<float>(0, i) << " ";
		}
		for (int i = 0; i < 785; i++)
		{
			f << w79.w.at<float>(0, i) << " ";
		}
		f.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return 0;
	}






	return 0;
}

