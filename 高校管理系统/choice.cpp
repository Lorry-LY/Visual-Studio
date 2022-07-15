#pragma once
#include "tool.h"
#include "Reascher.h"
#include "Tea_Off.h"
#include "choice.h"


/*
	这个cpp文件存储了所有的选项及功能
	函数的功能及其命名请查看.h
*/

//重新声明全局变量
extern int int_1, int_2, int_3;
extern string str_1, str_2, str_3;
extern vector<string> vec_str_1, vec_str_2, vec_str_3;
extern vector<int> vec_int_1, vec_int_2, vec_int_3;
extern vector<const char*> vec_words;

extern vector<string> vec_lab;//研究人员类中的实验室列表
extern vector<string> vec_department;//教师类中的院系列表
extern vector<string> vec_tittle;//教师类的职称列表
extern vector<string> vec_duty;//行政人员类的职务列表
extern vector<string> vec_politiclook;//政治面貌列表

//对象列表
extern vector<Reasecher> vec_obj_reasecher;
extern vector<Teacher> vec_obj_teacher;
extern vector<Official> vec_obj_official;
extern vector<Tea_Off> vec_obj_tea_off;

//number库和name库
extern vector<string> vec_number;
extern vector<string> vec_name;

//函数实现部分

//choice
void choice0()
{
	//所有的标志位为1时返回上一级，默认为0停留在本级

	while (1)
	{

		bool flag_0 = 0;//主菜单退出标志
		int choice_0;//主菜单选项

		vec_words.clear();
		vec_words.push_back("1.统计人员信息");
		vec_words.push_back("2.添加");
		vec_words.push_back("3.查找");
		vec_words.push_back("4.退出系统");

		choice_0 = output_list(vec_words);

		switch (choice_0)
		{
		case 1:
			//统计
			choice1();
			break;
		case 2:
			//增加
			choice2();
			break;
		case 3:
			//查找
			choice3();
			break;
		case 4:
			//退出系统
			flag_0 = 1;
			break;
		}

		if (flag_0)
		{
			break;
		}
	}

	cout << "感谢你的使用" << endl;
}
void choice1()
{
	bool flag_1 = 0;
	int choice1;
	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.查看所有人员的姓名、人员类别、编号");
		vec_words.push_back("2.查看特定种类的人员");
		vec_words.push_back("3.人员信息汇总");
		vec_words.push_back("4.返回上一级");

		choice1 = output_list(vec_words);

		switch (choice1)
		{
		case 1:
			//查看所有人员的姓名、人员类别、编号
			print1_1();
			choice1_1();
			break;
		case 2:
			//查看特定种类的人员
			choice1_2();
			break;
		case 3:
			//信息统计
			choice1_3();
			break;
		case 4:
			//返回上一级
			flag_1 = 1;
			break;
		}

		if (flag_1)
		{
			break;
		}
	}
}
void choice1_1()
{
	bool flag_1_1 = 0;
	int choice1_1;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按年龄排序");
		vec_words.push_back("2.按性别排序");
		vec_words.push_back("3.返回上一级");

		choice1_1 = output_list(vec_words);

		switch (choice1_1)
		{
		case 1:
			//按年领将所有人员的信息输出
			operate1_1_1();
			print1_1_1();
			break;
		case 2:
			operate1_1_2();
			print1_1_2();
			break;
		case 3:
			flag_1_1 = 1;
			break;
		}

		if (flag_1_1)
		{
			break;
		}
	}
}

void choice1_2()
{
	bool flag_1_2 = 0;
	int choice1_2;
	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.行政人员");
		vec_words.push_back("2.教师");
		vec_words.push_back("3.教师兼行政人员");
		vec_words.push_back("4.研究人员");
		vec_words.push_back("5.返回上一级");

		choice1_2 = output_list(vec_words);

		switch (choice1_2)
		{
		case 1:
			//official
			print1_2_1();
			choice1_2_1();
			break;
		case 2:
			//teacher
			print1_2_2();
			choice1_2_2();
			break;
		case 3:
			//tea&off
			print1_2_3();
			choice1_2_3();
			break;
		case 4:
			//reasecher
			print1_2_4();
			choice1_2_4();
			break;
		case 5:
			flag_1_2 = 1;
			break;
		}

		if (flag_1_2)
		{
			break;
		}
	}


}
void choice1_2_1()
{
	bool flag_1_2_1 = 0;
	int choice1_2_1;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按政治面貌排序");
		vec_words.push_back("2.按行政职务排序");
		vec_words.push_back("3.返回上一级");
		choice1_2_1 = output_list(vec_words);

		switch (choice1_2_1)
		{
		case 1:
			//按政治面貌排序
			operate1_2_1_1();
			print1_2_1_1();
			break;
		case 2:
			//按行政职务排序
			operate1_2_1_2();
			print1_2_2_1();
			break;
		case 3:
			flag_1_2_1 = 1;
			break;
		}

		if (flag_1_2_1)
		{
			break;
		}
	}
}
void choice1_2_2()
{
	bool flag_1_2_2 = 0;
	int choice1_2_2;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按所在院系排序");
		vec_words.push_back("2.按教师职称排序");
		vec_words.push_back("3.返回上一级");
		choice1_2_2 = output_list(vec_words);

		switch (choice1_2_2)
		{
		case 1:
			//break;
			operate1_2_2_1();
			print1_2_2_1();
			break;
		case 2:
			//
			operate1_2_2_2();
			print1_2_2_2();
			break;
		case 3:
			flag_1_2_2 = 1;
			break;
		}

		if (flag_1_2_2)
		{
			break;
		}
	}
}
void choice1_2_3()
{
	bool flag_1_2_3 = 0;
	int choice1_2_3;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按政治面貌排序");
		vec_words.push_back("2.按行政职务排序");
		vec_words.push_back("3.按所在院系排序");
		vec_words.push_back("4.按教师职称排序");
		vec_words.push_back("5.返回上一级");

		choice1_2_3 = output_list(vec_words);

		switch (choice1_2_3)
		{
		case 1:
			//break;
			operate1_2_3_1();
			print1_2_3_1();
			break;
		case 2:
			//
			operate1_2_3_2();
			print1_2_3_2();
			break;
		case 3:
			//break;
			operate1_2_3_3();
			print1_2_3_3();
			break;
		case 4:
			//
			operate1_2_3_4();
			print1_2_3_4();
			break;
		case 5:
			flag_1_2_3 = 1;
			break;
		}

		if (flag_1_2_3)
		{
			break;
		}
	}
}
void choice1_2_4()
{
	bool flag_1_2_4 = 0;
	int choice1_2_4;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按所在实验室排序");
		vec_words.push_back("2.按实验室职务排序");
		vec_words.push_back("3.返回上一级");

		choice1_2_4 = output_list(vec_words);

		switch (choice1_2_4)
		{
		case 1:
			//break;
			operate1_2_4_1();
			print1_2_4_1();
			break;
		case 2:
			//
			operate1_2_4_2();
			print1_2_4_2();
			break;
		case 3:
			flag_1_2_4 = 1;
			break;
		}

		if (flag_1_2_4)
		{
			break;
		}
	}
}

void choice1_3()
{
	print1_3();
}

void choice2()
{
	bool flag_2 = 0;
	int choice2;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("请选择你要添加的人员或事物：");
		vec_words.push_back("1.行政人员");
		vec_words.push_back("2.教师");
		vec_words.push_back("3.教师兼行政人员");
		vec_words.push_back("4.研究人员");
		vec_words.push_back("5.学院");
		vec_words.push_back("6.行政职务");
		vec_words.push_back("7.教师职称");
		vec_words.push_back("8.实验室");
		vec_words.push_back("9.政治面貌");
		vec_words.push_back("10.返回上一级");

		choice2 = output_list(vec_words);

		switch (choice2)
		{
		case 1:
			operate2_1();
			break;
		case 2:
			operate2_2();
			break;
		case 3:
			operate2_3();
			break;
		case 4:
			operate2_4();
			break;
		case 5:
			operate2_5();
			break;
		case 6:
			operate2_6();
			break;
		case 7:
			operate2_7();
			break;
		case 8:
			operate2_8();
			break;
		case 9:
			operate2_9();
			break;
		case 10:
			flag_2 = 1;
			break;
		}

		if (flag_2)
		{
			break;
		}
	}
}

void choice3()
{
	bool flag_3 = 0;
	int choice3;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.按编号查找人员");
		vec_words.push_back("2.按姓名查找人员");
		vec_words.push_back("3.查找学院");
		vec_words.push_back("4.查找行政职务");
		vec_words.push_back("5.查找教师职称");
		vec_words.push_back("6.查找政治面貌");
		vec_words.push_back("7.查找实验室");
		vec_words.push_back("8.返回上一级");

		choice3 = output_list(vec_words);

		switch (choice3)
		{
		case 1:
			if (find_people_in_number())//找到了
			{
				print3_1();
				choice3_1();
			}
			else
			{
				print3_1();
			}
			break;
		case 2:
			if (find_people_in_number())
			{
				print3_2();
				choice3_2();
			}
			else
			{
				print3_2();
			}
			break;
		case 3:
			operate3_3();
			print3_3();
			break;
		case 4:
			operate3_4();
			print3_4();
			break;
		case 5:
			operate3_5();
			print3_5();
			break;
		case 6:
			operate3_6();
			print3_6();
			break;
		case 7:
			operate3_7();
			print3_7();
			break;
		case 8:
			flag_3 = 1;
			break;
		}

		if (flag_3)
		{
			break;
		}
	}
}
void choice3_1()
{
	bool flag_3_1 = 0;
	int choice3_1;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.编辑资料");
		vec_words.push_back("2.删除人员");
		vec_words.push_back("3.返回上一级");

		choice3_1 = output_list(vec_words);

		switch (choice3_1)
		{
		case 1:
			operate3_1_1();
			break;
		case 2:
			operate3_1_2();
			break;
		case 3:
			flag_3_1 = 1;
			break;
		}

		if (flag_3_1)
		{
			break;
		}
	}
}
void choice3_2()
{
	bool flag_3_2 = 0;
	int choice3_2;

	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.编辑资料");
		vec_words.push_back("2.删除人员");
		vec_words.push_back("3.返回上一级");

		choice3_2 = output_list(vec_words);

		switch (choice3_2)
		{
		case 1:
			operate3_2_1();
			break;
		case 2:
			operate3_2_2();
			break;
		case 3:
			flag_3_2 = 1;
			break;
		}

		if (flag_3_2)
		{
			break;
		}
	}
}


//operate
void operate1_1_1()
{

	int size = vec_obj_official.size();

	int* ary_age, * ary_sort;
	ary_age = new int[size];
	ary_sort = new int[size];

	for (int i = 0; i < size; i++)
	{
		ary_sort[i] = i;
		ary_age[i] = vec_obj_official[i].get_age();
	}
	int temp = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ary_age[j] > ary_age[j + 1])
			{
				temp = ary_age[j + 1];
				ary_age[j + 1] = ary_age[j];
				ary_age[j] = temp;

				temp = ary_sort[j + 1];
				ary_sort[j + 1] = ary_sort[j];
				ary_sort[j] = temp;
			}
		}
	}

	vec_int_1.clear();

	for (int i = 0; i < size; i++)
	{
		vec_int_1.push_back(ary_sort[i]);
	}

	delete[] ary_age, ary_sort;

	size = vec_obj_tea_off.size();

	ary_age = new int[size];
	ary_sort = new int[size];

	for (int i = 0; i < size; i++)
	{
		ary_sort[i] = i;
		ary_age[i] = vec_obj_tea_off[i].Teacher::get_age();
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ary_age[j] > ary_age[j + 1])
			{
				temp = ary_age[j + 1];
				ary_age[j + 1] = ary_age[j];
				ary_age[j] = temp;

				temp = ary_sort[j + 1];
				ary_sort[j + 1] = ary_sort[j];
				ary_sort[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		vec_int_1.push_back(ary_sort[i]);
	}

	delete[] ary_age, ary_sort;

	size = vec_obj_teacher.size();

	ary_age = new int[size];
	ary_sort = new int[size];

	for (int i = 0; i < size; i++)
	{
		ary_sort[i] = i;
		ary_age[i] = vec_obj_teacher[i].get_age();
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ary_age[j] > ary_age[j + 1])
			{
				temp = ary_age[j + 1];
				ary_age[j + 1] = ary_age[j];
				ary_age[j] = temp;

				temp = ary_sort[j + 1];
				ary_sort[j + 1] = ary_sort[j];
				ary_sort[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		vec_int_1.push_back(ary_sort[i]);
	}

	delete[] ary_age, ary_sort;

	size = vec_obj_reasecher.size();

	ary_age = new int[size];
	ary_sort = new int[size];

	for (int i = 0; i < size; i++)
	{
		ary_sort[i] = i;
		ary_age[i] = vec_obj_reasecher[i].get_age();
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ary_age[j] > ary_age[j + 1])
			{
				temp = ary_age[j + 1];
				ary_age[j + 1] = ary_age[j];
				ary_age[j] = temp;

				temp = ary_sort[j + 1];
				ary_sort[j + 1] = ary_sort[j];
				ary_sort[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		vec_int_1.push_back(ary_sort[i]);
	}

	delete[] ary_age, ary_sort;


}
void operate1_1_2()
{
	//do nothing
}

void operate1_2_1_1()//按政治面貌排序,vec_int_temp1按序存储了排序之后所有official对象在vec_obj_official中的下标
{
	//do nothing
}
void operate1_2_1_2()
{
	//do nothing
}

void operate1_2_2_1()
{
	//do nothing
}
void operate1_2_2_2()
{
	//do nothing
}
void operate1_2_3_1()
{
	//do nothing
}
void operate1_2_3_2()
{
	//do nothing
}
void operate1_2_3_3()
{
	//do nothing
}
void operate1_2_3_4()
{
	//do nothing
}

void operate1_2_4_1()
{
	//do nothing
}
void operate1_2_4_2()
{
	//do nothing
}

void operate2_1()//添加official
{
	cout << "请输入他/她的姓名,最大长度为16个字符，超出长度的部分将被截断：" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "出生年份(整数）");
	int_2 = read_int(1, 12, "出生月份(整数）");

	if (int_2 == 2)//是二月
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//是闰年
		{
			int_3 = read_int(1, 29, "出生日期(整数）");
		}
		else
		{
			int_3 = read_int(1, 28, "出生日期(整数）");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "出生日期(整数）");
	}
	else
	{
		int_3 = read_int(1, 30, "出生日期(整数）");
	}

	int _sex = read_int(1, 2, "请选择他/她的性别,\n1男\n2女\n你的选择：");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "请输入他的四位尾号");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "尾号重复，请重新输入" << endl;
		}
		else
		{
			flag = 1;
		}

		if (flag)
		{
			break;
		}
	}

	int idx_duty, idx_politiclook;

	idx_duty = choose_list(vec_duty, "\n请选择行政职务：", "如过没有你想要的职务，请返回主菜单添加。");
	idx_politiclook = choose_list(vec_politiclook, "\n请选择政治面貌", "如果没有合适的政治面貌，请返回主菜单添加。");

	//到此为止，所有的数据已经收集完毕,在对象列表中添加即可
	vec_obj_official.push_back(Official(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_politiclook, idx_duty));
	cout << "\n已经成功添加该人员,后续修改请到主菜单中查找并修改。\n" << endl;
	vec_number.push_back(vec_obj_official.back().get_id().get_number());
	vec_name.push_back(vec_obj_official.back().get_name());
}
void operate2_2()
{
	cout << "请输入他/她的姓名,最大长度为16个字符，超出长度的部分将被截断：" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "出生年份(整数）");
	int_2 = read_int(1, 12, "出生月份(整数）");

	if (int_2 == 2)//是二月
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//是闰年
		{
			int_3 = read_int(1, 29, "出生日期(整数）");
		}
		else
		{
			int_3 = read_int(1, 28, "出生日期(整数）");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "出生日期(整数）");
	}
	else
	{
		int_3 = read_int(1, 30, "出生日期(整数）");
	}

	int _sex = read_int(1, 2, "请选择他/她的性别,\n1男\n2女\n你的选择：");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "请输入他的四位尾号");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "尾号重复，请重新输入" << endl;
		}
		else
		{
			flag = 1;
		}

		if (flag)
		{
			break;
		}
	}

	int idx_tittle, idx_department;

	idx_tittle = choose_list(vec_tittle, "\n请选择教师职称：", "如过没有你想要的职称，请返回主菜单添加。");
	idx_department = choose_list(vec_department, "\n请选择所在院系", "如果没有合适的院系，请返回主菜单添加。");

	//到此为止，所有的数据已经收集完毕,在对象列表中添加即可
	vec_obj_teacher.push_back(Teacher(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_tittle, idx_department));
	cout << "\n已经成功添加该人员,后续修改请到主菜单中查找并修改。\n" << endl;
	vec_number.push_back(vec_obj_teacher.back().get_id().get_number());
	vec_name.push_back(vec_obj_teacher.back().get_name());

}
void operate2_3()
{
	cout << "请输入他/她的姓名,最大长度为16个字符，超出长度的部分将被截断：" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "出生年份(整数）");
	int_2 = read_int(1, 12, "出生月份(整数）");

	if (int_2 == 2)//是二月
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//是闰年
		{
			int_3 = read_int(1, 29, "出生日期(整数）");
		}
		else
		{
			int_3 = read_int(1, 28, "出生日期(整数）");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "出生日期(整数）");
	}
	else
	{
		int_3 = read_int(1, 30, "出生日期(整数）");
	}

	int _sex = read_int(1, 2, "请选择他/她的性别,\n1男\n2女\n你的选择：");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "请输入他的四位尾号");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "尾号重复，请重新输入" << endl;
		}
		else
		{
			flag = 1;
		}

		if (flag)
		{
			break;
		}
	}

	int idx_duty, idx_politiclook;
	int idx_tittle, idx_department;

	idx_tittle = choose_list(vec_tittle, "\n请选择教师职称：", "如过没有你想要的职称，请返回主菜单添加。");
	idx_department = choose_list(vec_department, "\n请选择所在院系", "如果没有合适的院系，请返回主菜单添加。");
	idx_duty = choose_list(vec_duty, "\n请选择行政职务：", "如过没有你想要的职务，请返回主菜单添加。");
	idx_politiclook = choose_list(vec_politiclook, "\n请选择政治面貌", "如果没有合适的政治面貌，请返回主菜单添加。");

	//到此为止，所有的数据已经收集完毕,在对象列表中添加即可
	vec_obj_tea_off.push_back(Tea_Off(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_duty, idx_politiclook, idx_politiclook, idx_duty));
	cout << "\n已经成功添加该人员,后续修改请到主菜单中查找并修改。\n" << endl;
	vec_number.push_back(vec_obj_tea_off.back().Teacher::get_id().get_number());
	vec_name.push_back(vec_obj_tea_off.back().Teacher::get_name());
}
void operate2_4()
{
	cout << "请输入他/她的姓名,最大长度为16个字符，超出长度的部分将被截断：" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "出生年份(整数）");
	int_2 = read_int(1, 12, "出生月份(整数）");

	if (int_2 == 2)//是二月
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//是闰年
		{
			int_3 = read_int(1, 29, "出生日期(整数）");
		}
		else
		{
			int_3 = read_int(1, 28, "出生日期(整数）");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "出生日期(整数）");
	}
	else
	{
		int_3 = read_int(1, 30, "出生日期(整数）");
	}

	int _sex = read_int(1, 2, "请选择他/她的性别,\n1男\n2女\n你的选择：");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "请输入他的四位尾号");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "尾号重复，请重新输入" << endl;
		}
		else
		{
			flag = 1;
		}

		if (flag)
		{
			break;
		}
	}

	cout << "请输入他/她所在实验室的职务：" << endl;
	char post[16] = { '\0' };
	cin.getline(post, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_2 = post;

	int idx_lab = choose_list(vec_lab, "\n请选择他/她所在的实验室：", "如果没有合适的实验室，请在主菜单内添加.");

	vec_obj_reasecher.push_back(Reasecher(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), str_2, idx_lab));
	vec_number.push_back(vec_obj_reasecher.back().get_id().get_number());
	vec_name.push_back(vec_obj_reasecher.back().get_name());
}
void operate2_5()//添加学院
{
	cout << "当前学院已有：" << endl;
	for (int i = 0; i < vec_department.size(); i++)
	{
		cout << vec_department[i] << endl;
	}
	cout << "请输入你要添加的新学院，如XX学院,最多15个字符：" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "已经成功添加" << endl;
}
void operate2_6()
{
	cout << "当前已有行政职务：" << endl;
	for (int i = 0; i < vec_duty.size(); i++)
	{
		cout << vec_duty[i] << endl;
	}
	cout << "请输入你要添加的新职务,最多15个字符：" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "已经成功添加该职务." << endl;
}
void operate2_7()
{
	cout << "当前已有教师职称：" << endl;
	for (int i = 0; i < vec_tittle.size(); i++)
	{
		cout << vec_tittle[i] << endl;
	}
	cout << "请输入你要添加的新职称,最多15个字符：" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "已经成功添加该职称." << endl;
}
void operate2_8()
{
	cout << "当前已有实验室：" << endl;
	for (int i = 0; i < vec_lab.size(); i++)
	{
		cout << vec_lab[i] << endl;
	}
	cout << "请输入你要添加的新实验室，如XX实验室,最多25个字符：" << endl;
	char name[25];
	cin.getline(name, 25);
	vec_department.push_back(name);

	cout << "已经成功添加该实验室." << endl;
}
void operate2_9()
{
	cout << "当前已有政治面貌：" << endl;
	for (int i = 0; i < vec_politiclook.size(); i++)
	{
		cout << vec_politiclook[i] << endl;
	}
	cout << "请输入你要添加的新政治面貌,最多15个字符：" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "已经成功添加该政治面貌." << endl;
}

void operate3_1_1()
{
	vec_words.clear();
	vec_words.push_back("请选择你要修改的资料：");

	int choice;
	char ch[16];
	string str;

	switch (vec_int_3[0])
	{
	case 1:
		vec_words.push_back("行政职务");
		vec_words.push_back("政治面貌");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_official[vec_int_3[1]].ser_duty(choose_list(vec_duty, "请选择新的行政职务", NULL));
			break;
		case 2:
			vec_obj_official[vec_int_3[1]].set_poloticlook(choose_list(vec_politiclook, "请选择新的政治面貌", NULL));
			break;
		}
		break;
	case 2:
		vec_words.push_back("教师职称");
		vec_words.push_back("所在院系");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_teacher[vec_int_3[1]].set_tittle(choose_list(vec_tittle, "请选择新的教师职称", NULL));
			break;
		case 2:
			vec_obj_teacher[vec_int_3[1]].set_department(choose_list(vec_department, "请选择新的所在院系", NULL));
			break;
		}
		break;
	case 3:
		vec_words.push_back("行政职务");
		vec_words.push_back("政治面貌");
		vec_words.push_back("教师职称");
		vec_words.push_back("所在院系");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_tea_off[vec_int_3[1]].ser_duty(choose_list(vec_duty, "请选择新的行政职务", NULL));
			break;
		case 2:
			vec_obj_tea_off[vec_int_3[1]].set_poloticlook(choose_list(vec_politiclook, "请选择新的政治面貌", NULL));
			break;
		case 3:
			vec_obj_tea_off[vec_int_3[1]].set_tittle(choose_list(vec_tittle, "请选择新的教师职称", NULL));
			break;
		case 4:
			vec_obj_tea_off[vec_int_3[1]].set_department(choose_list(vec_department, "请选择新的所在院系", NULL));
			break;
		}
		break;
	case 4:
		vec_words.push_back("所在实验室");
		vec_words.push_back("实验室职务");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_reasecher[vec_int_3[1]].ser_lab(choose_list(vec_lab, "请选择新的实验室", NULL));
			break;
		case 2:
			cout << "请输入新的实验室职务,最多16字符：";
			cin.getline(ch, 16);
			cin.clear();
			cin.sync();
			str = ch;
			vec_obj_reasecher[vec_int_3[1]].set_post(str);
			break;
		}
		break;
	}

}
void operate3_1_2()
{
	switch (vec_int_3[0])
	{
	case 1:
	{
		std::vector<Official>::iterator it;
		it = vec_obj_official.begin() + vec_int_3[1];
		vec_obj_official.erase(it);
		break;
	}
	case 2:
	{
		std::vector<Teacher>::iterator it;
		it = vec_obj_teacher.begin() + vec_int_3[1];
		vec_obj_teacher.erase(it);
		break;
	}
	case 3:
	{
		std::vector<Tea_Off>::iterator it;
		it = vec_obj_tea_off.begin() + vec_int_3[1];
		vec_obj_tea_off.erase(it);
		break;
	}
	case 4:
	{
		std::vector<Reasecher>::iterator it;
		it = vec_obj_reasecher.begin() + vec_int_3[1];
		vec_obj_reasecher.erase(it);
		break;
	}
	}

	cout << "已经成功删除该人物信息\n" << endl;
}
void operate3_2_1()
{
	operate3_1_1();
}
void operate3_2_2()
{

	operate3_1_2();

}


void operate3_3()
{
	char ch[18];
	cout << "请输入你要查询的数据:";
	cin.getline(ch, 18);
	string str = ch;

	if (find(vec_department, str) != -1)
	{
		cout << "存在" << str << endl;
	}
	else
	{
		cout << str << "不存在" << endl;
	}
	system("pause");

}
void operate3_4()
{
	operate3_3();
}
void operate3_5()/////////////////
{
	operate3_3();
}
void operate3_6()
{
	operate3_3();
}
void operate3_7()
{
	operate3_3();
}



//print
void print1_1()
{
	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "姓名      编号              行政职务      政治面貌" << endl;
	cout.setf(std::ios::left);

	for (int i = 0; i < vec_obj_official.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_official[i].get_name();
		cout.width(18);
		cout << vec_obj_official[i].get_id().get_number();
		cout.width(14);
		cout << vec_obj_official[i].get_str_duty();
		cout.width(14);
		cout << vec_obj_official[i].get_str_politiclook() << endl;
	}

	cout << endl;
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int i = 0; i < vec_obj_teacher.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_teacher[i].get_name();
		cout.width(18);
		cout << vec_obj_teacher[i].get_id().get_number();
		cout.width(14);
		cout << vec_obj_teacher[i].get_str_department();
		cout.width(14);
		cout << vec_obj_teacher[i].get_str_tittle() << endl;
	}

	cout << endl;
	cout << "教师兼行政人员：" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;
	for (int i = 0; i < vec_obj_tea_off.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_tea_off[i].Teacher::get_name();
		cout.width(18);
		cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_department();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_tittle();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_duty();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
	}

	cout << endl;
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int i = 0; i < vec_obj_reasecher.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_reasecher[i].get_name();
		cout.width(18);
		cout << vec_obj_reasecher[i].get_id().get_number();
		cout.width(16);
		cout << vec_obj_reasecher[i].get_str_lab();
		cout.width(14);
		cout << vec_obj_reasecher[i].get_post() << endl;
	}
	cout << endl;
}
void print1_1_1()
{
	int size1 = vec_obj_official.size();
	int size2 = vec_obj_tea_off.size();
	int size3 = vec_obj_teacher.size();
	int size4 = vec_obj_reasecher.size();

	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "姓名      编号              行政职务      政治面貌" << endl;
	cout.setf(std::ios::left);

	for (int i = 0; i < size1; i++)
	{
		cout.width(10);
		cout << vec_obj_official[vec_int_1[i]].get_name();
		cout.width(18);
		cout << vec_obj_official[vec_int_1[i]].get_id().get_number();
		cout.width(14);
		cout << vec_obj_official[vec_int_1[i]].get_str_duty();
		cout.width(14);
		cout << vec_obj_official[vec_int_1[i]].get_str_politiclook() << endl;
	}
	cout << endl;
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int i = size1 + size2; i < size1 + size2 + size3; i++)
	{
		cout.width(10);
		cout << vec_obj_teacher[vec_int_1[i]].get_name();
		cout.width(18);
		cout << vec_obj_teacher[vec_int_1[i]].get_id().get_number();
		cout.width(14);
		cout << vec_obj_teacher[vec_int_1[i]].get_str_department();
		cout.width(14);
		cout << vec_obj_teacher[vec_int_1[i]].get_str_tittle() << endl;
	}

	cout << endl;
	cout << "教师兼行政人员：" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;
	for (int i = size1; i < size1 + size2; i++)
	{
		cout.width(10);
		cout << vec_obj_tea_off[vec_int_1[i]].Teacher::get_name();
		cout.width(18);
		cout << vec_obj_tea_off[vec_int_1[i]].Teacher::get_id().get_number();
		cout.width(14);
		cout << vec_obj_tea_off[vec_int_1[i]].get_str_department();
		cout.width(14);
		cout << vec_obj_tea_off[vec_int_1[i]].get_str_tittle();
		cout.width(14);
		cout << vec_obj_tea_off[vec_int_1[i]].get_str_duty();
		cout.width(14);
		cout << vec_obj_tea_off[vec_int_1[i]].get_str_politiclook() << endl;
	}

	cout << endl;
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int i = size1 + size2 + size3; i < size1 + size2 + size3 + size4; i++)
	{
		cout.width(10);
		cout << vec_obj_reasecher[vec_int_1[i]].get_name();
		cout.width(18);
		cout << vec_obj_reasecher[vec_int_1[i]].get_id().get_number();
		cout.width(16);
		cout << vec_obj_reasecher[vec_int_1[i]].get_str_lab();
		cout.width(14);
		cout << vec_obj_reasecher[vec_int_1[i]].get_post() << endl;
	}
	cout << endl;
}
void print1_1_2()////////////////
{
	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "姓名      编号              行政职务      政治面貌" << endl;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < vec_obj_official.size(); i++)
		{
			if (vec_obj_official[i].get_sex() == j)
			{
				cout.setf(std::ios::left);
				cout.width(10);
				cout << vec_obj_official[i].get_name();
				cout.width(18);
				cout << vec_obj_official[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_official[i].get_str_duty();
				cout.width(14);
				cout << vec_obj_official[i].get_str_politiclook() << endl;

			}
		}
	}

	cout << endl;
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			if (vec_obj_teacher[i].get_sex() == j)
			{
				cout.width(10);
				cout << vec_obj_teacher[i].get_name();
				cout.width(18);
				cout << vec_obj_teacher[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_department();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_tittle() << endl;
			}
		}
	}

	cout << endl;
	cout << "教师兼行政人员：" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			if (vec_obj_teacher[i].get_sex() == j)
			{
				cout.width(10);
				cout << vec_obj_tea_off[i].Teacher::get_name();
				cout.width(18);
				cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_department();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_tittle();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_duty();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
			}
		}
	}

	cout << endl;
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < vec_obj_reasecher.size(); i++)
		{
			if (vec_obj_reasecher[i].get_sex() == j)
			{
				cout.width(10);
				cout << vec_obj_reasecher[i].get_name();
				cout.width(18);
				cout << vec_obj_reasecher[i].get_id().get_number();
				cout.width(16);
				cout << vec_obj_reasecher[i].get_str_lab();
				cout.width(14);
				cout << vec_obj_reasecher[i].get_post() << endl;
			}
		}
	}

	cout << endl;

}

void print1_2_1()
{
	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "姓名      编号              行政职务      政治面貌" << endl;
	cout.setf(std::ios::left);

	for (int i = 0; i < vec_obj_official.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_official[i].get_name();
		cout.width(18);
		cout << vec_obj_official[i].get_id().get_number();
		cout.width(14);
		cout << vec_obj_official[i].get_str_duty();
		cout.width(14);
		cout << vec_obj_official[i].get_str_politiclook() << endl;
	}

	cout << endl;
}
void print1_2_1_1()
{
	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "姓名      编号              行政职务      政治面貌" << endl;
	cout.setf(std::ios::left);

	for (int j = 1; j < vec_politiclook.size(); j++)
	{
		for (int i = 0; i < vec_obj_official.size(); i++)
		{
			if (vec_obj_official[i].get_idx_politiclook() == j)
			{
				cout.width(10);
				cout << vec_obj_official[i].get_name();
				cout.width(18);
				cout << vec_obj_official[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_official[i].get_str_duty();
				cout.width(14);
				cout << vec_obj_official[i].get_str_politiclook() << endl;
			}
		}
	}
	cout << endl;
}
void print1_2_1_2()
{
	cout << "行政人员：" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "姓名      编号              行政职务      政治面貌" << endl;
	cout.setf(std::ios::left);

	for (int j = 1; j < vec_duty.size(); j++)
	{
		for (int i = 0; i < vec_obj_official.size(); i++)
		{
			if (vec_obj_official[i].get_idx_duty() == j)
			{
				cout.width(10);
				cout << vec_obj_official[i].get_name();
				cout.width(18);
				cout << vec_obj_official[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_official[i].get_str_duty();
				cout.width(14);
				cout << vec_obj_official[i].get_str_politiclook() << endl;
			}
		}
	}
	cout << endl;
}

void print1_2_2()
{
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int i = 0; i < vec_obj_teacher.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_teacher[i].get_name();
		cout.width(18);
		cout << vec_obj_teacher[i].get_id().get_number();
		cout.width(14);
		cout << vec_obj_teacher[i].get_str_department();
		cout.width(14);
		cout << vec_obj_teacher[i].get_str_tittle() << endl;
	}

	cout << endl;
}
void print1_2_2_1()
{
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int j = 1; j < vec_department.size(); j++)
	{
		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			if (vec_obj_teacher[i].get_idx_department() == j)
			{
				cout.width(10);
				cout << vec_obj_teacher[i].get_name();
				cout.width(18);
				cout << vec_obj_teacher[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_department();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_tittle() << endl;
			}
		}
	}
}
void print1_2_2_2()
{
	cout << "教师：" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称" << endl;
	for (int j = 1; j < vec_tittle.size(); j++)
	{
		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			if (vec_obj_teacher[i].get_idx_tittle() == j)
			{
				cout.width(10);
				cout << vec_obj_teacher[i].get_name();
				cout.width(18);
				cout << vec_obj_teacher[i].get_id().get_number();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_department();
				cout.width(14);
				cout << vec_obj_teacher[i].get_str_tittle() << endl;
			}
		}
	}
}

void print1_2_3()
{
	cout << "教师兼行政人员：" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;
	for (int i = 0; i < vec_obj_teacher.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_tea_off[i].Teacher::get_name();
		cout.width(18);
		cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_department();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_tittle();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_duty();
		cout.width(14);
		cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
	}
}
void print1_2_3_1()
{
	cout << "教师兼行政人员：" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;

	for (int j = 0; j < vec_politiclook.size(); j++)
	{
		for (int i = 0; i < vec_obj_tea_off.size(); i++)
		{
			if (vec_obj_tea_off[i].get_idx_politiclook() == j)
			{
				cout.width(10);
				cout << vec_obj_tea_off[i].Teacher::get_name();
				cout.width(18);
				cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_department();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_tittle();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_duty();
				cout.width(14);
				cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
			}
		}
	}
}
void print1_2_3_2()
{
	{
		cout << "教师兼行政人员：" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;

		for (int j = 0; j < vec_duty.size(); j++)
		{
			for (int i = 0; i < vec_obj_tea_off.size(); i++)
			{
				if (vec_obj_tea_off[i].get_idx_duty() == j)
				{
					cout.width(10);
					cout << vec_obj_tea_off[i].Teacher::get_name();
					cout.width(18);
					cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_department();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_tittle();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_duty();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
				}
			}
		}
	}
}
void print1_2_3_3()
{
	{
		cout << "教师兼行政人员：" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;

		for (int j = 0; j < vec_department.size(); j++)
		{
			for (int i = 0; i < vec_obj_tea_off.size(); i++)
			{
				if (vec_obj_tea_off[i].get_idx_department() == j)
				{
					cout.width(10);
					cout << vec_obj_tea_off[i].Teacher::get_name();
					cout.width(18);
					cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_department();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_tittle();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_duty();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
				}
			}
		}
	}
}
void print1_2_3_4()
{
	{
		cout << "教师兼行政人员：" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;

		for (int j = 0; j < vec_tittle.size(); j++)
		{
			for (int i = 0; i < vec_obj_tea_off.size(); i++)
			{
				if (vec_obj_tea_off[i].get_idx_tittle() == j)
				{
					cout.width(10);
					cout << vec_obj_tea_off[i].Teacher::get_name();
					cout.width(18);
					cout << vec_obj_tea_off[i].Teacher::get_id().get_number();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_department();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_tittle();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_duty();
					cout.width(14);
					cout << vec_obj_tea_off[i].get_str_politiclook() << endl;
				}
			}
		}
	}
}

void print1_2_4()
{
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int i = 0; i < vec_obj_reasecher.size(); i++)
	{
		cout.width(10);
		cout << vec_obj_reasecher[i].get_name();
		cout.width(18);
		cout << vec_obj_reasecher[i].get_id().get_number();
		cout.width(16);
		cout << vec_obj_reasecher[i].get_str_lab();
		cout.width(14);
		cout << vec_obj_reasecher[i].get_post() << endl;
	}
	cout << endl;
}
void print1_2_4_1()
{
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int j = 0; j < vec_lab.size(); j++)
	{
		for (int i = 0; i < vec_obj_reasecher.size(); i++)
		{
			if (vec_obj_reasecher[i].get_lab_index() == j)
			{
				cout.width(10);
				cout << vec_obj_reasecher[i].get_name();
				cout.width(18);
				cout << vec_obj_reasecher[i].get_id().get_number();
				cout.width(16);
				cout << vec_obj_reasecher[i].get_str_lab();
				cout.width(14);
				cout << vec_obj_reasecher[i].get_post() << endl;
			}
		}
	}
}
void print1_2_4_2()
{
	cout << "研究人员：" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "姓名      编号              所在实验室      实验室职务" << endl;
	for (int j = 0; j < vec_lab.size(); j++)
	{
		for (int i = 0; i < vec_obj_reasecher.size(); i++)
		{
			if (vec_obj_reasecher[i].get_lab_index() == j)
			{
				cout.width(10);
				cout << vec_obj_reasecher[i].get_name();
				cout.width(18);
				cout << vec_obj_reasecher[i].get_id().get_number();
				cout.width(16);
				cout << vec_obj_reasecher[i].get_str_lab();
				cout.width(14);
				cout << vec_obj_reasecher[i].get_post() << endl;
			}
		}
	}
}

void print1_3()//信息汇总
{
	cout << endl;
	cout << "信息统计：" << endl;
	cout << "共有教职工：" << vec_number.size() << "人" << endl;
	cout << "行政管理人员：" << vec_obj_official.size() << endl;
	cout << "教师兼行政管理人员：" << vec_obj_tea_off.size() << endl;
	cout << "教师：" << vec_obj_teacher.size() << endl;
	cout << "实验人员：" << vec_obj_reasecher.size() << endl;
	cout << "共有实验室：" << vec_lab.size() - 1 << "座" << endl;
	cout << "开设专业：" << vec_department.size() - 1 << "个" << endl;
	cout << endl;
	system("pause");
}

void print3_1()
{
	if (vec_int_3.size() == 0)
	{
		cout << "未找到该编号对应的人员，建议在统计功能中查阅后再次查找\n" << endl;
	}
	else
	{
		int idx = vec_int_3[1];
		cout << "详细人员信息如下:" << endl;
		cout << "------------------------------------------" << endl;
		switch (vec_int_3[0])
		{
		case 1:
			cout.setf(std::ios::left);
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_official[idx].get_name();
			cout.width(18);
			cout << vec_obj_official[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "行政职务：";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "政治面貌：";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 2:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_teacher[idx].get_name();
			cout.width(18);
			cout << vec_obj_teacher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在院系：";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "教师职称：";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_tittle();
			cout << endl;

			break;
		case 3:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_tea_off[idx].Teacher::get_name();
			cout.width(18);
			cout << vec_obj_tea_off[idx].Teacher::get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在院系：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "教师职称：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_tittle();
			cout << endl;

			cout.width(6);
			cout << "行政职务：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "政治面貌：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 4:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_reasecher[idx].get_name();
			cout.width(18);
			cout << vec_obj_reasecher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在实验室：";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_str_lab();
			cout << endl;

			cout.width(6);
			cout << "实验室职务：";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_post();
			cout << endl;
			cout << endl;
			break;
		}
	}
}
void print3_2()
{
	if (vec_int_3.size() == 0)
	{
		cout << "未找到该姓名对应的人员，建议在统计功能中查阅后再次查找\n" << endl;
	}
	else
	{
		int idx = vec_int_3[1];
		cout << "详细人员信息如下:" << endl;
		cout << "------------------------------------------" << endl;
		switch (vec_int_3[0])
		{
		case 1:
			cout.setf(std::ios::left);
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_official[idx].get_name();
			cout.width(18);
			cout << vec_obj_official[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "行政职务：";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "政治面貌：";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 2:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_teacher[idx].get_name();
			cout.width(18);
			cout << vec_obj_teacher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在院系：";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "教师职称：";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_tittle();
			cout << endl;

			break;
		case 3:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_tea_off[idx].Teacher::get_name();
			cout.width(18);
			cout << vec_obj_tea_off[idx].Teacher::get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在院系：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "教师职称：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_tittle();
			cout << endl;

			cout.width(6);
			cout << "行政职务：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "政治面貌：";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 4:
			cout.width(14);
			cout << "姓名";
			cout.width(18);
			cout << "编号";
			cout << endl;

			cout.width(14);
			cout << vec_obj_reasecher[idx].get_name();
			cout.width(18);
			cout << vec_obj_reasecher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "所在实验室：";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_str_lab();
			cout << endl;

			cout.width(6);
			cout << "实验室职务：";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_post();
			cout << endl;
			cout << endl;
			break;
		}
	}
}
void print3_3()
{
	;
}
void print3_4()
{
	;
}
void print3_5()
{
	;
}
void print3_6()
{
	;
}
void print3_7()
{
	;
}