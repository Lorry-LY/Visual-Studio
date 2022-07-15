#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic4.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_NORMAL);
	imshow("test opencv setup", src);
	
	//通道分离
	vector<Mat>mv;
	split(src, mv);
	int size = mv.size();
	cout << size << endl;
	imshow("blue", mv[0]);
	imshow("green", mv[1]);
	imshow("red", mv[2]);
	mv[2] = Scalar(0);

	//通道合并
	Mat dest;
	merge(mv, dest);
	imshow("dest", dest);

	//ROI
	Rect roi;
	roi.x = 100;
	roi.y = 100;
	roi.width = 200;
	roi.height = 200;
	Mat sub = src(roi).clone();
	imshow("roi", sub);


	waitKey(0);
	destroyAllWindows();

	return 0;
}