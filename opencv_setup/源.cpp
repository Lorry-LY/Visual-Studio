#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<vector>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("lena.bmp", 0);
	imshow("src", src);
	Canny(src, src, 60, 120);
	imshow("canny", src);

	Mat dst;
	vector<Point>P;
	P = breakImage(src, dst, 10);
	imshow("dst", dst);

	int nsize = P.size();
	Mat temp = Mat::zeros(dst.size(), CV_8UC3);
	for (int i = 0; i < nsize; i++)
	{
		circle(temp, P[i], 1, Scalar(0, 255, 255));
	}
	Mat circleadd;
	cvtColor(src, src, COLOR_GRAY2BGR);
	addWeighted(tp, 0.5, src, 0.5, 0, circleadd);

	imshow("circleadd", circleadd);

	waitKey(0);

}

vector<Point> breakImage(Mat& src, Mat& dst, int DisThre)
{
	if (dst.data != src.data) src.copyTo(dst);

	vector<Point> pointxy;
	Point ptPoint;
	Size size = src.size();
	int nSize, dx, dy;
	float distance;

	for (int i = 1; i < size.height - 1; i++)
	{
		uchar* dataPre = dst.ptr<uchar>(i - 1);
		uchar* dataCurr = dst.ptr<uchar>(i);
		uchar* dataNext = dst.ptr<uchar>(i + 1);
		for (int j = 1; j < size.width - 1; j++)
		{
			//  p9 p2 p3    
			//  p8 p1 p4    
			//  p7 p6 p5
			int p1 = dataCurr[j];
			if (p1 != 255) continue;
			int p2 = dataPre[j];
			int p3 = dataPre[j + 1];
			int p4 = dataCurr[j + 1];
			int p5 = dataNext[j + 1];
			int p6 = dataNext[j];
			int p7 = dataNext[j - 1];
			int p8 = dataCurr[j - 1];
			int p9 = dataPre[j - 1];

			if (p1 == 255)
			{
				if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) == 255)
				{
					printf("p1 = 1");
					ptPoint.x = j;
					ptPoint.y = i;
					pointxy.push_back(ptPoint);
					printf("x:%d y:%d\n", j, i);
				}
			}

		}
	}
	nSize = (int)pointxy.size();
	printf("size:%d\n", nSize);
	for (int i = 0; i < nSize - 1; i++)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			dx = pointxy[i].x - pointxy[j].x;
			dy = pointxy[i].y - pointxy[j].y;
			distance = (float)(dx * dx + dy * dy);
			if (distance <= DisThre * DisThre)
			{
				line(dst, pointxy[i], pointxy[j], Scalar(255, 255, 255));
			}
		}
	}
	return pointxy;
}


int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic9.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("Í¼Æ¬¼ÓÔØrÊ§°Ü¡£\n");
		return -1;
	}

	namedWindow("input", cv::WINDOW_AUTOSIZE);
	imshow("input", src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}