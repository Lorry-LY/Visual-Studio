#pragma once

#include"Park.h"
#include<iostream>
#include<vector>

using namespace std;


class Automobile
{
private:
	string plateNumber;
public:
	Automobile();
	Automobile(string plateNumber);

	void setPlateNumber(string plateNumber);
	string getPlateNumber();

	virtual int pay();
	virtual void enter(Park &park);
	virtual void leave(Park& park);
	
};

