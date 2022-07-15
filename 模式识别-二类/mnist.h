#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui/highgui_c.h>
#include<opencv2/core/core.hpp>

#define IMAGEROW 28
#define IMAGECOL 28

using namespace cv;
using namespace std;


int Read_train_image(char* filepath, int number, int k, Mat* images);//读取mnist数据集

int Read_train_label(int number, int k, int label, Mat* labels);

int Read_txt(string file, Mat* labels);