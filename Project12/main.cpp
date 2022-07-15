#include <iostream>
#include <string>
using namespace std;
struct car {
	string maker;
	int year = 0;
};
int main() {
	cout << "How many cars do you wish to catalog? ";
	int num;
	cin >> num;
	cin.get();
	car* p_car = new car[num];
	for (int i = 0; i < num; i++) {
		cout << "Car #" << i + 1 << ":\n";
		cout << "Please enter the make: ";
		getline(cin, (p_car + i)->maker);
		cout << "Please enter the year made: ";
		cin >> (p_car + i)->year;
		cin.get();
	}
	cout << "here is your collection: \n";
	for (int i = 0; i < num; i++) {
		cout << (p_car + i)->year << " " << (p_car + i)->maker << endl;
	}
	delete[] p_car;
	return 0;
}