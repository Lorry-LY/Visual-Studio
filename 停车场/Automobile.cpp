#include "Automobile.h"

Automobile::Automobile() :plateNumber("") {};

Automobile::Automobile(string plateNumber) :plateNumber(plateNumber) {};

void Automobile::setPlateNumber(string plateNumber)
{
	this->plateNumber = plateNumber;
}

string Automobile::getPlateNumber()
{
	return plateNumber;
}

void Automobile::enter(Park &park)
{
	if (park.getAviNumber() != 0)
	{
		park.setAviNumber(park.getAviNumber() - 1);
		for (int i = 0; i < park.getAllNumber(); i++)
		{
			if (park.getCar(i) == "")
			{
				park.setCar(this->getPlateNumber(), i);
				cout << this->plateNumber << "进入停车场，分配" << i + 1 << "号停车位" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "无法为"<<plateNumber<<"分配停车位" << endl;
	}
}

int Automobile::pay()
{
	return 0;
}

void Automobile::leave(Park& park)
{
	for (int i = 0; i < park.getAllNumber(); i++)
	{
		if (park.getCar(i) == getPlateNumber())
		{
			park.setCar("", i);
			park.setAviNumber(park.getAviNumber() + 1);
			park.setIncome(park.getIncome() + pay());
			break;
		}
	}
}