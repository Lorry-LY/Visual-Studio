#include "mnist.h"

int Read_train_image(char* filepath, int number, int p,int k, Mat* images) {
	//������ز���
	/*
		���������
		filepath���ļ���·��
		number��Ҫ��ȡ��ͼƬ����
		mat�����ͼƬ��mat����
	*/
	//�ļ�����ʵ·��
	char filename[100];
	Mat srcImage;
	Mat Onedata;
	for (int i = 1; i <= number; i++)
	{
		//sprintf����ָ��·���µ�ͼƬ����
		sprintf_s(filename, filepath, i - 1 + p);
		//�����ļ�����ͼƬ���ζ�ȡ��������
		srcImage = imread(filename, IMREAD_GRAYSCALE);
		if (!srcImage.data)
		{
			cout << "����ͼƬ����" << endl;
			return -1;
		}
		resize(srcImage, srcImage, Size(28, 28));
		Onedata = srcImage.reshape(1, 1);
		for (int j = 0; j < images->cols; j++) {
			images->at<uchar>(i - 1 + k, j) = Onedata.at<uchar>(0, j);
		}
	}
	cout << "ͼ���ȡ�ɹ�" << endl;
	return 0;
}

int Read_train_label(int number, int k, int label, Mat* labels) {
	for (int i = 0; i < number; i++) {
		labels->at<uchar>(i + k, 0) = label;
	}

	cout << "��ǩ��ȡ�ɹ�" << endl;
	return 0;
}

int Read_txt(string file, Mat* labels) {
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());  //��ʧ�ܣ������������Ϣ������ֹ��������

	string s;
	int i = 0;
	while (getline(infile, s)) {
		//cout << s[0] << endl;
		int a = (int)s[0];
		labels->at<uchar>(i, 0) = a - 48;
		i++;
	}
	infile.close();
	cout << "��ǩ��ȡ�ɹ�" << endl;
	return 0;
}