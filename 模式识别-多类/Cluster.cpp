#include "Cluster.h"


Mat train_Cluster(Mat& images)
{
	cout << "训练开始。。。。" << endl;
	Mat curLabels = Mat::zeros(images.rows, 1, CV_32SC1);
	Mat center = Mat::zeros(10, images.cols, CV_32F);
	Mat centerLabel = Mat::zeros(10, 1, CV_32SC1);
	for (int j = 0; j < center.rows; j++)
	{
		centerLabel.at<int>(j, 0) = j;
		for (int i = 0; i < images.cols; i++)
		{
			center.at<float>(j, i) = images.at<float>(j, i);
		}
	}
	int ALLITER = 10;
	while (ALLITER--)
	{
		for (int i = 0; i < images.rows; i++)
		{
			Mat distance = Mat::zeros(10, 1, CV_32F);
			for (int k = 0; k < distance.rows; k++)
			{
				for (int j = 0; j < images.cols; j++)
				{
					distance.at<float>(k, 0) += (images.at<float>(i, j) - center.at<float>(k, j)) * (images.at<float>(i, j) - center.at<float>(k, j));
				}
			}
			float dis = 10000.0;
			int klabel = -1;
			for (int k = 0; k < distance.rows; k++)
			{
				if (distance.at<float>(k, 0) < dis)
				{
					dis = distance.at<float>(k, 0);
					klabel = k;
				}
			}
			curLabels.at<int>(i, 0) = klabel;
		}
		Mat AVG = Mat::zeros(10, 784, CV_32F);
		Mat AVGNumber = Mat::zeros(10, 1, CV_32SC1);
		for (int i = 0; i < images.rows; i++)
		{
			AVGNumber.at<int>(curLabels.at<int>(i, 0), 0)++;
			for (int j = 0; j < images.cols; j++)
			{
				AVG.at<float>(curLabels.at<int>(i, 0), j) += images.at<float>(i, j);
			}
		}

		for (int k = 0; k < AVG.rows; k++)
		{
			//cout << AVGNumber.at<int>(k, 0) << endl;
			for (int j = 0; j < images.cols; j++)
			{
				AVG.at<float>(k, j) /= AVGNumber.at<int>(k, 0);
			}
		}
		Mat kNumber = Mat::zeros(10, 1, CV_32SC1);
		Mat minDis = Mat::zeros(10, 1, CV_32F);
		//数据初始化
		for (int j = 0; j < kNumber.rows; j++)
		{
			kNumber.at<int>(j, 0) = -1;
			minDis.at<float>(j, 0) = 10000.0;
		}

		for (int i = 0; i < images.rows; i++)
		{
			double distance = 0.0;
			for (int j = 0; j < images.cols; j++)
			{
				distance += (images.at<float>(i, j) - AVG.at<float>(curLabels.at<int>(i, 0), j)) * (images.at<float>(i, j) - AVG.at<float>(curLabels.at<int>(i, 0), j));
			}
			//cout << minDis.at<float>(curLabels.at<int>(i, 0), 0) << " " << curLabels.at<int>(i, 0) << endl;
			if (distance < minDis.at<float>(curLabels.at<int>(i, 0), 0))
			{
				minDis.at<float>(curLabels.at<int>(i, 0), 0) = distance;
				kNumber.at<int>(curLabels.at<int>(i, 0), 0) = i;
			}
		}
		int centerNumberRight = 0;
		for (int j = 0; j < centerLabel.rows; j++)
		{
			if (centerLabel.at<int>(j, 0) == kNumber.at<int>(j, 0))centerNumberRight++;
		}

		for (int j = 0; j < center.rows; j++)
		{
			//cout << kNumber.at<int>(j, 0) << " ";
			centerLabel.at<int>(j, 0) = kNumber.at<int>(j, 0);
			for (int k = 0; k < center.cols; k++)
			{
				center.at<float>(j, k) = images.at<float>(centerLabel.at<int>(j, 0), k);
			}
		}

		if (centerNumberRight == 10)
		{
			break;
		}


	}


	Mat result = Mat::zeros(10, 784, CV_32F);
	for (int j = 0; j < images.cols; j++)
	{
		for (int k = 0; k < center.rows; k++)
		{
			result.at<float>(k, j) = center.at<float>(k, j);
		}
	}

	cout << "训练完成。" << endl;
	return result;
}

Mat test_Cluster(Mat& test, Mat& testLabels, Mat& result)
{
	cout << "测试开始。。。。" << endl;
	Mat center = Mat::zeros(10, 784, CV_32F);
	for (int j = 0; j < test.cols; j++)
	{
		for (int k = 0; k < center.rows; k++)
		{
			center.at<float>(k, j) = result.at<float>(k, j);
		}
	}
	int rightNumber = 0;
	for (int i = 0; i < test.rows; i++)
	{
		int label = testLabels.at<int>(i, 0);
		Mat distance = Mat::zeros(10, 1, CV_32F);
		for (int k = 0; k < distance.rows; k++)
		{
			for (int j = 0; j < test.cols; j++)
			{
				distance.at<float>(k, 0) += (test.at<float>(i, j) - center.at<float>(k, j)) * (test.at<float>(i, j) - center.at<float>(k, j));
			}
		}
		float dis = 10000.0;
		int klabel = -1;
		for (int k = 0; k < distance.rows; k++)
		{
			if (distance.at<float>(k, 0) < dis)
			{
				dis = distance.at<float>(k, 0);
				klabel = k;
			}
		}
		if (klabel == label)rightNumber++;

	}
	cout << "测试完成。" << endl;

	cout << "正确率为：" << 1.0 * rightNumber / test.rows << endl;
	return Mat();
}