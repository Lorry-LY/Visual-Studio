#pragma once

#include"Automobile.h"
class Bus :
    public Automobile
{
private:
	int carNumber;
public:
	Bus(string plateNumber, int carNumber);

	void setCarNumber(int carNumber);
	int getCarNumber();

	int pay();
	//void leave(Park& park);
};

