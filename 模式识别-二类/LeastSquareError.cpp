#include "LeastSquareError.h"

#define ITERATION 100

int judgeE(Mat& e, Mat& x, Mat& w, Mat& b)
{
	e = x * w - b;
	int zeroNumber = 0, negNumber = 0;

	for (int i = 0; i < e.rows; i++)
	{
		float cur_row = e.at<float>(i, 0);
		if (cur_row < 0)negNumber++;
		if (fabs(cur_row) < 5.0e-6)zeroNumber++;
	}
	//cout << negNumber << "  " << zeroNumber << endl;
	if (zeroNumber > x.rows * 0.001)return 1;
	else if (negNumber == x.rows)return -1;
	else return 0;
}



Mat train_leastSquareError(Mat& images, Mat& labels)
{
	Mat w = Mat::zeros(images.cols, 1, CV_32F);
	Mat b = Mat::zeros(images.rows, 1, CV_32F);
	Mat e = Mat::zeros(images.rows, 1, CV_32F);
	for (int i = 0; i < images.rows; i++)b.at<float>(i, 0) = 1.0;
	const float c = 0.05;

	cout << "正在训练。。。。" << endl;
	for (int i = 0; i < images.rows; i++)
	{
		if (labels.at<int>(i, 0) == 8)
		{
			for (int j = 0; j < images.cols; j++)
			{
				images.at<float>(i, j) *= -1;
			}
		}
	}
	Mat inv = Mat::zeros(images.cols, images.rows, CV_32F);
	invert(images, inv, DECOMP_SVD);

	bool isRight = false;
	int iteration = 0;
	while (!isRight)
	{
		if (iteration == ITERATION)
		{
			isRight = true;
		}
		w = inv * b;
		int eJudge = judgeE(e, images, w, b);
		if (eJudge == -1)break;
		else if (eJudge == 1)isRight = true;
		else {
			for (int i = 0; i < images.rows; i++)
			{
				b.at<float>(i, 0) +=c * (e.at<float>(i, 0) + fabsf(e.at<float>(i, 0)));
			}
		}
		iteration++;
	}
	if (isRight)
	{
		cout << "训练完成。" << endl;
		return w.t();
	}
	else
	{
		cout << "训练完成。无解！" << endl;
		return Mat::zeros(w.cols, w.rows, CV_32F);
	}
	
}

