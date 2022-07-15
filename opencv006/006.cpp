#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;

int main(int argc, char** argv)
{
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
	if (canvas.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("input", cv::WINDOW_AUTOSIZE);
	imshow("input", canvas);

	//绘制线路
	line(canvas, Point(10, 10), Point(400, 400), Scalar(0, 255, 255), 5, LINE_8);
	imshow("line", canvas);

	Rect rect(100, 100, 200, 200);
	rectangle(canvas, rect, Scalar(255, 255, 0), 2, LINE_4);
	imshow("retangle", canvas);

	putText(canvas, "hello opencv", Point(100, 50), FONT_HERSHEY_SIMPLEX, 2.0,Scalar(0,255,0), 2, 8);

	circle(canvas, Point(200, 200), 50, Scalar(240, 253, 0), 2, LINE_8);
	imshow("circle", canvas);
	RotatedRect rrt;
	rrt.center = Point(256, 256);
	rrt.size = Size(100, 200);
	rrt.angle = CV_PI / 4;
	ellipse(canvas, rrt, Scalar(0, 0, 255), 2, 8);
	imshow("rrt", canvas);

	Mat image = Mat::zeros(Size(512, 512), CV_8UC3);
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	RNG rng(12345);
	while (true)
	{
		x1 = (int)rng.uniform(0, 512);
		y1 = (int)rng.uniform(0, 512);
		x2 = (int)rng.uniform(0, 512);
		y2 = (int)rng.uniform(0, 512);
		image = Scalar(0, 0, 0);
		rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 1, 8);
		imshow("image", image);
		char c = waitKey(100);
		if (c == 27)
		{
			break;
		}
	}

	waitKey(0);
	destroyAllWindows();
	return 0;
}