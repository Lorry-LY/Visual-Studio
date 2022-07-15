#pragma once

#include "Hungarian.h"
#include "KalmanTracker.h"

#include <set>

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;

typedef struct TrackingBox					//����һ���ṹ�壬���洢֡��ţ���id���������г�����rect���͵ģ�Ĭ�ϳ�idΪ-1
{
	int frame;
	long long id = -1;
	int classId = -1;
	Rect_<float> box;
}TrackingBox;

// Computes IOU between two boundboxes   ���������궨��֮���IOUֵ
double GetIOU(Rect_<float> bb_test, Rect_<float> bb_gt);

class MyTracker
{
public:
	void Initial(vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec);

	void predict(vector<KalmanTracker>& trackers, vector<Rect_<float>>& predictedBoxes);

	void getMatchedPair(vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec, vector<Rect_<float>>& predictedBoxes);

	void getResult(vector<cv::Point>& matchedPairs, vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec);

	void Tracking(vector<TrackingBox>& tempVec);

	vector<cv::Point> MatchedPairResult();

	set<int> unmatchedDetectionsResult();

	vector<TrackingBox> getTrackedObject();

	vector<KalmanTracker> getBackTrackers();

private:

	vector<KalmanTracker> trackers;

	int max_age = 20;
	int min_hits = 3;
	double iouThreshold = 0.3;

	vector<Rect_<float>> predictedBoxes;

	vector<vector<double>> iouMatrix;
	vector<int> assignment;
	set<int> unmatchedDetections;
	set<int> unmatchedTrajectories;
	set<int> allItems;
	set<int> matchedItems;
	vector<cv::Point> matchedPairs;
	vector<TrackingBox> frameTrackingResult;
	vector<KalmanTracker> trackersResult;
	unsigned int trkNum = 0;
	unsigned int detNum = 0;


	int total_frames = 0;
	double total_time = 0.0;
};
