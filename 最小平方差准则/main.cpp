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

const int N = 8000;
//double x[8000][785] = { 0 };
Mat x = Mat(Size(785, N), CV_64F);
Mat xInv= Mat(Size(N, 785), CV_64F);;
Mat w = Mat(Size(1, 785), CV_64F);
Mat b = Mat(Size(1, N), CV_64F);
Mat e = Mat(Size(1, N), CV_64F);
const double c = 0.1;


bool readImage(string path)
{
	double normalizeNumber = 0.001;
	for (int i = 0; i < N / 2; i++)
	{
		cout << "已读取" << i << "张5的图片。" << endl;
		double* x_row = x.ptr<double>(i);
		string s5 = path + "/5/" + to_string(i) + ".bmp";
		Mat m5 = imread(s5, IMREAD_GRAYSCALE);
		for (int row = 0; row < 28; row++)
		{
			uchar* curr_row = m5.ptr<uchar>(row);
			for (int col = 0; col < 28; col++)
			{
				double pv = *curr_row++;
				*x_row++ = (pv ? normalizeNumber : 0);
			}
		}
		*x_row = 1;
	}

	for (int i = 0; i < N / 2; i++)
	{
		cout << "已读取" << i << "张8的图片。" << endl;
		double* x_row = x.ptr<double>(N / 2 + i);
		string s8 = path + "/8/" + to_string(i) + ".bmp";
		Mat m8 = imread(s8, IMREAD_GRAYSCALE);
		for (int row = 0; row < 28; row++)
		{
			uchar* curr_row = m8.ptr<uchar>(row);
			for (int col = 0; col < 28; col++)
			{
				double pv = *curr_row++;
				*x_row++ = (pv ? -normalizeNumber : 0);
			}
		}
		*x_row = -1;
	}
	//normalize(x, x, 1000, 0);
	//cout << x;
	return true;

}

void getInvert()
{
	//invert(x, xInv, DECOMP_SVD);
	string filename = "D:\\xInv.txt";
	ifstream f(filename.c_str());
	if (f)
	{
		for (int i = 0; i < 785; i++)
		{
			double* wrow = xInv.ptr<double>(i);
			for (int j = 0; j < 8000; j++)
			{
				double temp;
				f >> temp;
				*wrow++ = temp;
			}	
		}
		f.close();
		cout << "保存成功。" << endl;
	}
	else cout << "保存失败。" << endl;
	//cout << xInv;
}

void getW()
{
	/*Mat xt = x.t();
	Mat xx = xt * x;
	cout << xx;
	Mat xxx = Mat::zeros(Size(785, 785), CV_64F);
	invert(xx, xxx);
	cout << xxx;
	Mat xxxx = xxx * xt;*/

	//cout << xxxx;
	w = xInv * b;
	//cout << w;
}

int judgeE()
{
	e = x * w - b;
	int zeroNumber = 0, negNumber = 0;

	for (int i = 0; i < N; i++)
	{
		double* cur_col = e.ptr<double>(i);
		if (*cur_col < 0)negNumber++;
		if ( fabs(*cur_col) < 5.0e-4)zeroNumber++;
		cur_col++;
	}
	cout << negNumber << "  " << zeroNumber << endl;
	if (zeroNumber > N * 0.88)return 1;
	else if (negNumber == N)return -1;
	else return 0;
}

int main(int argc, char** argv)
{
	//cout << getFileNumber("D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages/1/0.bmp");

	for (int i = 0; i < N; i++)
	{
		double* cur_col = b.ptr<double>(i);
		*cur_col++ = 1;
	}

	std::cout << "训练开始。" << endl;

	string trainPath = "D:/Python/Lib/site-packages/tensorflow/examples/tutorials/mnist/MNIST_data_TrainImages";
	if (readImage(trainPath))
	{
		cout << "读入数据完成。" << endl;
	}
	else
	{
		cout << "读取失败。" << endl;
	}
	getInvert();

	bool isRight = false;
	cout << "训练中。。。" << endl;
	while (!isRight)
	{
		getW();
		int eJudge = judgeE();
		if (eJudge == -1)break;
		else if (eJudge == 1)isRight = true;
		else {
			for (int i = 0; i < N; i++)
			{
				double* bcur_row = b.ptr<double>(i);
				double* ecur_row = e.ptr<double>(i);
				*bcur_row = *bcur_row + c * (*ecur_row + fabsf(*ecur_row));
				bcur_row++;
				ecur_row++;
			}
		}
	}
	if (isRight)
	{
		cout << "最后w训练结果" << endl << w;
		//normalize(w, w, 255, 0);
		string filename = "D:\\testW.txt";
		ofstream f(filename.c_str());
		if (f)
		{
			for (int i = 0; i < 785; i++)
			{
				double* wrow = w.ptr<double>(i);
				f << *wrow << endl;
			}
			f.close();
			cout << "保存成功。" << endl;
		}
		else cout << "保存失败。" << endl;
		//cout << "最后b训练结果" << endl << b;
		imwrite("D:/testD.png", b);
	}
	else
	{
		cout << "无解，训练不成功。" << endl;
	}


	return 0;
}

