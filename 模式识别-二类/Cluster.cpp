#include "Cluster.h"


Mat train_Cluster(Mat& images)
{
	cout << "训练开始。。。。" << endl;
	Mat curLabels = Mat::zeros(images.rows, 1, CV_32SC1);
	Mat center5 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
	Mat center8 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
	int centerNumber5 = 0;
	int centerNumber8 = 1;
	for (int i = 0; i < images.cols; i++)center5.at<float>(0, i) = images.at<float>(0, i);
	curLabels.at<int>(0, 0) = 5;
	for (int i = 0; i < images.cols; i++)center8.at<float>(0, i) = images.at<float>(1, i);
	curLabels.at<int>(1, 0) = 8;
	int ALLITER = 10;
	while (ALLITER--)
	{
		for (int i = 0; i < images.rows; i++)
		{
			double distance5 = 0.0;
			double distance8 = 0.0;
			for (int j = 0; j < images.cols; j++)
			{
				distance5 += (images.at<float>(i, j) - center5.at<float>(0, j)) * (images.at<float>(i, j) - center5.at<float>(0, j));
				distance8 += (images.at<float>(i, j) - center8.at<float>(0, j)) * (images.at<float>(i, j) - center8.at<float>(0, j));
			}
			if (distance5 < distance8)curLabels.at<int>(i, 0) = 5;
			else curLabels.at<int>(i, 0) = 8;
		}
		Mat AVG5 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
		Mat AVG8 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
		int number5 = 0;
		int number8 = 0;
		for (int i = 0; i < images.rows; i++)
		{
			if (curLabels.at<int>(i, 0) == 5)
			{
				number5++;
				for (int j = 0; j < images.cols; j++)
				{
					AVG5.at<float>(0, j) += images.at<float>(i, j);
				}
			}
			else {
				number8++;
				for (int j = 0; j < images.cols; j++)
				{
					AVG8.at<float>(0, j) += images.at<float>(i, j);
				}
			}
		}

		for (int j = 0; j < images.cols; j++)
		{
			AVG5.at<float>(0, j) /= number5;
			AVG8.at<float>(0, j) /= number8;
		}

		int k5 = -1;
		int k8 = -1;
		double minDis5 = 100000.0;
		double minDis8 = 100000.0;
		for (int i = 0; i < images.rows; i++)
		{
			if (curLabels.at<int>(i, 0) == 5)
			{
				double distance5 = 0.0;
				for (int j = 0; j < images.cols; j++)
				{
					distance5 += (images.at<float>(i, j) - AVG5.at<float>(0, j)) * (images.at<float>(i, j) - AVG5.at<float>(0, j));
				}
				if (distance5 < minDis5)
				{
					minDis5 = distance5;
					k5 = i;
				}
			}
			else
			{
				double distance8 = 0.0;
				for (int j = 0; j < images.cols; j++)
				{
					distance8 += (images.at<float>(i, j) - AVG8.at<float>(0, j)) * (images.at<float>(i, j) - AVG8.at<float>(0, j));
				}
				if (distance8 < minDis8)
				{
					minDis8 = distance8;
					k8 = i;
				}
			}
		}

		if (centerNumber5 == k5 && centerNumber8 == k8)
		{
			//
			break;
		}
		int centerNumber5 = k5;
		int centerNumber8 = k8;
		for (int i = 0; i < images.cols; i++)center5.at<float>(0, i) = images.at<float>(k5, i);
		curLabels.at<int>(0, 0) = 5;
		for (int i = 0; i < images.cols; i++)center8.at<float>(0, i) = images.at<float>(k8, i);
		curLabels.at<int>(1, 0) = 8;
	}
	Mat result = Mat::zeros(2, IMAGECOL*IMAGEROW, CV_32F);
	for (int j = 0; j < images.cols; j++)
	{
		result.at<float>(0, j) = center5.at<float>(0, j);
		result.at<float>(1, j) = center8.at<float>(0, j);
	}

	cout << "训练完成。" << endl;
	return result;
}

Mat test_Cluster(Mat& test, Mat& testLabels)
{
	cout << "测试开始。。。。" << endl;
	Mat center5 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
	Mat center8 = Mat::zeros(1, IMAGECOL*IMAGEROW, CV_32F);
	for (int i = 0; i < test.cols; i++)center5.at<float>(0, i) = test.at<float>(0, i);
	for (int i = 0; i < test.cols; i++)center8.at<float>(0, i) = test.at<float>(1, i);
	int rightNumber = 0;
	for (int i = 0; i < test.rows; i++)
	{
		int label = testLabels.at<int>(i, 0);
		double distance5 = 0.0;
		double distance8 = 0.0;
		for (int j = 0; j < test.cols; j++)
		{
			distance5 += (test.at<float>(i, j) - center5.at<float>(0, j)) * (test.at<float>(i, j) - center5.at<float>(0, j));
			distance8 += (test.at<float>(i, j) - center8.at<float>(0, j)) * (test.at<float>(i, j) - center8.at<float>(0, j));
		}
		if (distance5 < distance8 && label == 5)rightNumber++;
		if (distance5 >= distance8 && label == 8)rightNumber++;
	}
	cout << "测试完成。" << endl;

	cout << "正确率为：" << 1.0 * rightNumber / test.rows << endl;
	return Mat();
}