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
			char* str = (char*)line.data();
			char* tmpStr = strtok(str, ",");
			while (tmpStr != NULL)
			{
				resultVec.push_back(std::string(tmpStr));
				tmpStr = strtok(NULL, ",");
			}
			int x = atoi(resultVec[2].c_str());
			int y = atoi(resultVec[3].c_str());
			int w = atoi(resultVec[4].c_str());
			int h = atoi(resultVec[5].c_str());
			result.push_back(Rect_<float>(Point_<float>(x, y), Point_<float>(x + w, y + h)));
		}
	}
	return result;
}

std::vector<cv::Point3f> getCarType(cv::String filename)
{
	ifstream fin(filename);
	string line;
	vector<cv::Point3f> result;
	if (fin) {
		while (getline(fin, line)) {
			std::vector<std::string> resultVec;
			char* str = (char*)line.data();
			char* tmpStr = strtok(str, ",");
			while (tmpStr != NULL)
			{
				resultVec.push_back(std::string(tmpStr));
				tmpStr = strtok(NULL, ",");
			}
			float id = atoi(resultVec[0].c_str());
			float x = atoi(resultVec[2].c_str()) + atoi(resultVec[4].c_str()) / 2.0;
			float y = atoi(resultVec[3].c_str()) + atoi(resultVec[5].c_str()) / 2.0;
			result.push_back(cv::Point3f(id, x, y));
		}
	}
	return result;
}