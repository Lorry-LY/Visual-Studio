
#include"mnist.h"
//#include"perceptron.h"
#include"SVMClassifier.h"
#include"KNNClassifier.h"
#include"Cluster.h"

#define TRAINNUMBER 60000
#define TESTNUMBER 10000

Mat images = Mat::zeros(TRAINNUMBER, 784, CV_8UC1);
Mat labels = Mat::zeros(TRAINNUMBER, 1, CV_8UC1);

Mat test = Mat::zeros(TESTNUMBER, 784, CV_8UC1);
Mat testLabels = Mat::zeros(TESTNUMBER, 1, CV_8UC1);

void init_train()
{
	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_train.txt";

	Read_train_image(trainImageFiltPath, TRAINNUMBER, 0, &images);
	Read_txt(fileName, &labels);
	images.convertTo(images, CV_32FC1, 1 / 255.0);
	labels.convertTo(labels, CV_32SC1);
}

void init_test()
{
	char testFilePath[100] = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_test\\mnist_test_%d.png";
	string testFileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_test.txt";

	Read_train_image(testFilePath, TESTNUMBER, 0, &test);
	Read_txt(testFileName, &testLabels);
	test.convertTo(test, CV_32FC1, 1 / 255.0);
	testLabels.convertTo(testLabels, CV_32SC1);
}

int main()
{
	init_train();
	init_test();
	cout << "欢迎使用模式识别分类器（小宇版），请选择分类器。" << endl;
	cout << "1、感知器准则		2、支持向量机		    3、K近邻分类器		4、聚类分析" << endl;
	int controller;
	while (cin >> controller)
	{
		Mat w;
		switch (controller)
		{
		case 1://w = train_perceptron(images, labels);
			break;
		case 2:train_SVM(images, labels, test, testLabels);
			break;
		case 3:train_KNN(images, labels, test, testLabels);
			break;
		case 4:w = train_Cluster(images);
			test_Cluster(test, testLabels, w);
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}

	}




	return 0;
}