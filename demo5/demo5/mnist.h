#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int Read_train_image(char* filepath, int number,int k, Mat* images);//读取mnist数据集

int Read_train_label(int number, int k, int label, Mat* labels);

int Read_txt(string file, Mat* labels);