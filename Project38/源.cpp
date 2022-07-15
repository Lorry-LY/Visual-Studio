#include<iostream>
#include<iomanip>
using namespace std;


class Student {
//有4个学生组队参加某比赛，每个学生信息包含学号，姓名，个人成绩，4个学生有一共同团队成绩。	
private:
	string id;
	string name;
	int grade;

public:
	Student(string id = "", string name = "", int grade = 0);
	void setId(string id);
	string getId();
	void setName(string name);
	string getName();
	void setGrade(int grade);
	int getGrade();

	void display();
	
	Student operator =(Student& stu);

};

//函数实现
Student::Student(string id, string name, int grade)
{
	this->id = id;
	this->name = name;
	this->grade = grade;
}

void Student::setId(string id)
{
	this->id = id;
}

string Student::getId()
{
	return id;
}

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName()
{
	return name;
}

void Student::setGrade(int grade)
{
	this->grade = grade;
}

int Student::getGrade()
{
	return grade;
}

void Student::display()
{
	cout << "学号：" << getId() << " 姓名：" << getName() << " 成绩：" << getGrade() << endl;
}

Student Student::operator =(Student& stu)
{
	this->id = stu.id;
	this->name = stu.id;
	this->grade = stu.grade;
	return *this;
}


int main() 
{
	Student stu[4] = {
		{"202020","张三",50},
		{"202021","李四",60},
		{"202022","王五",89},
		{"202023","刘六",58}
	};
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (stu[i].getGrade() < stu[j].getGrade())
			{
				Student st = stu[i];
				stu[i] = stu[j];
				stu[j] = st;
			}
			else if (stu[i].getGrade() == stu[j].getGrade())
			{
				for (int k = 0; k < 6; k++)
				{
					if (stu[i].getId().at(k) < stu[j].getId().at(k))
					{
						Student st = stu[i];
						stu[i] = stu[j];
						stu[j] = st;
						break;
					}
				}
			}
		}
		stu[i].display();
	}
	


	return 0;
}