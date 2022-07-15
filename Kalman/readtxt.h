#pragma once

#include <iostream>
#include <vector>
#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <fstream>
#include <string.h>

using namespace std;
using namespace cv;

std::vector<cv::Rect_<float>> getgroundtruth(cv::String filename)
{
	ifstream fin(filename);
	string line;
	vector<cv::Rect_<float>> result;
	if (fin) {
		while (getline(fin, line)) {
			std::vector<std::string> resultVec;
			char* str = (char *)line.data();
			char* tmpStr = strtok(str, ",");
			while (tmpStr != NULL)
			{
				resultVec.push_back(std::string(tmpStr));
				tmpStr = strtok(NULL, ",");
			}
			result.push_back(Rect_<float>(Point_<float>(atoi(resultVec[2].c_str()), atoi(resultVec[3].c_str())), Point_<float>(atoi(resultVec[4].c_str()), atoi(resultVec[5].c_str()))));
		}
	}
	return result;
}

std::vector<cv::Point3f> getCarType(cv::String filename)
{

}