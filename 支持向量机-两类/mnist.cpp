#include "mnist.h"

int Read_train_image(char* filepath, int number, int p,int k, Mat* images) {
	//定义相关参数
	/*
		传入参数：
		filepath：文件的路径
		number：要调取的图片数量
		mat：存放图片的mat数组
	*/
	//文件的真实路径
	char filename[100];
	Mat srcImage;
	Mat Onedata;
	for (int i = 1; i <= number; i++)
	{
		//sprintf读入指定路径下的图片序列
		sprintf_s(filename, filepath, i - 1 + p);
		//按照文件名将图片依次读取到数组中
		srcImage = imread(filename, IMREAD_GRAYSCALE);
		if (!srcImage.data)
		{
			cout << "读入图片有误！" << endl;
			return -1;
		}
		resize(srcImage, srcImage, Size(28, 28));
		Onedata = srcImage.reshape(1, 1);
		for (int j = 0; j < images->cols; j++) {
			images->at<uchar>(i - 1 + k, j) = Onedata.at<uchar>(0, j);
		}
	}
	cout << "图像读取成功" << endl;
	return 0;
}

int Read_train_label(int number, int k, int label, Mat* labels) {
	for (int i = 0; i < number; i++) {
		labels->at<uchar>(i + k, 0) = label;
	}

	cout << "标签读取成功" << endl;
	return 0;
}

int Read_txt(string file, Mat* labels) {
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());  //若失败，则输出错误消息，并终止程序运行

	string s;
	int i = 0;
	while (getline(infile, s)) {
		//cout << s[0] << endl;
		int a = (int)s[0];
		labels->at<uchar>(i, 0) = a - 48;
		i++;
	}
	infile.close();
	cout << "标签读取成功" << endl;
	return 0;
}