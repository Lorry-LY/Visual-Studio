#include "Car.h"

Car::Car(string plateNumber, string brand) :Automobile(plateNumber), brand(brand) {};

void Car::setBrand(string brand)
{
	this->brand = brand;
}

string Car::getBrand()
{
	return brand;
}

int Car::pay()
{
	cout << "���ƺţ�" << getPlateNumber() << "���ͣ��γ�   Ʒ�ƣ�" << brand << "  �ɷ�1Ԫ��" << endl;
	return 1;
}

//void Car::leave(Park& park)
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