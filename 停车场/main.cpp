#include"Park.h"
#include"Bus.h"
#include"Car.h"
#include"Truck.h"

int main()
{
	int n;
	cout << "������ͣ��λ������";
	cin >> n;
	Park park(n);
	Car car1("³B-12345", "�µ�A6");
	car1.enter(park);
	Truck truck("³B-23456", 15);
	truck.enter(park);
	car1.leave(park);

	Bus bus("³B-34567", 50);
	bus.enter(park);

	park.showInfo();

	Car car2("³B-45678", "����320");
	car2.enter(park);

	bus.leave(park);
	truck.leave(park);

	park.showInfo();

	return 0;
}