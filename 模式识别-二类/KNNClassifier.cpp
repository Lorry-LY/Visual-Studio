#include "KNNClassifier.h"

#include<vector>
#define MAXKNUMBER 20

Mat train_KNN(Mat& images, Mat& labels, Mat& test, Mat& testLabels)
{
	cout << "开始测试。。。" << endl;
	int rightNumber = 0;
	typedef pair<int, double>PII;
	vector<PII>vec;
	for (int i = 0; i < test.rows; i++)
	{
		for (int k = 0; k < MAXKNUMBER; k++)
		{
			double sum = 0.0;
			int label = labels.at<int>(k, 0);
			for (int j = 0; j < images.cols; j++)
			{
				sum += (test.at<float>(i, j) - images.at<float>(k, j)) * (test.at<float>(i, j) - images.at<float>(k, j));
			}
			vec.push_back({ label,sum });
			sort(vec.begin(), vec.end());
		}
		int cur_label = testLabels.at<int>(i, 0);
		for (int k = MAXKNUMBER; k < images.rows; k++)
		{
			double sum = 0.0;
			int label = labels.at<int>(k, 0);
			for (int j = 0; j < images.cols; j++)
			{
				sum += (test.at<float>(i, j) - images.at<float>(k, j)) * (test.at<float>(i, j) - images.at<float>(k, j));
			}
			vector<PII>::iterator it;
			for (it = vec.begin(); it < vec.end(); it++)
			{
				PII node = *it;
				if (node.second > sum)
				{
					PII temp = { label,sum };
					vec.insert(it, temp);
					vec.pop_back();
					break;
				}
			}
		}
		int number = 0;
		vector<PII>::iterator it;
		for (it = vec.begin(); it < vec.end(); it++)
		{
			PII node = *it;
			if (node.first == cur_label)number++;
		}
		if (number > MAXKNUMBER / 2)rightNumber++;
		//cout << "第" << i << "张图片测试完成。" << endl;
		vec.clear();
	}

	cout << "正确率为：" << rightNumber / (float)(images.rows) << endl;
	return Mat();

}