#include "SVMClassifier.h"

using namespace cv::ml;

Mat train_SVM(Mat& images, Mat& labels, Mat& test, Mat& testLabels)
{
	cout << "ѵ����ʼ��������" << endl;

	// ѵ��SVM������
	//��ʼ��
	Ptr<SVM> svm = SVM::create();
	//�����
	svm->setType(SVM::C_SVC);
	//kernalѡ��RBF
	svm->setKernel(SVM::RBF);
	//���þ���ֵ 
	svm->setGamma(0.05);
	svm->setC(100.0);
	//������ֹ������������ѡ�����200��
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 200, FLT_EPSILON));

	svm->train(TrainData::create(images, ROW_SAMPLE, labels));

	//cout << "ѵ����������д��xml:" << endl;
	////����ģ��
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
	std::cout << "ѵ��������"<< endl;
	std::cout << "���ڲ��ԡ�������" << endl;

	Mat result2;
	svm->predict(test, result2);
	int correctNum = 0;
	for (int i = 0; i < result2.rows; i++) {
		int predict = result2.at<float>(i, 0);
		if (predict == testLabels.at<int>(i, 0))
			correctNum++;
	}
	cout << "Ԥ����ȷ�ʣ� " << 1.0 * correctNum / testLabels.rows << endl;

	return result;
}

