#pragma once
#include "Automobile.h"
class Truck :
	public Automobile
{
private:
	float weight;
public:
	Truck(string plateNumber, float weight);

	void setWeight(float weight);
	float getWeight();

	int pay();
	//void leave(Park& park);

};

