//Plane.cpp

#include "Plane.h"

void Plane::show()
{
	cout << "�ɻ���ţ�" << this->number << " �ɻ����ƣ�" << this->name << " �ɻ����꣺��" << x << ',' << y << ") �ɻ�������" << this->weight << 't' << endl;
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
		cout << "�״ﷶΧ��û���κγ��С�" << endl;
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