#pragma once
#define PI 3.14
class CShape
{
public:
	double x;	//X����
	double y;	//Y����
public:
	CShape(double x, double y) :x(x), y(y) {};
	double GetX();//��ȡx����
	double GetY();//��ȡY����
	virtual double Area();//�������
};

