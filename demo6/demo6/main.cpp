#include "mnist.h"

using namespace cv;
using namespace std;
using namespace cv::ml;

int main() {
	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\text_train.txt";

	Mat images = Mat::zeros(60000, 400, CV_8UC1);
	Mat labels = Mat::zeros(60000, 1, CV_8UC1);
	Read_train_image(trainImageFiltPath, 60000, 0, &images);
	Read_txt(fileName, &labels);


	images.convertTo(images, CV_32FC1);
	labels.convertTo(labels, CV_32SC1);

	// ѵ��SVM������
	//��ʼ��
	Ptr<SVM> svm = SVM::create();
	//�����
	svm->setType(SVM::C_SVC);
	//kernalѡ��RBF
	svm->setKernel(SVM::RBF);
	//���þ���ֵ 
	svm->setGamma(0.01);
	svm->setC(10.0);
	//������ֹ������������ѡ�����200��
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 200, FLT_EPSILON));

	svm->train(TrainData::create(images, ROW_SAMPLE, labels));

	cout << "ѵ����������д��xml:" << endl;
	//����ģ��
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
	std::cout << "������ȷ�ԣ� " << rate << endl;

	char testFilePath[100] = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead\\mnist_test\\mnist_test_%d.png";
	string testFileName = "D:\\MSVC_data\\project\\mnist\\text_test.txt";
	Mat test = Mat::zeros(10000, 400, CV_8UC1);
	Mat testLabels = Mat::zeros(10000, 1, CV_8UC1);
	Read_train_image(testFilePath, 10000, 0, &test);
	Read_txt(testFileName, &testLabels);
	test.convertTo(test, CV_32FC1);
	testLabels.convertTo(testLabels, CV_32SC1);

	Mat result2;
	svm->predict(test, result2);
	int correctNum = 0;
	for (int i = 0; i < result2.rows; i++) {
		int predict = result2.at<float>(i, 0);
		cout << "��" << i << "ͼ��Ԥ����: " << predict
			<< " ͼ����ʵ����� " << testLabels.at<int>(i, 0) << endl;
		if (predict == testLabels.at<int>(i, 0))
			correctNum++;
	}
	cout << "Ԥ����ȷ���� " << correctNum
		<< "Ԥ����ȷ�ʣ� " << 1.0 * correctNum / testLabels.rows << endl;



	waitKey(0);
	return 0;
}