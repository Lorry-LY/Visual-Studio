#include "Bus.h"


Bus::Bus(string plateNumber, int carNumber) :Automobile(plateNumber), carNumber(carNumber) {};

void Bus::setCarNumber(int carNumber)
{
	this->carNumber = carNumber;
}

int Bus::getCarNumber()
{
	return carNumber;
}

int Bus::pay()
{
	cout << "���ƺţ�" << getPlateNumber() << "���ͣ���ʿ   �ؿ�����" << carNumber << "  �ɷ�2Ԫ��" << endl;
	return 2;
}

//void Bus::leave(Park& park)
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