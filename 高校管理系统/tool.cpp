#include "tool.h"
#include "Number.h"
#include "People.h"
#include "Reascher.h"
#include "Official.h"
#include "Teacher.h"
#include "Tea_Off.h"

extern vector<string> vec_lab;//�о���Ա���е�ʵ�����б�
extern vector<string> vec_department;//��ʦ���е�Ժϵ�б�
extern vector<string> vec_tittle;//��ʦ���ְ���б�
extern vector<string> vec_duty;//������Ա���ְ���б�
extern vector<string> vec_politiclook;//������ò�б�

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
			cout << "������" << key_words << ":";
		}
		else
		{
			cout << "������:" << endl;
		}

		gets_s(buffer);
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] < '0' || buffer[i]>'9')
			{
				cout << "����ֻ��Ϊ����!" << endl;
				flag = 0;
				break;
			}
			else//����flag�ж��Ƿ�������ַ���Ϊ����
			{
				flag = 1;
			}
		}
		//����flag = 1˵�����������û�����⣬��buffer�е�������ȡ����
		if (flag)
		{
			flag = 0;//����flag�����ж��Ƿ���Ϸ�Χ
			reasult = atoi(buffer);//��������ǽ��ַ��������е����ְ������һ����������

			if (reasult >= min && reasult <= max)//�����ж��Ƿ���[min,max]��
			{
				flag = 1;
			}
			else
			{
				cout << "������һ�������ֵ��" << endl;
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
	int reasult = read_int(1, vec_choice_list.size(), "ѡ��");

	vec_choice_list.clear();

	cout << endl;

	return reasult;
}
int find(vector<string> vec, string str)
{
	for (int i = 1; i < vec.size(); i++)//�˴�+������Ϊ�˱����з����޷��ŵ�warning
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
		cout << size << "." << "������һ��" << endl;
	}
	else if (B != NULL)
	{
		cout << B << endl;
	}

	return read_int(1, size, NULL);
}
bool find_people_in_number()
{
	cout << "\n��������Ҫ���ҵı�ţ�";
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
		vec_words.push_back("\n����Ա����\n��ѡ�����������:");
		vec_words.push_back("1.������Ա");
		vec_words.push_back("2.��ʦ");
		vec_words.push_back("3..��ʦ��������Ա");
		vec_words.push_back("4.�о���Ա");

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
		cout << "\n��������Ҫ���ҵ�������";
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
			vec_words.push_back("\n����Ա����\n��ѡ�����������:");
			vec_words.push_back("1.������Ա");
			vec_words.push_back("2.��ʦ");
			vec_words.push_back("3..��ʦ��������Ա");
			vec_words.push_back("4.�о���Ա");

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
	s0 = "δ֪ʵ����", s1 = "��ľ����ʵ����", s2 = "��е����ʵ����", s3 = "���ﻯѧʵ����", s4 = "����ʵ����";
	vec_lab.push_back(s0);
	vec_lab.push_back(s1);
	vec_lab.push_back(s2);
	vec_lab.push_back(s3);
	vec_lab.push_back(s4);
	//
	s0 = "δ֪ѧԺ", s1 = "�����ѧԺ", s2 = "��ѧԺ", s3 = "����ѧԺ", s4 = "ҽѧԺ";
	vec_department.push_back(s0);
	vec_department.push_back(s1);
	vec_department.push_back(s2);
	vec_department.push_back(s3);
	vec_department.push_back(s4);
	//
	s0 = "δְ֪��", s1 = "����", s2 = "������", s3 = "һ����ʦ", s4 = "������ʦ";
	vec_tittle.push_back(s0);
	vec_tittle.push_back(s1);
	vec_tittle.push_back(s2);
	vec_tittle.push_back(s3);
	vec_tittle.push_back(s4);
	//
	s0 = "δְ֪��", s1 = "У��", s2 = "��У��", s3 = "�칫������", s4 = "��������";
	vec_duty.push_back(s0);
	vec_duty.push_back(s1);
	vec_duty.push_back(s2);
	vec_duty.push_back(s3);
	vec_duty.push_back(s4);
	//
	s0 = "δ֪������ò", s1 = "��Ա", s2 = "������Ա", s3 = "�޵�����ʿ", s4 = "Ⱥ��";
	vec_politiclook.push_back(s0);
	vec_politiclook.push_back(s1);
	vec_politiclook.push_back(s2);
	vec_politiclook.push_back(s3);
	vec_politiclook.push_back(s4);

	//���ʼ��ӻ�������

	vec_obj_reasecher.push_back(Reasecher("����", 1, 35, Number(2020 - 35, 4, 5, 1, 1001), "�����о�Ա", 2));
	vec_obj_reasecher.push_back(Reasecher("����", 0, 27, Number(2020 - 27, 10, 17, 0, 4579), "�߼��о�Ա", 1));
	vec_obj_reasecher.push_back(Reasecher("����", 0, 29, Number(2020 - 29, 3, 7, 0, 1231), "�м��о�Ա", 3));
	vec_obj_reasecher.push_back(Reasecher("����", 1, 33, Number(2020 - 33, 12, 15, 1, 6731), "�о��鳤", 4));
	//
	vec_obj_official.push_back(Official("����", 1, 26, Number(2020 - 16, 5, 13, 1, 4452), 1, 2));
	vec_obj_official.push_back(Official("Ǯ��", 0, 40, Number(2020 - 40, 7, 19, 0, 4921), 2, 3));
	vec_obj_official.push_back(Official("���", 1, 32, Number(2020 - 32, 2, 21, 1, 3378), 3, 1));
	vec_obj_official.push_back(Official("��ʮ", 0, 37, Number(2020 - 37, 1, 10, 0, 2525), 4, 4));
	//
	vec_obj_teacher.push_back(Teacher("��ʮһ", 1, 29, Number(2020 - 29, 7, 7, 1, 3315), 3, 2));
	vec_obj_teacher.push_back(Teacher("֣ʮ��", 1, 34, Number(2020 - 34, 3, 17, 1, 3327), 4, 2));
	vec_obj_teacher.push_back(Teacher("��ʮ��", 0, 45, Number(2020 - 45, 1, 27, 0, 15), 2, 3));
	vec_obj_teacher.push_back(Teacher("��ʮ��", 0, 40, Number(2020 - 40, 7, 7, 0, 99), 1, 1));
	//
	vec_obj_tea_off.push_back(Tea_Off("��ʮ��", 0, 41, Number(2020 - 41, 6, 20, 0, 453), 2, 1, 3, 1));
	vec_obj_tea_off.push_back(Tea_Off("κʮ��", 0, 41, Number(2020 - 41, 11, 20, 0, 543), 3, 4, 1, 2));
	vec_obj_tea_off.push_back(Tea_Off("��ʮ��", 1, 50, Number(2020 - 50, 12, 1, 1, 4253), 4, 2, 4, 3));
	vec_obj_tea_off.push_back(Tea_Off("��ʮ��", 1, 48, Number(2020 - 48, 1, 5, 1, 2453), 1, 3, 2, 4));

	vec_number.clear();
	vec_number.push_back("δ֪���");
	vec_name.clear();
	vec_name.push_back("δ֪����");

	for (int i = 0; i < 4; i++)
	{
		//����number������ֿⲻ��Ҫ����˳�����ȫ�̻�����Ӽ���
		vec_number.push_back(vec_obj_official[i].get_id().get_number());
		vec_number.push_back(vec_obj_reasecher[i].get_id().get_number());
		vec_number.push_back(vec_obj_teacher[i].get_id().get_number());
		vec_number.push_back(vec_obj_tea_off[i].Teacher::get_id().get_number());//�˴���ʽָ�����ø���ĳ�Ա����
		vec_name.push_back(vec_obj_official[i].get_name());
		vec_name.push_back(vec_obj_tea_off[i].Teacher::get_name());
		vec_name.push_back(vec_obj_reasecher[i].get_name());
		vec_name.push_back(vec_obj_teacher[i].get_name());
	}

}

void information_save()
{
	ofstream outfile;
	cout << "������Ա����Ϣ�Ѿ�������D:\\system.txt��\n" << endl;
	outfile.open("D:\\system.txt");
	if (outfile.is_open())
	{
		outfile << "������Ա��" << endl;
		outfile << "-------------------------------------------------" << endl;

		outfile << "����      ���              ����ְ��      ������ò" << endl;
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
		outfile << "��ʦ��" << endl;
		outfile << "---------------------------------------------------" << endl;

		outfile << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
		outfile << "��ʦ��������Ա��" << endl;
		outfile << "----------------------------------------------------------------------------" << endl;

		outfile << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;
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
		outfile << "�о���Ա��" << endl;
		outfile << "-------------------------------------------------------" << endl;

		outfile << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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
		cout << "����δ֪�Ĵ�����Ϣδ�ܳɹ�����,������ֹ" << endl;
		exit(-1);
	}
	outfile.close();


}