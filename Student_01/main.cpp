//main.cpp

#include"duty.h"
//#include<iostream>
//#include<string>
//using namespace std;

int main()
{
	Student stu("���", 5, "25041", 99);
	stu.modifycode("14250");
	stu.modifygrade(59);
	stu.display();
	cout << endl;
	duty moni("����", 5, "25041", 90, "moniter");
	moni.display();
	moni.Student::display();
	duty study(stu, "study");
	study.display();
	study.Student::display();

	return 0;
}