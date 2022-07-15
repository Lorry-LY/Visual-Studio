#include"perceptron.h"

#define ITERATIONS 30

Mat train_perceptron(Mat& images, Mat& labels)
{
	Mat w = Mat::zeros(Size(images.cols + 1, 1), CV_32F);
	for (int i = 0; i <= images.cols; i++)w.at<float>(0, i) = 1.0;
	const float c = 0.05;
	int number = ITERATIONS;
	cout << "正在训练。。。。" << endl;
	while (number--)
	{
		for (int i = 0; i < images.rows; i++)
		{
			double sum = 0.0;
			int label = labels.at<int>(i, 0);
			int symbol = label == 5 ? 1 : -1;
			for (int j = 0; j < images.cols; j++)
			{
				sum += images.at<float>(i, j) * w.at<float>(0, j) * symbol;
			}
			sum += symbol * w.at<float>(0, images.cols);
			if (sum <= 0)
			{
				for (int j = 0; j < images.cols; j++)
				{
					w.at<float>(0, j) += images.at<float>(i, j) * c * symbol;
				}
				w.at<float>(0, images.cols) += symbol * c;
			}
		}
		//cout << "第" << ITERATIONS - number << "次训练完成。" << endl;
	}
	cout << "训练完成。" << endl;
	return w;
}

float testImage(Mat& images, Mat& labels, Mat& w)
{
	cout << "开始测试。。。" << endl;
	int rightNumber = 0;
	for (int i = 0; i < images.rows; i++)
	{
		double sum = 0.0;
		int label = labels.at<int>(i, 0);
		for (int j = 0; j < images.cols; j++)
		{
			sum += images.at<float>(i, j) * w.at<float>(0, j);
		}
		if(w.cols==images.cols+1)sum += w.at<float>(0, images.cols);
		if (sum <= 0 && label == 8)rightNumber++;
		if (sum > 0 && label == 5)rightNumber++;
	}

	cout << "正确率为：" << rightNumber / (float)(images.rows) << endl;
	return rightNumber / (float)images.rows;
}