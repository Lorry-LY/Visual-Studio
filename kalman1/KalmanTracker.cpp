#include "KalmanTracker.h"

int KalmanTracker::kf_count = 0;

// 	��ʼ���������˲���
void KalmanTracker::init_kf(StateType stateMat, int ClassId)
{
	int stateNum = 7;			//ʹ��7��״ֵ̬����IOU�Ŀ�Ҳ���ӽ�ȥ��
	int measureNum = 4;
	kf = KalmanFilter(stateNum, measureNum, 0);

	classId = ClassId;

	measurement = Mat::zeros(measureNum, 1, CV_32F);

	kf.transitionMatrix = (Mat_<float>(stateNum, stateNum) <<			//״̬ת�ƾ���
		1, 0, 0, 0, 1, 0, 0,
		0, 1, 0, 0, 0, 1, 0,
		0, 0, 1, 0, 0, 0, 1,
		0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 1);

	setIdentity(kf.measurementMatrix);									//�۲����
	setIdentity(kf.processNoiseCov, Scalar::all(1e-2));					//��������Э�������
	setIdentity(kf.measurementNoiseCov, Scalar::all(1e-1));				//��������Э�������
	setIdentity(kf.errorCovPost, Scalar::all(1));						//����ֵ����ʵֵ֮������Э�������

	//ʹ��[cx,cy,s,r]��ʽ�ı궨������ʼ��״̬����
	kf.statePost.at<float>(0, 0) = stateMat.x + stateMat.width / 2;
	kf.statePost.at<float>(1, 0) = stateMat.y + stateMat.height / 2;
	kf.statePost.at<float>(2, 0) = stateMat.area();
	kf.statePost.at<float>(3, 0) = stateMat.width / stateMat.height;
}

//Ԥ����Ƶı궨��
StateType KalmanTracker::predict()
{
	// predict
	Mat p = kf.predict();
	m_age += 1;

	if (m_time_since_update > 0)
		m_hit_streak = 0;
	m_time_since_update += 1;

	StateType predictBox = get_rect_xysr(p.at<float>(0, 0), p.at<float>(1, 0), p.at<float>(2, 0), p.at<float>(3, 0));

	m_history.push_back(predictBox);
	return m_history.back();
}

//ʹ�ù۲�ı궨��������״̬����
void KalmanTracker::update(StateType stateMat, int ClassId)
{
	m_time_since_update = 0;
	m_history.clear();
	m_hits += 1;
	m_hit_streak += 1;
	classId = ClassId;
	// measurement
	measurement.at<float>(0, 0) = stateMat.x + stateMat.width / 2;
	measurement.at<float>(1, 0) = stateMat.y + stateMat.height / 2;
	measurement.at<float>(2, 0) = stateMat.area();
	measurement.at<float>(3, 0) = stateMat.width / stateMat.height;

	// update
	kf.correct(measurement);
}

//���ص�ǰ״̬����
StateType KalmanTracker::get_state()
{
	Mat s = kf.statePost;
	return get_rect_xysr(s.at<float>(0, 0), s.at<float>(1, 0), s.at<float>(2, 0), s.at<float>(3, 0));
}

//�ѱ궨���[cx,cy,s,r]��ʽת��[x,y,w,h]
StateType KalmanTracker::get_rect_xysr(float cx, float cy, float s, float r)
{
	float w = sqrt(s * r);
	float h = s / w;
	float x = (cx - w / 2);
	float y = (cy - h / 2);

	if (x < 0 && cx > 0)
		x = 0;
	if (y < 0 && cy > 0)
		y = 0;

	return StateType(x, y, w, h);
}

