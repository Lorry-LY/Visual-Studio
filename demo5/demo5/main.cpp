#include "mnist.h"

using namespace cv;
using namespace std;
using namespace cv::ml;

int main() {
	char trainImageFiltPath[100] = {
		"D:\\work\\mnistRead\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\work\\mnistRead\\text_train.txt";
	
	Mat images = Mat::zeros(60000, 400, CV_8UC1);
	Mat labels = Mat::zeros(60000, 1, CV_8UC1);
	Read_train_image(trainImageFiltPath, 60000, 0, &images);
	Read_txt(fileName, &labels);


	images.convertTo(images, CV_32FC1);
	labels.convertTo(labels, CV_32SC1);

	Ptr<DTrees> DTmodel = DTrees::create();
	DTmodel->setMaxDepth(8);
	DTmodel->setCVFolds(0);

	Ptr<TrainData> trainData = TrainData::create(images, ROW_SAMPLE, labels);
	DTmodel->train(trainData);
	DTmodel->save("DTrees_model.yml");

	Mat result;
	DTmodel->predict(images, result);
	int count = 0;
	for (int row = 0; row < result.rows; row++) {
		int predict = result.at<float>(row, 0);
		if (labels.at<int>(row, 0) == predict) {
			count = count + 1;
		}
	}
	float rate = 1.0 * count / result.rows;
	std::cout << "分类正确性： " << rate << endl;
	
	char testFilePath[100] = "D:/work/mnistRead/mnist_test/mnist_test_%d.png";
	string testFileName = "D:\\work\\mnistRead\\text_test.txt";
	Mat test = Mat::zeros(10000, 400, CV_8UC1);
	Mat testLabels = Mat::zeros(10000, 1, CV_8UC1);
	Read_train_image(testFilePath, 10000, 0, &test);
	Read_txt(testFileName, &testLabels);
	test.convertTo(test, CV_32FC1);
	testLabels.convertTo(testLabels, CV_32SC1);

	Mat result2;
	DTmodel->predict(test, result2);
	int correctNum = 0;
	for (int i = 0; i < result2.rows; i++) {
		int predict = result2.at<float>(i, 0);
		cout << "第" << i << "图像预测结果: " << predict
			<< " 图像真实结果： " << testLabels.at<int>(i, 0) << endl;
		if (predict==testLabels.at<int>(i, 0))
			correctNum++;
	}
	cout << "预测正确数： " << correctNum
		<< "预测正确率： " << 1.0 * correctNum / testLabels.rows << endl;
	
	

	waitKey(0);
	return 0;
}