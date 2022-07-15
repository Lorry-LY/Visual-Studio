#pragma once
#define PI 3.14
class CShape
{
public:
	double x;	//X坐标
	double y;	//Y坐标
public:
	CShape(double x, double y) :x(x), y(y) {};
	double GetX();//获取x坐标
	double GetY();//获取Y坐标
	virtual double Area();//计算面积
};

