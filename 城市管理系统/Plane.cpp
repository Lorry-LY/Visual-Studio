//Plane.cpp

#include "Plane.h"

void Plane::show()
{
	cout << "飞机编号：" << this->number << " 飞机名称：" << this->name << " 飞机坐标：（" << x << ',' << y << ") 飞机重量：" << this->weight << 't' << endl;
}

int Plane::GanBrake(double sp, double reDistance)
{
	if (this->GetNumber() == 2000)
	{
		return -1;
	}
	else if (weight * sp / 5 < reDistance)
	{
		return 1;
	}
	else
		return 0;
}

void Plane::RadarFind(double radarRadius, Map mapObj)
{
	double radius;
	int number=0;
	for (int i = 0; i < mapObj.GetCurCounter() - 1; i++)
	{
		radius = (((long double)mapObj.GetPositionX(i) - this->x) *(long double)(mapObj.GetPositionX(i) - this->x) + (long double)(mapObj.GetPositionY(i) - this->y) * (long double)(mapObj.GetPositionY(i) - this->y));
		if (radius <= radarRadius * radarRadius)
		{
			mapObj.ShowCity(i);
			number++;
		}
		cout << endl;
	}
	if (!number)
	{
		cout << "雷达范围内没有任何城市。" << endl;
	}
}

void Plane::SetPlane(int num, string na, double w, int xpos, int ypos)
{
	this->number = num;
	this->name = na;
	this->weight = w;
	this->x = xpos;
	this->y = ypos;
}

int Plane::GetNumber()
{
	return this->number;
}