#include "mnist.h"

using namespace cv;
using namespace std;
using namespace cv::ml;

int main() {
	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\text_train.txt";

	Mat images = Mat::zeros(60000, 400, CV_8UC1);
	Mat labels = Mat::zeros(60000, 1, CV_8UC1);
	Read_train_image(trainImageFiltPath, 60000, 0, &images);
	Read_txt(fileName, &labels);


	images.convertTo(images, CV_32FC1, 1 / 255.0);
	labels.convertTo(labels, CV_32SC1);

	// 训练SVM分类器
	//初始化
	Ptr<SVM> svm = SVM::create();
	//多分类
	svm->setType(SVM::C_SVC);
	//kernal选用RBF
	svm->setKernel(SVM::RBF);
	//设置经验值 
	svm->setGamma(0.03);
	svm->setC(100.0);
	//设置终止条件，在这里选择迭代200次
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 200, FLT_EPSILON));

	svm->train(TrainData::create(images, ROW_SAMPLE, labels));

	cout << "训练结束，正写入xml:" << endl;
	//保存模型
	svm->save("mnist.xml");

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
	std::cout << "分类正确性： " << rate << endl;

	char testFilePath[100] = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\mnist_test\\mnist_test_%d.png";
	string testFileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\text_test.txt";
	Mat test = Mat::zeros(10000, 400, CV_8UC1);
	Mat testLabels = Mat::zeros(10000, 1, CV_8UC1);
	Read_train_image(testFilePath, 10000, 0, &test);
	Read_txt(testFileName, &testLabels);
	test.convertTo(test, CV_32FC1, 1 / 255.0);
	testLabels.convertTo(testLabels, CV_32SC1);

	Mat result2;
	svm->predict(test, result2);
	int correctNum = 0;
	for (int i = 0; i < result2.rows; i++) {
		int predict = result2.at<float>(i, 0);
		cout << "第" << i << "图像预测结果: " << predict
			<< " 图像真实结果： " << testLabels.at<int>(i, 0) << endl;
		if (predict == testLabels.at<int>(i, 0))
			correctNum++;
	}
	cout << "预测正确数： " << correctNum
		<< "预测正确率： " << 1.0 * correctNum / testLabels.rows << endl;



	waitKey(0);
	return 0;
}