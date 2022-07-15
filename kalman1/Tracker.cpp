#include "Tracker.h"

double GetIOU(Rect_<float> bb_test, Rect_<float> bb_gt)		//����������Ľ�����
{
	float in = (bb_test & bb_gt).area();
	float un = bb_test.area() + bb_gt.area() - in;

	if (un < DBL_EPSILON)
		return 0;

	return (double)(in / un);
}

void MyTracker::Initial(vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec)
{
	for (unsigned int i = 0; i < tempVec.size(); i++)                         //�ڼ�֡����֡�ж�����
	{
		KalmanTracker trk = KalmanTracker(tempVec[i].box, tempVec[i].classId);  //��֡�ĵ�i�У���ʵ��������õ�1֡�������н��г�ʼ��
		trackers.push_back(trk);                                                //��ʼ����Ľ���Ž�һ��vector��
	}
}

void MyTracker::predict(vector<KalmanTracker>& trackers, vector<Rect_<float>>& predictedBoxes)
{
	//3.1. get predicted locations from existing trackers.		ͨ�����е�׷�������õ�Ԥ��λ��
	predictedBoxes.clear();
	for (auto it = trackers.begin(); it != trackers.end();)
	{
		Rect_<float> pBox = (*it).predict();
		if (pBox.x >= 0 && pBox.y >= 0)
		{
			predictedBoxes.push_back(pBox);
			it++;
		}
		else
		{
			it = trackers.erase(it);
		}
	}
}

void MyTracker::getMatchedPair(vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec, vector<Rect_<float>>& predictedBoxes)
{
	///////////////////////////////////////
	  // 3.2. associate detections to tracked object (both represented as bounding boxes)		����������׷�ٶ��󣨾�����Ϊ�궨��
	  // dets : detFrameData[fi]
	trkNum = predictedBoxes.size();		//Ԥ���ĳߴ磬���ж��ٸ���
	detNum = tempVec.size();			//һ֡�ж�����

	iouMatrix.clear();
	iouMatrix.resize(trkNum, vector<double>(detNum, 0));

	for (unsigned int i = 0; i < trkNum; i++) // compute iou matrix as a distance matrix		����iou������Ϊ�������
	{
		for (unsigned int j = 0; j < detNum; j++)
		{
			// use 1-iou because the hungarian algorithm computes a minimum-cost assignment.	ʹ��1-iou��Ϊ�������㷨������С�ɱ�����
			iouMatrix[i][j] = 1 - GetIOU(predictedBoxes[i], tempVec[j].box);					//ÿһ��Ԥ���͸�֡�������м���
		}
	}

	// solve the assignment problem using hungarian algorithm.		ʹ���������㷨�������������
  // the resulting assignment is [track(prediction) : detection], with len=preNum		��������[track(prediction) : detection]�����ȵ���preNum
	HungarianAlgorithm HungAlgo;
	assignment.clear();
	HungAlgo.Solve(iouMatrix, assignment);

	unmatchedTrajectories.clear();
	unmatchedDetections.clear();
	allItems.clear();
	matchedItems.clear();

	if (detNum > trkNum) //	there are unmatched detections		���һ֡����������Ԥ������������δƥ��ļ��
	{
		for (unsigned int n = 0; n < detNum; n++)
			allItems.insert(n);

		for (unsigned int i = 0; i < trkNum; ++i)
			matchedItems.insert(assignment[i]);

		set_difference(allItems.begin(), allItems.end(),
			matchedItems.begin(), matchedItems.end(),
			insert_iterator<set<int>>(unmatchedDetections, unmatchedDetections.begin()));
	}
	else if (detNum < trkNum) // there are unmatched trajectory/predictions		һ֡������С��Ԥ��������������δƥ���׷��/Ԥ��
	{
		for (unsigned int i = 0; i < trkNum; ++i)
			if (assignment[i] == -1) // unassigned label will be set as -1 in the assignment algorithm		δ����ı�ǩ���ڷ����㷨������Ϊ-1
				unmatchedTrajectories.insert(i);
	}

	// filter out matched with low IOU		���˵���IOU��ƥ��
	matchedPairs.clear();
	for (unsigned int i = 0; i < trkNum; ++i)
	{
		if (assignment[i] == -1) //pass over invalid values
			continue;
		if (1 - iouMatrix[i][assignment[i]] < iouThreshold)
		{
			unmatchedTrajectories.insert(i);
			unmatchedDetections.insert(assignment[i]);
		}
		else
		{
			matchedPairs.push_back(cv::Point(i, assignment[i]));
		}
	}
}

void MyTracker::getResult(vector<cv::Point>& matchedPairs, vector<KalmanTracker>& trackers, vector<TrackingBox>& tempVec)
{
	///////////////////////////////////////
	// 3.3. updating trackers

	// update matched trackers with assigned detections.
	// each prediction is corresponding to a tracker
	int detIdx, trkIdx;
	for (unsigned int i = 0; i < matchedPairs.size(); i++)
	{
		trkIdx = matchedPairs[i].x;
		detIdx = matchedPairs[i].y;
		trackers[trkIdx].update(tempVec[detIdx].box, tempVec[detIdx].classId);
	}

	// create and initialise new trackers for unmatched detections
	for (auto umd : unmatchedDetections)
	{
		KalmanTracker tracker = KalmanTracker(tempVec[umd].box, tempVec[umd].classId);
		trackers.push_back(tracker);
	}

	// get trackers' output
	frameTrackingResult.clear();
	for (auto it = trackers.begin(); it != trackers.end();)
	{
		if (((*it).m_time_since_update < 1) &&
			((*it).m_hit_streak >= min_hits))
		{
			TrackingBox res;
			res.box = (*it).get_state();
			res.id = (*it).m_id + 1;
			res.classId = (*it).classId;
			//res.frame = frame_count;
			frameTrackingResult.push_back(res);
			it++;
		}
		else
		{
			it++;
		}

		// remove dead tracklet
		if (it != trackers.end() && (*it).m_time_since_update > max_age)
		{
			it = trackers.erase(it);
		}
	}

}


set<int> MyTracker::unmatchedDetectionsResult()
{
	return unmatchedDetections;
}

vector<cv::Point> MyTracker::MatchedPairResult()
{
	return matchedPairs;
}

vector<TrackingBox> MyTracker::getTrackedObject()
{
	return frameTrackingResult;
}

vector<KalmanTracker> MyTracker::getBackTrackers()
{
	return trackersResult;
}


void MyTracker::Tracking(vector<TrackingBox>& tempVec)
{
	if (trackers.size() == 0) // the first frame met	��һ֡
	{
		Initial(trackers, tempVec);

		//continue;
	}
	else
	{
		//�õ�Ԥ���
		predict(trackers, predictedBoxes);
		//�õ�ƥ��ĺ�δƥ���
		getMatchedPair(trackers, tempVec, predictedBoxes);
		matchedPairs = MatchedPairResult();
		unmatchedDetections = unmatchedDetectionsResult();
		////�õ�׷�ٽ��
		getResult(matchedPairs, trackers, tempVec);
	}

}






