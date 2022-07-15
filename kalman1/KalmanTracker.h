#pragma once

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define StateType Rect_<float>

//�����ʾ��Ϊ�߽��۲�ĸ������ٶ�����ڲ�״̬��
class KalmanTracker
{
public:
	KalmanTracker()
	{
		init_kf(StateType(), int());
		m_time_since_update = 0;
		m_hits = 0;
		m_hit_streak = 0;
		m_age = 0;
		m_id = kf_count;
		kf_count++;
		classId;
	}
	KalmanTracker(StateType initRect, int)
	{
		init_kf(initRect, int());
		m_time_since_update = 0;
		m_hits = 0;
		m_hit_streak = 0;
		m_age = 0;
		m_id = kf_count;
		kf_count++;
		classId;
	}

	~KalmanTracker()
	{
		m_history.clear();
	}

	StateType predict();
	void update(StateType stateMat, int ClassId);

	StateType get_state();
	StateType get_rect_xysr(float cx, float cy, float s, float r);

	static int kf_count;

	int m_time_since_update;
	int m_hits;
	int m_hit_streak;
	int m_age;
	int m_id;
	int classId;

private:
	void init_kf(StateType stateMat, int ClassId);

	cv::KalmanFilter kf;
	cv::Mat measurement;

	std::vector<StateType> m_history;
};
