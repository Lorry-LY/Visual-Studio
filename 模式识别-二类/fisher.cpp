#include "fisher.h"

Mat trainFisher(Mat& images, Mat& labels)
{
	cout << "训练开始。。。。" << endl;

	Mat m = Mat::zeros(images.cols, 1, CV_32F);
	Mat m1 = Mat::zeros(images.cols, 1, CV_32F);
	Mat m2 = Mat::zeros(images.cols, 1, CV_32F);
	Mat s = Mat::zeros(images.cols, images.cols, CV_32F);
	Mat s1 = Mat::zeros(images.cols, images.cols, CV_32F);
	Mat s2 = Mat::zeros(images.cols, images.cols, CV_32F);
	Mat w = Mat::zeros(images.cols, 1, CV_32F);

	for (int i = 0; i < images.rows; i++)
	{
		if (labels.at<int>(i, 0) == 5)
		{
			for (int j = 0; j < images.cols; j++)
			{
				m1.at<float>(j, 0) += images.at<float>(i, j) / (images.rows / 2);
			}
		}
		else
		{
			for (int j = 0; j < images.cols; j++)
			{
				m2.at<float>(j, 0) += images.at<float>(i, j) / (images.rows / 2);
			}
		}
	}

	for (int i = 0; i < images.rows; i++)
	{
		if (labels.at<int>(i, 0) == 5)
		{
			Mat temp = Mat::zeros(m1.size(), CV_32F);
			for (int j = 0; j < images.cols; j++)
			{
				temp.at<float>(j, 0) = images.at<float>(i, j);
			}
			temp -= m1;
			s1 += temp * temp.t();
		}
		else
		{
			Mat temp = Mat::zeros(m2.size(), CV_32F);
			for (int j = 0; j < images.cols; j++)
			{
				temp.at<float>(j, 0) = images.at<float>(i, j);
			}
			temp -= m2;
			s2 += temp * temp.t();
		}
	}

	s = s1 + s2;
	w = s.t() * (m1 - m2);

	cout << "训练完成。" << endl;
	return w.t();
}