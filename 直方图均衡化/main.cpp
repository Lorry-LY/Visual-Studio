#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<map>
using namespace cv;
using namespace std;
Mat equalHist(Mat src);		//均衡化函数
void calculateHist(Mat src, Mat result,int color);		//画直方图


int main(int argc, char** argv)
{
	//读图
	Mat src = imread(argv[0], IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}
	imshow("原图", src);
	
	Mat dst1 = equalHist(src);	//调用均衡化函数
	/*调用OpenCV API*/
	Mat dst2;					
	equalizeHist(src, dst2);

	/*显示图片*/
	imshow("重写均衡化函数", dst1);
	imshow("调用API", dst2);

	/*画直方图*/
	namedWindow("直方图", WINDOW_AUTOSIZE);
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
	//计算直方图
	int histZize = 256;
	Mat hist;
	float range[] = { 0,255 };
	const float* histRanges = { range };
	calcHist(&src, 1, 0, Mat(), hist, 1, &histZize, &histRanges, true, false);

	//画直方图	
	int margin = 50;
	int nm = result.rows - 2 * margin;
	normalize(hist, hist, 0, nm, NORM_MINMAX, -1, Mat());
	float step = 500 / 256.0;
	for (int i = 0; i < 255; i++)
	{
		line(result, Point(step * i, 50 + nm - hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - hist.at<float>(i + 1, 0))), Scalar(color, color, 200), 2, 8, 0);
	}
	imshow("直方图", result);
}


Mat equalHist(Mat src)
{
	Mat dst = Mat::zeros(src.size(), src.type());		//目标图片

	int number[256] = { 0 };		//像素个数
	const int totalNumber = src.rows * src.cols;		//总像素个数
	float pr[256] = { 0.0 };		//像素比例
	float sr[256] = { 0.0 };		//像素和比例
	const int layer = 256 - 1;		//分层数
	map<int, int>maps;				//原像素像目标像素映射
	for (int i = 0; i < src.rows; i++)	//计算像素个数
	{
		for (int j = 0; j < src.cols; j++)
		{
			number[src.at<uchar>(i, j)]++;
		}
	}
	for (int i = 0; i < 256; i++)		//计算像素比例
	{
		pr[i] = ((float)number[i]) / totalNumber;
	}
	float temp = pr[0];
	sr[0] = temp;
	for (int i = 1; i < 256; i++)		//计算像素和比例
	{
		temp += pr[i];
		sr[i] = temp;
	}
	for (int i = 0; i < 256; i++)		//映射
	{
		maps[i] = (int)round(sr[i] * layer);
	}
	for (int i = 0; i < src.rows; i++)		//对目标图片赋值
	{
		for (int j = 0; j < src.cols; j++)
		{
			dst.at<uchar>(i, j) = maps[src.at<uchar>(i, j)];
		}
	}
	return dst;

}

