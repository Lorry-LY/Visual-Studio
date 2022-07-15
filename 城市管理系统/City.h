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
	City(unsigned number=1000, string name="Beijing", int x=0, int y=0) :number(number), name(name), x(x), y(y) {};			//���캯��
	void setNumber(int num);		//���ó��б��
	void setName(int name);			//���ó�������
	void setPosition(int xpos, int ypos);		//���ó�������
	string getName();		//��ȡ��������
	int getNum();		//��ȡ���б��
	int getX();		//��ȡ����x����
	int getY();		//��ȡ����y����
	void show();	//��ʾ������Ϣ
	friend class Map;
};

#endif //!CITY_H

