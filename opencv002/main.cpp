#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic4.jpg",IMREAD_COLOR);
	if (src.empty())
	{
		printf("Õº∆¨º”‘ÿr ß∞‹°£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_NORMAL);
	imshow("test opencv setup", src);
	int height = src.rows;
	int weight = src.cols;
	int dim = src.channels();
	int d = src.depth();
	int t = src.type();
	printf("height is %d,weight is %d,channel is %d\n", height, weight, dim);
	cout << d << "  " << t << endl;

	/*create Mat*/
	//one
	Mat t1 = Mat(256, 256, CV_8UC1);
	t1 = Scalar(255);
	imshow("t1", t1);

	//two
	Mat t2 = Mat(Size(512, 512), CV_8UC3);
	t2 = Scalar(20, 20, 87);
	imshow("t2", t2);

	//three
	Mat t3 = Mat::zeros(Size(256, 256), CV_8UC3);
	imshow("t3", t3);

	//from source
	Mat t4 = src;
	//t4 = Scalar(20, 20, 87);
	Mat t5 = src.clone();
	t5 = Scalar(20, 20, 87);

	imshow("t4", t4);
	imshow("t5", t5);

	Mat t6 = Mat::zeros(src.size(), src.type());
	imshow("t6", t6);


	//visit each pixel
	/*for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < weight; col++)
		{
			if (dim == 3)
			{
				Vec3b pixel = src.at<Vec3b>(row, col);
				int blue = pixel[0];
				int green = pixel[1];
				int red = pixel[2];
				src.at<Vec3b>(row, col)[0] = 255 - blue;
				src.at<Vec3b>(row, col)[1] = 255 - green;
				src.at<Vec3b>(row, col)[2] = 255 - red;
			}
			if (dim == 1)
			{
				int pv = src.at<uchar>(row, col);
				src.at<uchar>(row, col) = 255 - pv;
			}
		}
	}*/

	Mat result = Mat::zeros(src.size(), src.type());
	for (int row = 0; row < height; row++)
	{
		uchar* curr_row = src.ptr<uchar>(row);
		uchar* result_row = result.ptr<uchar>(row);
		for (int col = 0; col < weight; col++)
		{
			if (dim == 3)
			{
				int blue=*curr_row++;
				int green=*curr_row++;
				int red=*curr_row++;
				*result_row++ = blue > 200 ? 255 : blue + 50;
				*result_row++ = green > 200 ? 255 : green + 50;
				*result_row++ = red > 200 ? 255 : red + 50;
			}
			if (dim == 1)
			{
				int pv = *curr_row++;
				*result_row++ = pv;
			}
		}
	}

	imshow("pixel", src);
	imshow("result", result);

	imwrite("D:/test.png", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}