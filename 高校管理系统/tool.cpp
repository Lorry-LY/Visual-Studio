#include "tool.h"
#include "Number.h"
#include "People.h"
#include "Reascher.h"
#include "Official.h"
#include "Teacher.h"
#include "Tea_Off.h"

extern vector<string> vec_lab;//研究人员类中的实验室列表
extern vector<string> vec_department;//教师类中的院系列表
extern vector<string> vec_tittle;//教师类的职称列表
extern vector<string> vec_duty;//行政人员类的职务列表
extern vector<string> vec_politiclook;//政治面貌列表

extern vector<Reasecher> vec_obj_reasecher;
extern vector<Teacher> vec_obj_teacher;
extern vector<Official> vec_obj_official;
extern vector<Tea_Off> vec_obj_tea_off;

extern vector<string> vec_number;
extern vector<string> vec_name;

extern int int_1, int_2, int_3;
extern vector<const char*> vec_words;
extern vector<int> vec_int_1, vec_int_2, vec_int_3;

int read_int(int min, int max, const char* key_words)
{
	char buffer[50] = { '\0' };
	bool flag = 0;
	int reasult;
	while (1)
	{
		if (key_words != NULL)
		{
			cout << "请输入" << key_words << ":";
		}
		else
		{
			cout << "请输入:" << endl;
		}

		gets_s(buffer);
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] < '0' || buffer[i]>'9')
			{
				cout << "输入只能为数字!" << endl;
				flag = 0;
				break;
			}
			else//先用flag判断是否输入的字符均为数字
			{
				flag = 1;
			}
		}
		//到此flag = 1说明输入的数字没有问题，将buffer中的数字提取出来
		if (flag)
		{
			flag = 0;//重置flag用以判断是否符合范围
			reasult = atoi(buffer);//这个函数是将字符型数组中的数字按序组成一个整数返回

			if (reasult >= min && reasult <= max)//用于判断是否处在[min,max]中
			{
				flag = 1;
			}
			else
			{
				cout << "请输入一个合理的值！" << endl;
			}
		}
		if (flag)
			break;
	}

	return reasult;
}
int output_list(vector<const char*>& vec_choice_list)
{
	for (int i = 0; i < vec_choice_list.size(); i++)
	{
		cout << vec_choice_list[i] << endl;
	}
	int reasult = read_int(1, vec_choice_list.size(), "选项");

	vec_choice_list.clear();

	cout << endl;

	return reasult;
}
int find(vector<string> vec, string str)
{
	for (int i = 1; i < vec.size(); i++)//此处+运算是为了避免有符号无符号的warning
	{
		if (vec[i] == str)
		{
			return i;
		}
	}

	return -1;
}
int choose_list(vector<string> vec, const char* A, const char* B)
{
	int size = vec.size();
	if (A != NULL)
	{
		cout << A << endl;
	}
	for (int i = 1; i < size; i++)
	{
		cout << i << "." << vec[i] << endl;
	}
	if (B == "back")
	{
		cout << size << "." << "返回上一级" << endl;
	}
	else if (B != NULL)
	{
		cout << B << endl;
	}

	return read_int(1, size, NULL);
}
bool find_people_in_number()
{
	cout << "\n请输入你要查找的编号：";
	char ch[18] = { '\0' };
	cin.getline(ch, 18);
	cin.clear();
	cin.sync();

	string str = ch;

	int idx = find(vec_number, str);
	if (idx == -1)
	{
		return false;
	}
	else
	{
		vec_words.clear();
		vec_words.push_back("\n此人员存在\n请选择其所属类别:");
		vec_words.push_back("1.行政人员");
		vec_words.push_back("2.教师");
		vec_words.push_back("3..教师兼行政人员");
		vec_words.push_back("4.研究人员");

		vec_int_3.clear();


		bool flag = 0;
		for (int i = 0; i < vec_obj_official.size(); i++)
		{
			if (vec_obj_official[i].get_id().get_number() == str)
			{
				vec_int_3.push_back(1);
				vec_int_3.push_back(i);
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			return true;
		}

		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			if (vec_obj_teacher[i].get_id().get_number() == str)
			{
				vec_int_3.push_back(2);
				vec_int_3.push_back(i);
				break;
			}
		}
		if (flag)
		{
			return true;
		}

		for (int i = 0; i < vec_obj_tea_off.size(); i++)
		{
			if (vec_obj_tea_off[i].Teacher::get_id().get_number() == str)
			{
				vec_int_3.push_back(3);
				vec_int_3.push_back(i);
				break;
			}
		}
		if (flag)
		{
			return true;
		}

		for (int i = 0; i < vec_obj_reasecher.size(); i++)
		{
			if (vec_obj_reasecher[i].get_id().get_number() == str)
			{
				vec_int_3.push_back(4);
				vec_int_3.push_back(i);
				break;
			}
		}

		return true;
	}
}
bool find_people_in_name()
{
	{
		cout << "\n请输入你要查找的姓名：";
		char ch[16] = { '\0' };
		cin.getline(ch, 16);
		cin.clear();
		cin.sync();

		string str = ch;

		int idx = find(vec_name, str);
		if (idx == -1)
		{
			return false;
		}
		else
		{
			vec_words.clear();
			vec_words.push_back("\n此人员存在\n请选择其所属类别:");
			vec_words.push_back("1.行政人员");
			vec_words.push_back("2.教师");
			vec_words.push_back("3..教师兼行政人员");
			vec_words.push_back("4.研究人员");

			vec_int_3.clear();


			bool flag = 0;
			for (int i = 0; i < vec_obj_official.size(); i++)
			{
				if (vec_obj_official[i].get_name() == str)
				{
					vec_int_3.push_back(1);
					vec_int_3.push_back(i);
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				return true;
			}

			for (int i = 0; i < vec_obj_teacher.size(); i++)
			{
				if (vec_obj_teacher[i].get_name() == str)
				{
					vec_int_3.push_back(2);
					vec_int_3.push_back(i);
					break;
				}
			}
			if (flag)
			{
				return true;
			}

			for (int i = 0; i < vec_obj_tea_off.size(); i++)
			{
				if (vec_obj_tea_off[i].Teacher::get_name() == str)
				{
					vec_int_3.push_back(3);
					vec_int_3.push_back(i);
					break;
				}
			}
			if (flag)
			{
				return true;
			}

			for (int i = 0; i < vec_obj_reasecher.size(); i++)
			{
				if (vec_obj_reasecher[i].get_name() == str)
				{
					vec_int_3.push_back(4);
					vec_int_3.push_back(i);
					break;
				}
			}

			return true;
		}
	}
}

void creat_all()
{
	string s0, s1, s2, s3, s4;
	//
	s0 = "未知实验室", s1 = "土木工程实验室", s2 = "机械工程实验室", s3 = "生物化学实验室", s4 = "物理实验室";
	vec_lab.push_back(s0);
	vec_lab.push_back(s1);
	vec_lab.push_back(s2);
	vec_lab.push_back(s3);
	vec_lab.push_back(s4);
	//
	s0 = "未知学院", s1 = "计算机学院", s2 = "文学院", s3 = "物理学院", s4 = "医学院";
	vec_department.push_back(s0);
	vec_department.push_back(s1);
	vec_department.push_back(s2);
	vec_department.push_back(s3);
	vec_department.push_back(s4);
	//
	s0 = "未知职称", s1 = "教授", s2 = "副教授", s3 = "一级讲师", s4 = "二级讲师";
	vec_tittle.push_back(s0);
	vec_tittle.push_back(s1);
	vec_tittle.push_back(s2);
	vec_tittle.push_back(s3);
	vec_tittle.push_back(s4);
	//
	s0 = "未知职务", s1 = "校长", s2 = "副校长", s3 = "办公室主任", s4 = "行政经理";
	vec_duty.push_back(s0);
	vec_duty.push_back(s1);
	vec_duty.push_back(s2);
	vec_duty.push_back(s3);
	vec_duty.push_back(s4);
	//
	s0 = "未知政治面貌", s1 = "党员", s2 = "共青团员", s3 = "无党派人士", s4 = "群众";
	vec_politiclook.push_back(s0);
	vec_politiclook.push_back(s1);
	vec_politiclook.push_back(s2);
	vec_politiclook.push_back(s3);
	vec_politiclook.push_back(s4);

	//随后开始添加基础对象

	vec_obj_reasecher.push_back(Reasecher("张三", 1, 35, Number(2020 - 35, 4, 5, 1, 1001), "助理研究员", 2));
	vec_obj_reasecher.push_back(Reasecher("李四", 0, 27, Number(2020 - 27, 10, 17, 0, 4579), "高级研究员", 1));
	vec_obj_reasecher.push_back(Reasecher("王五", 0, 29, Number(2020 - 29, 3, 7, 0, 1231), "中级研究员", 3));
	vec_obj_reasecher.push_back(Reasecher("赵六", 1, 33, Number(2020 - 33, 12, 15, 1, 6731), "研究组长", 4));
	//
	vec_obj_official.push_back(Official("黄七", 1, 26, Number(2020 - 16, 5, 13, 1, 4452), 1, 2));
	vec_obj_official.push_back(Official("钱八", 0, 40, Number(2020 - 40, 7, 19, 0, 4921), 2, 3));
	vec_obj_official.push_back(Official("孙九", 1, 32, Number(2020 - 32, 2, 21, 1, 3378), 3, 1));
	vec_obj_official.push_back(Official("周十", 0, 37, Number(2020 - 37, 1, 10, 0, 2525), 4, 4));
	//
	vec_obj_teacher.push_back(Teacher("吴十一", 1, 29, Number(2020 - 29, 7, 7, 1, 3315), 3, 2));
	vec_obj_teacher.push_back(Teacher("郑十二", 1, 34, Number(2020 - 34, 3, 17, 1, 3327), 4, 2));
	vec_obj_teacher.push_back(Teacher("冯十三", 0, 45, Number(2020 - 45, 1, 27, 0, 15), 2, 3));
	vec_obj_teacher.push_back(Teacher("陈十四", 0, 40, Number(2020 - 40, 7, 7, 0, 99), 1, 1));
	//
	vec_obj_tea_off.push_back(Tea_Off("楚十五", 0, 41, Number(2020 - 41, 6, 20, 0, 453), 2, 1, 3, 1));
	vec_obj_tea_off.push_back(Tea_Off("魏十六", 0, 41, Number(2020 - 41, 11, 20, 0, 543), 3, 4, 1, 2));
	vec_obj_tea_off.push_back(Tea_Off("蒋十七", 1, 50, Number(2020 - 50, 12, 1, 1, 4253), 4, 2, 4, 3));
	vec_obj_tea_off.push_back(Tea_Off("沈十八", 1, 48, Number(2020 - 48, 1, 5, 1, 2453), 1, 3, 2, 4));

	vec_number.clear();
	vec_number.push_back("未知编号");
	vec_name.clear();
	vec_name.push_back("未知姓名");

	for (int i = 0; i < 4; i++)
	{
		//由于number库和名字库不需要考虑顺序，因此全程混序添加即可
		vec_number.push_back(vec_obj_official[i].get_id().get_number());
		vec_number.push_back(vec_obj_reasecher[i].get_id().get_number());
		vec_number.push_back(vec_obj_teacher[i].get_id().get_number());
		vec_number.push_back(vec_obj_tea_off[i].Teacher::get_id().get_number());//此处显式指定调用父类的成员函数
		vec_name.push_back(vec_obj_official[i].get_name());
		vec_name.push_back(vec_obj_tea_off[i].Teacher::get_name());
		vec_name.push_back(vec_obj_reasecher[i].get_name());
		vec_name.push_back(vec_obj_teacher[i].get_name());
	}

}

void information_save()
{
	ofstream outfile;
	cout << "所有人员的信息已经保存在D:\\system.txt中\n" << endl;
	outfile.open("D:\\system.txt");
	if (outfile.is_open())
	{
		outfile << "行政人员：" << endl;
		outfile << "-------------------------------------------------" << endl;

		outfile << "姓名      编号              行政职务      政治面貌" << endl;
		outfile.setf(std::ios::left);

		for (int i = 0; i < vec_obj_official.size(); i++)
		{
			outfile.width(10);
			outfile << vec_obj_official[i].get_name();
			outfile.width(18);
			outfile << vec_obj_official[i].get_id().get_number();
			outfile.width(14);
			outfile << vec_obj_official[i].get_str_duty();
			outfile.width(14);
			outfile << vec_obj_official[i].get_str_politiclook() << endl;
		}

		outfile << endl;
		outfile << "教师：" << endl;
		outfile << "---------------------------------------------------" << endl;

		outfile << "姓名      编号              所在院系      教师职称" << endl;
		for (int i = 0; i < vec_obj_teacher.size(); i++)
		{
			outfile.width(10);
			outfile << vec_obj_teacher[i].get_name();
			outfile.width(18);
			outfile << vec_obj_teacher[i].get_id().get_number();
			outfile.width(14);
			outfile << vec_obj_teacher[i].get_str_department();
			outfile.width(14);
			outfile << vec_obj_teacher[i].get_str_tittle() << endl;
		}

		outfile << endl;
		outfile << "教师兼行政人员：" << endl;
		outfile << "----------------------------------------------------------------------------" << endl;

		outfile << "姓名      编号              所在院系      教师职称      行政职务      政治面貌" << endl;
		for (int i = 0; i < vec_obj_tea_off.size(); i++)
		{
			outfile.width(10);
			outfile << vec_obj_tea_off[i].Teacher::get_name();
			outfile.width(18);
			outfile << vec_obj_tea_off[i].Teacher::get_id().get_number();
			outfile.width(14);
			outfile << vec_obj_tea_off[i].get_str_department();
			outfile.width(14);
			outfile << vec_obj_tea_off[i].get_str_tittle();
			outfile.width(14);
			outfile << vec_obj_tea_off[i].get_str_duty();
			outfile.width(14);
			outfile << vec_obj_tea_off[i].get_str_politiclook() << endl;
		}

		outfile << endl;
		outfile << "研究人员：" << endl;
		outfile << "-------------------------------------------------------" << endl;

		outfile << "姓名      编号              所在实验室      实验室职务" << endl;
		for (int i = 0; i < vec_obj_reasecher.size(); i++)
		{
			outfile.width(10);
			outfile << vec_obj_reasecher[i].get_name();
			outfile.width(18);
			outfile << vec_obj_reasecher[i].get_id().get_number();
			outfile.width(16);
			outfile << vec_obj_reasecher[i].get_str_lab();
			outfile.width(14);
			outfile << vec_obj_reasecher[i].get_post() << endl;
		}
		outfile << endl;
	}
	else
	{
		cout << "由于未知的错误，信息未能成功保存,程序终止" << endl;
		exit(-1);
	}
	outfile.close();


}