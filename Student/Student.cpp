#include "Student.h"

void Student::display()
{
	cout << "姓名：" << name << ' ' << "学号：" << code << ' ' << "班级：" << classroom << ' ' << "C++成绩：" << grade << endl;
}

void Student::modifygrade(int grade)
{
	this->grade = grade;
}

void Student::modifycode(string code)
{
	this->code = code;
}

void Student::modifyname(string name)
{
	this->name = name;
}