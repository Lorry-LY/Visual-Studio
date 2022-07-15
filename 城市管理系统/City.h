//City.h

#include<iostream>
#include<string>
using namespace std;

#ifndef CITY_H
#define CITY_H

class City
{
private:
	int number;
	string name;
	int x;
	int y;

public:
	City(unsigned number=1000, string name="Beijing", int x=0, int y=0) :number(number), name(name), x(x), y(y) {};			//构造函数
	void setNumber(int num);		//设置城市编号
	void setName(int name);			//设置城市名称
	void setPosition(int xpos, int ypos);		//设置城市坐标
	string getName();		//读取城市名称
	int getNum();		//读取城市编号
	int getX();		//读取城市x坐标
	int getY();		//读取城市y坐标
	void show();	//显示城市信息
	friend class Map;
};

#endif //!CITY_H

