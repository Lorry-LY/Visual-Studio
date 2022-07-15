#include<opencv2/opencv.hpp>
#include<iostream>
#include<highgui/highgui.hpp>
#include<highgui/highgui_c.h>
using namespace cv;
using namespace std;

void hist_compare()
{
	Mat src1 = imread("C:/Users/87419/Desktop/Pa/pic3.jpg", IMREAD_COLOR);
	Mat src2 = imread("C:/Users/87419/Desktop/Pa/pic4.jpg", IMREAD_COLOR);
	imshow("src1", src1);
	imshow("src2", src2);

	//计算直方图
	int histZize[] = { 256,256,256 };
	Mat hist1, hist2;
	float range1[] = { 0,255 };
	float range2[] = { 0,255 };
	float range3[] = { 0,255 };
	int channels[] = { 0,1,2 };
	const float* histRanges[] = { range1,range2,range3 };
	calcHist(&src1, 1, channels, Mat(), hist1, 3, histZize, histRanges, true, false);
	calcHist(&src2, 1, channels, Mat(), hist2, 3, histZize, histRanges, true, false);
	
	//归一化
	normalize(hist1, hist1, 0, 1.0, NORM_MINMAX, -1, Mat());
	normalize(hist2, hist2, 0, 1.0, NORM_MINMAX, -1, Mat());

	//巴氏距离比较
	double h12= compareHist(hist1, hist2, HISTCMP_BHATTACHARYYA);
	double h11 = compareHist(hist1, hist1, HISTCMP_BHATTACHARYYA);

	//相关性比较
	double c12 = compareHist(hist1, hist2, HISTCMP_CORREL);
	double c11 = compareHist(hist1, hist1, HISTCMP_CORREL);

	cout << h12 << " " << h11 << endl;
	cout << c12 << " " << c11 << endl;

}



//int main()
//{
//	hist_compare();
//	//Mat src = imread("C:/Users/87419/Desktop/Pa/pic2.jpg", IMREAD_COLOR);
//	//if (src.empty())
//	//{
//	//	printf("图片加载r失败。\n");
//	//	return -1;
//	//}
//
//	//namedWindow("test opencv setup", cv::WINDOW_NORMAL);
//	//imshow("test opencv setup", src);
//
//	//Mat gray, dst;
//	//cvtColor(src, gray, COLOR_BGR2GRAY);
//	//imshow("gray", gray);
//	//equalizeHist(gray, dst);
//	//imshow("dst", dst);
//
//	//
//
//	////计算直方图
//	//int histZize = 256;
//	//Mat b_hist, g_hist, r_hist;
//	//float range[] = { 0,255 };
//	//const float* histRanges = { range };
//	//calcHist(&gray, 1, 0, Mat(), b_hist, 1, &histZize, &histRanges, true, false);
//	//calcHist(&dst, 1, 0, Mat(), g_hist, 1, &histZize, &histRanges, true, false);
//
//	//Mat result = Mat::zeros(Size(600, 400), CV_8UC3);
//	//int margin = 50;
//	//int nm = result.rows - 2 * margin;
//	//normalize(b_hist, b_hist, 0, nm, NORM_MINMAX, -1, Mat());
//	//normalize(g_hist, g_hist, 0, nm, NORM_MINMAX, -1, Mat());
//	//normalize(r_hist, r_hist, 0, nm, NORM_MINMAX, -1, Mat());
//
//	//float step = 500 / 256.0;
//	//for (int i = 0; i < 255; i++)
//	//{
//
//	//	line(result, Point(step * i, 50 + nm - b_hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - b_hist.at<float>(i + 1, 0))), Scalar(255, 0, 0), 2, 8, 0);
//	//	line(result, Point(step * i, 50 + nm - g_hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - g_hist.at<float>(i + 1, 0))), Scalar(0, 255, 0), 2, 8, 0);
//	//}
//
//	//imshow("result", result);
//
//	
//
//
//	waitKey(0);
//	destroyAllWindows();
//
//	return 0;
//
//	
//}


int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/87419/Desktop/Pa/pic14.jpg", IMREAD_COLOR);
	if (src.empty())
	{
		printf("图片加载r失败。\n");
		return -1;
	}

	namedWindow("test opencv setup", cv::WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	vector<Mat>mv;
	split(src, mv);

	//计算直方图
	int histZize = 256;
	Mat b_hist, g_hist, r_hist;
	float range[] = { 0,255 };
	const float* histRanges = { range };
	calcHist(&mv[0], 1, 0, Mat(), b_hist, 1, &histZize, &histRanges, true, false);
	calcHist(&mv[1], 1, 0, Mat(), g_hist, 1, &histZize, &histRanges, true, false);
	calcHist(&mv[2], 1, 0, Mat(), r_hist, 1, &histZize, &histRanges, true, false);
	imshow("mv0", mv[0]);
	imshow("mv1", mv[1]);
	imshow("mv2,", mv[2]);

	Mat temp = Mat::zeros(src.size(), 0);
	temp = mv[0].clone();
	mv[0] = mv[2].clone();
	mv[2] = temp.clone();
	Mat dest;
	merge(mv, dest);
	imshow("dest", dest);

	Mat result = Mat::zeros(Size(600, 400), CV_8UC3);
	int margin = 50;
	int nm = result.rows - 2 * margin;
	normalize(b_hist, b_hist, 0, nm, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, nm, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, nm, NORM_MINMAX, -1, Mat());

	float step = 500 / 256.0;
	for (int i = 0; i < 255; i++)
	{
		
		line(result, Point(step * i, 50 + nm - b_hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - b_hist.at<float>(i + 1, 0))), Scalar(255, 0, 0), 2, 8, 0);
		line(result, Point(step * i, 50 + nm - g_hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - g_hist.at<float>(i + 1, 0))), Scalar(0, 255, 0), 2, 8, 0);
		line(result, Point(step * i, 50 + nm - r_hist.at<float>(i, 0)), Point(step * (i + 1), 50 + (nm - r_hist.at<float>(i + 1, 0))), Scalar(0, 0, 255), 2, 8, 0);
	}

	imshow("result", result);




	waitKey(0);
	destroyAllWindows();

	return 0;
}

