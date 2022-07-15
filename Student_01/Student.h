//Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
using namespace std;
class Student
{
//public:
//	Student();
//	Student(Student& stu);
//	~Student();
//	
private:
	string name;
	int classroom;
	string code;
	int grade;
public:
	Student(string name, int classroom, string code, int grade) :name(name), classroom(classroom), code(code), grade(grade) {};
	virtual void display();
	void modifygrade(int grade);
	void modifycode(string code);
	void modifyname(string name);
};



#endif // !STUDENT_H

