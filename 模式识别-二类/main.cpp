
#include"perceptron.h"
#include"LeastSquareError.h"
#include"fisher.h"
#include"SVMClassifier.h"
#include"KNNClassifier.h"
#include"Cluster.h"


#define TRAINNUMBER 11272
#define TESTNUMBER 1866

Mat images = Mat::zeros(TRAINNUMBER, IMAGECOL*IMAGEROW, CV_8UC1);
Mat labels = Mat::zeros(TRAINNUMBER, 1, CV_8UC1);

Mat test = Mat::zeros(TESTNUMBER, IMAGECOL * IMAGEROW, CV_8UC1);
Mat testLabels = Mat::zeros(TESTNUMBER, 1, CV_8UC1);

void init_train()
{
	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\mnist_train\\%d.jpg"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\text_train.txt";

	Read_train_image(trainImageFiltPath, TRAINNUMBER, 0, &images);
	Read_txt(fileName, &labels);
	images.convertTo(images, CV_32FC1, 1 / 255.0);
	labels.convertTo(labels, CV_32SC1);
}

void init_test()
{
	char testFilePath[100] = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\mnist_test\\%d.jpg";
	string testFileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\text_test.txt";

	Read_train_image(testFilePath, TESTNUMBER, 0, &test);
	Read_txt(testFileName, &testLabels);
	test.convertTo(test, CV_32FC1, 1 / 255.0);
	testLabels.convertTo(testLabels, CV_32SC1);
}

void do_PCA(Mat& images)
{
	for (int i = 0; i < images.rows; i++)
	{
		Mat src = Mat::zeros(Size(IMAGECOL, IMAGEROW), CV_32FC1);
		for (int j = 0; j < images.cols; j++)
		{
			src.at<float>(j / IMAGEROW, j % IMAGECOL) = images.at<float>(i, j);
		}
		PCA pca(src, Mat(), CV_PCA_DATA_AS_COL);
		Mat dst = pca.eigenvalues;
		//cout << dst;
		for (int j = 0; j < dst.rows; j++)
		{
			images.at<float>(i, j) = dst.at<float>(j, 0);
		}
	}
	images = images(Rect(0, 0, IMAGECOL, images.rows));
}

void do_LDA(Mat& images,Mat &labels)
{
	LDA lda(images, labels);
	Mat dst = lda.project(images);
	images = dst;
	images = images(Rect(0, 0, dst.cols, dst.rows));
}

int main()
{
	init_train();
	init_test();
	int controller;
	cout << "是否对数据进行PCA或者LDA处理？" << endl;
	cout << "1、不处理		2、LDA		3、PCA" << endl;
	cin >> controller;
	if (controller == 3)
	{
		do_PCA(images);
		do_PCA(test);
	}
	if (controller == 2)
	{
		do_LDA(images,labels);
		do_LDA(test,testLabels);
	}
	cout << "欢迎使用模式识别分类器（小宇版），请选择分类器。" << endl;
	cout << "1、感知器准则		2、最小平方误差准则		3、fisher准则" << endl;
	cout << "4、支持向量机		5、K进邻分类器		        6、聚类分类器" << endl;
	while (cin >> controller)
	{
		Mat w;
		switch (controller)
		{
		case 1:w = train_perceptron(images, labels);
			testImage(test, testLabels, w);
			break;
		case 2:w = train_leastSquareError(images, labels);
			testImage(test, testLabels, w);
			break;
		case 3:w = trainFisher(images, labels);
			testImage(test, testLabels, w);
			break;
		case 4:train_SVM(images, labels, test, testLabels);
			break;
		case 5:train_KNN(images, labels, test, testLabels);
			break;
		case 6:w = train_Cluster(images);
			test_Cluster(test, testLabels);
			break;
		default:
			break;
		}

	}




	return 0;
}