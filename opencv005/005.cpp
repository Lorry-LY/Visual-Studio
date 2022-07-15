#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic159.jpg", IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("input", cv::WINDOW_AUTOSIZE);
	imshow("input", src);


	int height = src.rows ;
	int weight = src.cols ;
	int dim = src.channels();
	double min_val;
	double max_val;
	Point minloc;
	Point maxloc;
	//最大最小值
	minMaxLoc(src, &min_val, &max_val, &minloc, &maxloc,Mat());
	std::cout << "min:" << min_val << " max:" << max_val << std::endl;
	std::cout << "min:" << minloc << " max:" << maxloc << std::endl;

	/*
	//均值方法
	Scalar s = mean(src, Mat());
	std::cout << "均值：" << s[0] << " " << s[1] << " " << s[2] << std::endl;
	
	//方差方法
	Mat mm, mstd;
	meanStdDev(src, mm, mstd);
	std::cout << "均值：" << mstd.at<double>(0,0) << " " << mstd.at<double>(1, 0) << " " << mstd.at<double>(2, 0) << std::endl;
	*/

	//像素值统计信息
	vector<int >hist(256);
	for (int i = 0; i < 256; i++)
	{
		hist[i] = 0;
	}
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < weight; col++)
		{
			int pv = src.at<uchar>(row, col);
			hist[pv]++;
		}
	}
	

	

	waitKey(0);

	return 0;
}