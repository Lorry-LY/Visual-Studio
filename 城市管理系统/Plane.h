//Plane.h
#ifndef PLANE_H
#define PLANE_H

#include<iostream>
#include<string>
#include"Map.h"
using namespace std;

class Plane
{
private:
	int number;
	string name;
	int x;
	int y;
	double weight;
public:
	Plane(unsigned number = 2000, string name = "≤®“Ù737", int x = 0, int y = 0, double weight = 2.00)
		:number(number), name(name), x(x), y(y), weight(weight) {};
	void show();
	int GanBrake(double sp, double reDistance);
	void RadarFind(double radarRadius, Map mapObj);
	void SetPlane(int num, string na, double w, int xpos, int ypos);
	int GetNumber();
};

#endif // !PLANE_H

