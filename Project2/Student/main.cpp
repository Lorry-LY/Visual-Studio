//main.cpp
#include"Student.h"

int main()
{
	Student stu("���", 5, "25041", 99);
	stu.modifycode("14250");
	stu.modifygrade(59);
	stu.display();

	return 0;
}