#include "Truck.h"


Truck::Truck(string plateNumber, float weight) :Automobile(plateNumber), weight(weight) {};

void Truck::setWeight(float weight)
{
	this->weight = weight;
}

float Truck::getWeight()
{
	return weight;
}

int Truck::pay()
{
	cout << "车牌号：" << getPlateNumber() << "车型：轿车   载重：" << weight << "t  缴费3元。" << endl;
	return 3;
}

//void Truck::leave(Park& park)
//{
//	for (int i = 0; i < park.getAllNumber(); i++)
//	{
//		if (park.getCar(i) == getPlateNumber())
//		{
//			park.setCar("", i);
//			park.setAviNumber(park.getAviNumber() + 1);
//			park.setIncome(park.getIncome() + pay());
//			break;
//		}
//	}
//}