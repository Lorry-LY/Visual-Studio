#include "Student.h"

void Student::display()
{
	cout << "������" << name << ' ' << "ѧ�ţ�" << code << ' ' << "�༶��" << classroom << ' ' << "C++�ɼ���" << grade << endl;
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