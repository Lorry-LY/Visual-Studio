#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic8.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("Í¼Æ¬¼ÓÔØrÊ§°Ü¡£\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	int height = src.rows;
	int width = src.cols;
	Mat result = Mat::zeros(src.size(), CV_8UC3);
	for (int row = 1; row < height-1; row++)
	{
		for (int col = 1; col < width-1; col++)
		{
			//3*3µÄ¾í»ýºË;
			int sb = src.at<Vec3b>(row, col)[0] + src.at<Vec3b>(row - 1, col - 1)[0] + src.at<Vec3b>(row - 1, col)[0] + src.at<Vec3b>(row - 1, col + 1)[0] + src.at<Vec3b>(row, col - 1)[0] + src.at<Vec3b>(row - 1, col + 1)[0] + src.at<Vec3b>(row + 1, col - 1)[0] + src.at<Vec3b>(row + 1, col + 1)[0] + src.at<Vec3b>(row + 1, col)[0];
			int sg = src.at<Vec3b>(row, col)[1] + src.at<Vec3b>(row - 1, col - 1)[1] + src.at<Vec3b>(row - 1, col)[1] + src.at<Vec3b>(row - 1, col + 1)[1] + src.at<Vec3b>(row, col - 1)[1] + src.at<Vec3b>(row - 1, col + 1)[1] + src.at<Vec3b>(row + 1, col - 1)[1] + src.at<Vec3b>(row + 1, col + 1)[1] + src.at<Vec3b>(row + 1, col)[1];
			int sr = src.at<Vec3b>(row, col)[2] + src.at<Vec3b>(row - 1, col - 1)[2] + src.at<Vec3b>(row - 1, col)[2] + src.at<Vec3b>(row - 1, col + 1)[2] + src.at<Vec3b>(row, col - 1)[2] + src.at<Vec3b>(row - 1, col + 1)[2] + src.at<Vec3b>(row + 1, col - 1)[2] + src.at<Vec3b>(row + 1, col + 1)[2] + src.at<Vec3b>(row + 1, col)[2];
			result.at<Vec3b>(row, col)[0] = sb / 9;
			result.at<Vec3b>(row, col)[1] = sg / 9;
			result.at<Vec3b>(row, col)[2] = sr / 9;
		}
	}
	imshow("¾í»ý", result);

	//API
	Mat dst = Mat::zeros(src.size(), CV_8UC3);
	blur(src, dst, Size(4, 4), Point(-1, -1), BORDER_DEFAULT);
	imshow("blur", dst);



	waitKey(0);
	destroyAllWindows();

	return 0;
}