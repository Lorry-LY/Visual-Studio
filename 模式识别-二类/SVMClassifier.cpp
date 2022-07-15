#include "SVMClassifier.h"

using namespace cv::ml;

Mat train_SVM(Mat& images, Mat& labels, Mat& test, Mat& testLabels)
{
	cout << "训练开始。。。。" << endl;

	// 训练SVM分类器
	//初始化
	Ptr<SVM> svm = SVM::create();
	//多分类
	svm->setType(SVM::C_SVC);
	//kernal选用RBF
	svm->setKernel(SVM::RBF);
	//设置经验值 
	svm->setGamma(0.05);
	svm->setC(100.0);
	//设置终止条件，在这里选择迭代200次
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 200, FLT_EPSILON));

	svm->train(TrainData::create(images, ROW_SAMPLE, labels));

	//cout << "训练结束，正写入xml:" << endl;
	////保存模型
	//svm->save("mnist.xml");

	Mat result;
	svm->predict(images, result);
	int count = 0;
	for (int row = 0; row < result.rows; row++) {
		int predict = result.at<float>(row, 0);
		if (labels.at<int>(row, 0) == predict) {
			count = count + 1;
		}
	}
	float rate = 1.0 * count / result.rows;
	std::cout << "训练结束。"<< endl;
	std::cout << "正在测试。。。。" << endl;

	Mat result2;
	svm->predict(test, result2);
	int correctNum = 0;
	for (int i = 0; i < result2.rows; i++) {
		int predict = result2.at<float>(i, 0);
		if (predict == testLabels.at<int>(i, 0))
			correctNum++;
	}
	cout << "预测正确率： " << 1.0 * correctNum / testLabels.rows << endl;

	return result;
}

