//Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	int classroom;
	string code;
	int grade;
public:
	Student(string name, int classroom, string code, int grade) :name(name), classroom(classroom), code(code), grade(grade) {};
	void display();
	void modifygrade(int grade);
	void modifyname(string name);
	void modifycode(string code);
	/*~Student()
	{
		cout << "ÀàÒÑÎö¹¹";
	}*/
};


#endif // !STUDENT_H

