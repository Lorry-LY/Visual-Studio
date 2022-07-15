//City.cpp

#include "City.h"

void City::setNumber(int num)
{
	this->number = num;
}

void City::setName(int name)
{
	this->name = name;
}
  
void City::setPosition(int xpos, int ypos)
{
	this->x = xpos;
	this->y = ypos;
}

string City::getName()
{
	return this->name;
}

int City::getNum()
{
	return this->number;
}

int City::getX()
{
	return this->x;
}

int City::getY()
{
	return this->y;
}

void City::show()
{
	cout << "±àºÅ£º" << number << " ³ÇÊÐ£º" << name << " Î»ÖÃ£º(" << x << "," << y << ")" << endl;
}