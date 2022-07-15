#pragma once
#include "Automobile.h"
class Car :
    public Automobile
{
private:
	string brand;
public:
	Car(string plateNumber, string brand);

	void setBrand(string brand);
	string getBrand();

	int pay();
	//void leave(Park& park);
};

