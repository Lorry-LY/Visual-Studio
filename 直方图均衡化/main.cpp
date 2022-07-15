#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<map>
using namespace cv;
using namespace std;
Mat equalHist(Mat src);		//���⻯����
void calculateHist(Mat src, Mat result,int color);		//��ֱ��ͼ


int main(int argc, char** argv)
{
	//��ͼ
	Mat src = imread(argv[0], IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("ͼƬ����rʧ�ܡ�\n");
		return -1;
	}
	imshow("ԭͼ", src);
	
	Mat dst1 = equalHist(src);	//���þ��⻯����
	/*����OpenCV API*/
	Mat dst2;					
	equalizeHist(src, dst2);

	/*��ʾͼƬ*/
	imshow("��д���⻯����", dst1);
	imshow("����API", dst2);

	/*��ֱ��ͼ*/
	namedWindow("ֱ��ͼ", WINDOW_AUTOSIZE);
	Mat result = Mat::zeros(Size(600, 400), CV_8UC3);
	calculateHist(src, result, 0);
	calculateHist(dst1, result, 70);
	calculateHist(dst2, result, 140);


	waitKey(0);
	destroyAllWindows();

	return 0;
}

void calculateHist(Mat src,Mat result,int color)
{
	//����ֱ��ͼ
	int histZize = 256;
	Mat hist;
	float range[] = { 0,255 };
	const float* histRanges = { range };
	calcHist(&src, 1, 0, Mat(), hist, 1, &histZize, &histRanges, true, false);

	//��ֱ��ͼ	
	int margin = 50;
	int nm = result.rows - 2 * margin;
	normalize(hist, hist, 0, nm, NORM_MINMAX, -1, Mat());
	float step = 500 / 256.0;
	for (int i = 0; i < 255; i++)
	{
		line(result, Point(step * i, 50 + nm - hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - hist.at<float>(i + 1, 0))), Scalar(color, color, 200), 2, 8, 0);
	}
	imshow("ֱ��ͼ", result);
}


Mat equalHist(Mat src)
{
	Mat dst = Mat::zeros(src.size(), src.type());		//Ŀ��ͼƬ

	int number[256] = { 0 };		//���ظ���
	const int totalNumber = src.rows * src.cols;		//�����ظ���
	float pr[256] = { 0.0 };		//���ر���
	float sr[256] = { 0.0 };		//���غͱ���
	const int layer = 256 - 1;		//�ֲ���
	map<int, int>maps;				//ԭ������Ŀ������ӳ��
	for (int i = 0; i < src.rows; i++)	//�������ظ���
	{
		for (int j = 0; j < src.cols; j++)
		{
			number[src.at<uchar>(i, j)]++;
		}
	}
	for (int i = 0; i < 256; i++)		//�������ر���
	{
		pr[i] = ((float)number[i]) / totalNumber;
	}
	float temp = pr[0];
	sr[0] = temp;
	for (int i = 1; i < 256; i++)		//�������غͱ���
	{
		temp += pr[i];
		sr[i] = temp;
	}
	for (int i = 0; i < 256; i++)		//ӳ��
	{
		maps[i] = (int)round(sr[i] * layer);
	}
	for (int i = 0; i < src.rows; i++)		//��Ŀ��ͼƬ��ֵ
	{
		for (int j = 0; j < src.cols; j++)
		{
			dst.at<uchar>(i, j) = maps[src.at<uchar>(i, j)];
		}
	}
	return dst;

}

