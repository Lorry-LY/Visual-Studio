#include"mnist.h"

#include<string>
#include<fstream>

int main()
{
	char trainImageFiltPath[100] = {
		"D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_train\\mnist_train_%d.png"
	};
	string fileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_train.txt";

	Mat images = Mat::zeros(60000, 784, CV_8UC1);
	Mat labels = Mat::zeros(60000, 1, CV_8UC1);
	Read_train_image(trainImageFiltPath, 60000, 0, &images);
	Read_txt(fileName, &labels);

	ofstream f("D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\text_train.txt", ios::trunc);
	if (f)
	{
		Mat image = Mat::zeros(28, 28, CV_8UC1);
		int number = 0;
		for (int i = 0; i < images.rows; i++)
		{
			int label = labels.at<uchar>(i, 0);
			if (label != 5 && label != 8)continue;
			for (int j = 0; j < images.cols; j++)
			{
				image.at<uchar>(j / 28, j % 28) = images.at<uchar>(i, j);
			}
			string filename = string("D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\mnist_train\\" + to_string(number++) + ".jpg");
			imwrite(filename, image);
			f << label << endl;
		}
		f.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return -1;
	}





	char testFilePath[100] = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\mnist_test\\mnist_test_%d.png";
	string testFileName = "D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistReadAll\\text_test.txt";
	Mat test = Mat::zeros(10000, 784, CV_8UC1);
	Mat testLabels = Mat::zeros(10000, 1, CV_8UC1);
	Read_train_image(testFilePath, 10000, 0, &test);
	Read_txt(testFileName, &testLabels);

	ofstream testf("D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\text_test.txt", ios::trunc);
	if (testf)
	{
		Mat image = Mat::zeros(28, 28, CV_8UC1);
		int number = 0;
		for (int i = 0; i < test.rows; i++)
		{
			int label = testLabels.at<uchar>(i, 0);
			if (label != 5 && label != 8)continue;
			for (int j = 0; j < test.cols; j++)
			{
				image.at<uchar>(j / 28, j % 28) = test.at<uchar>(i, j);
			}
			string filename = string("D:\\MSVC_data\\project\\mnist\\mnistRead\\mnistRead5_8\\mnist_test\\" + to_string(number++) + ".jpg");
			imwrite(filename, image);
			testf << label << endl;
		}
		testf.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
	}

	return 0;
}