#pragma once
#include "tool.h"
#include "Reascher.h"
#include "Tea_Off.h"
#include "choice.h"


/*
	���cpp�ļ��洢�����е�ѡ�����
	�����Ĺ��ܼ���������鿴.h
*/

//��������ȫ�ֱ���
extern int int_1, int_2, int_3;
extern string str_1, str_2, str_3;
extern vector<string> vec_str_1, vec_str_2, vec_str_3;
extern vector<int> vec_int_1, vec_int_2, vec_int_3;
extern vector<const char*> vec_words;

extern vector<string> vec_lab;//�о���Ա���е�ʵ�����б�
extern vector<string> vec_department;//��ʦ���е�Ժϵ�б�
extern vector<string> vec_tittle;//��ʦ���ְ���б�
extern vector<string> vec_duty;//������Ա���ְ���б�
extern vector<string> vec_politiclook;//������ò�б�

//�����б�
extern vector<Reasecher> vec_obj_reasecher;
extern vector<Teacher> vec_obj_teacher;
extern vector<Official> vec_obj_official;
extern vector<Tea_Off> vec_obj_tea_off;

//number���name��
extern vector<string> vec_number;
extern vector<string> vec_name;

//����ʵ�ֲ���

//choice
void choice0()
{
	//���еı�־λΪ1ʱ������һ����Ĭ��Ϊ0ͣ���ڱ���

	while (1)
	{

		bool flag_0 = 0;//���˵��˳���־
		int choice_0;//���˵�ѡ��

		vec_words.clear();
		vec_words.push_back("1.ͳ����Ա��Ϣ");
		vec_words.push_back("2.���");
		vec_words.push_back("3.����");
		vec_words.push_back("4.�˳�ϵͳ");

		choice_0 = output_list(vec_words);

		switch (choice_0)
		{
		case 1:
			//ͳ��
			choice1();
			break;
		case 2:
			//����
			choice2();
			break;
		case 3:
			//����
			choice3();
			break;
		case 4:
			//�˳�ϵͳ
			flag_0 = 1;
			break;
		}

		if (flag_0)
		{
			break;
		}
	}

	cout << "��л���ʹ��" << endl;
}
void choice1()
{
	bool flag_1 = 0;
	int choice1;
	while (1)
	{
		vec_words.clear();
		vec_words.push_back("1.�鿴������Ա����������Ա��𡢱��");
		vec_words.push_back("2.�鿴�ض��������Ա");
		vec_words.push_back("3.��Ա��Ϣ����");
		vec_words.push_back("4.������һ��");

		choice1 = output_list(vec_words);

		switch (choice1)
		{
		case 1:
			//�鿴������Ա����������Ա��𡢱��
			print1_1();
			choice1_1();
			break;
		case 2:
			//�鿴�ض��������Ա
			choice1_2();
			break;
		case 3:
			//��Ϣͳ��
			choice1_3();
			break;
		case 4:
			//������һ��
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
		vec_words.push_back("1.����������");
		vec_words.push_back("2.���Ա�����");
		vec_words.push_back("3.������һ��");

		choice1_1 = output_list(vec_words);

		switch (choice1_1)
		{
		case 1:
			//�����콫������Ա����Ϣ���
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
		vec_words.push_back("1.������Ա");
		vec_words.push_back("2.��ʦ");
		vec_words.push_back("3.��ʦ��������Ա");
		vec_words.push_back("4.�о���Ա");
		vec_words.push_back("5.������һ��");

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
		vec_words.push_back("1.��������ò����");
		vec_words.push_back("2.������ְ������");
		vec_words.push_back("3.������һ��");
		choice1_2_1 = output_list(vec_words);

		switch (choice1_2_1)
		{
		case 1:
			//��������ò����
			operate1_2_1_1();
			print1_2_1_1();
			break;
		case 2:
			//������ְ������
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
		vec_words.push_back("1.������Ժϵ����");
		vec_words.push_back("2.����ʦְ������");
		vec_words.push_back("3.������һ��");
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
		vec_words.push_back("1.��������ò����");
		vec_words.push_back("2.������ְ������");
		vec_words.push_back("3.������Ժϵ����");
		vec_words.push_back("4.����ʦְ������");
		vec_words.push_back("5.������һ��");

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
		vec_words.push_back("1.������ʵ��������");
		vec_words.push_back("2.��ʵ����ְ������");
		vec_words.push_back("3.������һ��");

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
		vec_words.push_back("��ѡ����Ҫ��ӵ���Ա�����");
		vec_words.push_back("1.������Ա");
		vec_words.push_back("2.��ʦ");
		vec_words.push_back("3.��ʦ��������Ա");
		vec_words.push_back("4.�о���Ա");
		vec_words.push_back("5.ѧԺ");
		vec_words.push_back("6.����ְ��");
		vec_words.push_back("7.��ʦְ��");
		vec_words.push_back("8.ʵ����");
		vec_words.push_back("9.������ò");
		vec_words.push_back("10.������һ��");

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
		vec_words.push_back("1.����Ų�����Ա");
		vec_words.push_back("2.������������Ա");
		vec_words.push_back("3.����ѧԺ");
		vec_words.push_back("4.��������ְ��");
		vec_words.push_back("5.���ҽ�ʦְ��");
		vec_words.push_back("6.����������ò");
		vec_words.push_back("7.����ʵ����");
		vec_words.push_back("8.������һ��");

		choice3 = output_list(vec_words);

		switch (choice3)
		{
		case 1:
			if (find_people_in_number())//�ҵ���
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
		vec_words.push_back("1.�༭����");
		vec_words.push_back("2.ɾ����Ա");
		vec_words.push_back("3.������һ��");

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
		vec_words.push_back("1.�༭����");
		vec_words.push_back("2.ɾ����Ա");
		vec_words.push_back("3.������һ��");

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

void operate1_2_1_1()//��������ò����,vec_int_temp1����洢������֮������official������vec_obj_official�е��±�
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

void operate2_1()//���official
{
	cout << "��������/��������,��󳤶�Ϊ16���ַ����������ȵĲ��ֽ����ضϣ�" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "�������(������");
	int_2 = read_int(1, 12, "�����·�(������");

	if (int_2 == 2)//�Ƕ���
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//������
		{
			int_3 = read_int(1, 29, "��������(������");
		}
		else
		{
			int_3 = read_int(1, 28, "��������(������");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "��������(������");
	}
	else
	{
		int_3 = read_int(1, 30, "��������(������");
	}

	int _sex = read_int(1, 2, "��ѡ����/�����Ա�,\n1��\n2Ů\n���ѡ��");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "������������λβ��");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "β���ظ�������������" << endl;
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

	idx_duty = choose_list(vec_duty, "\n��ѡ������ְ��", "���û������Ҫ��ְ���뷵�����˵���ӡ�");
	idx_politiclook = choose_list(vec_politiclook, "\n��ѡ��������ò", "���û�к��ʵ�������ò���뷵�����˵���ӡ�");

	//����Ϊֹ�����е������Ѿ��ռ����,�ڶ����б�����Ӽ���
	vec_obj_official.push_back(Official(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_politiclook, idx_duty));
	cout << "\n�Ѿ��ɹ���Ӹ���Ա,�����޸��뵽���˵��в��Ҳ��޸ġ�\n" << endl;
	vec_number.push_back(vec_obj_official.back().get_id().get_number());
	vec_name.push_back(vec_obj_official.back().get_name());
}
void operate2_2()
{
	cout << "��������/��������,��󳤶�Ϊ16���ַ����������ȵĲ��ֽ����ضϣ�" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "�������(������");
	int_2 = read_int(1, 12, "�����·�(������");

	if (int_2 == 2)//�Ƕ���
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//������
		{
			int_3 = read_int(1, 29, "��������(������");
		}
		else
		{
			int_3 = read_int(1, 28, "��������(������");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "��������(������");
	}
	else
	{
		int_3 = read_int(1, 30, "��������(������");
	}

	int _sex = read_int(1, 2, "��ѡ����/�����Ա�,\n1��\n2Ů\n���ѡ��");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "������������λβ��");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "β���ظ�������������" << endl;
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

	idx_tittle = choose_list(vec_tittle, "\n��ѡ���ʦְ�ƣ�", "���û������Ҫ��ְ�ƣ��뷵�����˵���ӡ�");
	idx_department = choose_list(vec_department, "\n��ѡ������Ժϵ", "���û�к��ʵ�Ժϵ���뷵�����˵���ӡ�");

	//����Ϊֹ�����е������Ѿ��ռ����,�ڶ����б�����Ӽ���
	vec_obj_teacher.push_back(Teacher(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_tittle, idx_department));
	cout << "\n�Ѿ��ɹ���Ӹ���Ա,�����޸��뵽���˵��в��Ҳ��޸ġ�\n" << endl;
	vec_number.push_back(vec_obj_teacher.back().get_id().get_number());
	vec_name.push_back(vec_obj_teacher.back().get_name());

}
void operate2_3()
{
	cout << "��������/��������,��󳤶�Ϊ16���ַ����������ȵĲ��ֽ����ضϣ�" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "�������(������");
	int_2 = read_int(1, 12, "�����·�(������");

	if (int_2 == 2)//�Ƕ���
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//������
		{
			int_3 = read_int(1, 29, "��������(������");
		}
		else
		{
			int_3 = read_int(1, 28, "��������(������");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "��������(������");
	}
	else
	{
		int_3 = read_int(1, 30, "��������(������");
	}

	int _sex = read_int(1, 2, "��ѡ����/�����Ա�,\n1��\n2Ů\n���ѡ��");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "������������λβ��");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "β���ظ�������������" << endl;
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

	idx_tittle = choose_list(vec_tittle, "\n��ѡ���ʦְ�ƣ�", "���û������Ҫ��ְ�ƣ��뷵�����˵���ӡ�");
	idx_department = choose_list(vec_department, "\n��ѡ������Ժϵ", "���û�к��ʵ�Ժϵ���뷵�����˵���ӡ�");
	idx_duty = choose_list(vec_duty, "\n��ѡ������ְ��", "���û������Ҫ��ְ���뷵�����˵���ӡ�");
	idx_politiclook = choose_list(vec_politiclook, "\n��ѡ��������ò", "���û�к��ʵ�������ò���뷵�����˵���ӡ�");

	//����Ϊֹ�����е������Ѿ��ռ����,�ڶ����б�����Ӽ���
	vec_obj_tea_off.push_back(Tea_Off(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), idx_duty, idx_politiclook, idx_politiclook, idx_duty));
	cout << "\n�Ѿ��ɹ���Ӹ���Ա,�����޸��뵽���˵��в��Ҳ��޸ġ�\n" << endl;
	vec_number.push_back(vec_obj_tea_off.back().Teacher::get_id().get_number());
	vec_name.push_back(vec_obj_tea_off.back().Teacher::get_name());
}
void operate2_4()
{
	cout << "��������/��������,��󳤶�Ϊ16���ַ����������ȵĲ��ֽ����ضϣ�" << endl;
	char name[16] = { '\0' };
	cin.getline(name, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_1 = name;

	int_1 = read_int(1950, 2020, "�������(������");
	int_2 = read_int(1, 12, "�����·�(������");

	if (int_2 == 2)//�Ƕ���
	{
		if (int_1 % 4 == 0 && int_1 % 100 != 0 && int_1 % 400 == 0)//������
		{
			int_3 = read_int(1, 29, "��������(������");
		}
		else
		{
			int_3 = read_int(1, 28, "��������(������");
		}
	}
	else if (int_2 == 1 || int_2 == 3 || int_2 == 5 || int_2 == 7 || int_2 == 8 || int_2 == 10 || int_2 == 12)
	{
		int_3 = read_int(1, 31, "��������(������");
	}
	else
	{
		int_3 = read_int(1, 30, "��������(������");
	}

	int _sex = read_int(1, 2, "��ѡ����/�����Ա�,\n1��\n2Ů\n���ѡ��");

	bool sex = _sex == 1 ? 0 : 1;

	bool flag = 0;
	int test_number;

	while (1)
	{
		test_number = read_int(1, 9999, "������������λβ��");
		if (find(vec_number, to_string(test_number)) != -1)
		{
			cout << "β���ظ�������������" << endl;
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

	cout << "��������/������ʵ���ҵ�ְ��" << endl;
	char post[16] = { '\0' };
	cin.getline(post, 16);
	cin.clear();
	cin.ignore(1024, '\n');
	str_2 = post;

	int idx_lab = choose_list(vec_lab, "\n��ѡ����/�����ڵ�ʵ���ң�", "���û�к��ʵ�ʵ���ң��������˵������.");

	vec_obj_reasecher.push_back(Reasecher(str_1, sex, 2020 - int_1, Number(int_1, int_2, int_3, sex, test_number), str_2, idx_lab));
	vec_number.push_back(vec_obj_reasecher.back().get_id().get_number());
	vec_name.push_back(vec_obj_reasecher.back().get_name());
}
void operate2_5()//���ѧԺ
{
	cout << "��ǰѧԺ���У�" << endl;
	for (int i = 0; i < vec_department.size(); i++)
	{
		cout << vec_department[i] << endl;
	}
	cout << "��������Ҫ��ӵ���ѧԺ����XXѧԺ,���15���ַ���" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "�Ѿ��ɹ����" << endl;
}
void operate2_6()
{
	cout << "��ǰ��������ְ��" << endl;
	for (int i = 0; i < vec_duty.size(); i++)
	{
		cout << vec_duty[i] << endl;
	}
	cout << "��������Ҫ��ӵ���ְ��,���15���ַ���" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "�Ѿ��ɹ���Ӹ�ְ��." << endl;
}
void operate2_7()
{
	cout << "��ǰ���н�ʦְ�ƣ�" << endl;
	for (int i = 0; i < vec_tittle.size(); i++)
	{
		cout << vec_tittle[i] << endl;
	}
	cout << "��������Ҫ��ӵ���ְ��,���15���ַ���" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "�Ѿ��ɹ���Ӹ�ְ��." << endl;
}
void operate2_8()
{
	cout << "��ǰ����ʵ���ң�" << endl;
	for (int i = 0; i < vec_lab.size(); i++)
	{
		cout << vec_lab[i] << endl;
	}
	cout << "��������Ҫ��ӵ���ʵ���ң���XXʵ����,���25���ַ���" << endl;
	char name[25];
	cin.getline(name, 25);
	vec_department.push_back(name);

	cout << "�Ѿ��ɹ���Ӹ�ʵ����." << endl;
}
void operate2_9()
{
	cout << "��ǰ����������ò��" << endl;
	for (int i = 0; i < vec_politiclook.size(); i++)
	{
		cout << vec_politiclook[i] << endl;
	}
	cout << "��������Ҫ��ӵ���������ò,���15���ַ���" << endl;
	char name[15];
	cin.getline(name, 15);
	vec_department.push_back(name);

	cout << "�Ѿ��ɹ���Ӹ�������ò." << endl;
}

void operate3_1_1()
{
	vec_words.clear();
	vec_words.push_back("��ѡ����Ҫ�޸ĵ����ϣ�");

	int choice;
	char ch[16];
	string str;

	switch (vec_int_3[0])
	{
	case 1:
		vec_words.push_back("����ְ��");
		vec_words.push_back("������ò");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_official[vec_int_3[1]].ser_duty(choose_list(vec_duty, "��ѡ���µ�����ְ��", NULL));
			break;
		case 2:
			vec_obj_official[vec_int_3[1]].set_poloticlook(choose_list(vec_politiclook, "��ѡ���µ�������ò", NULL));
			break;
		}
		break;
	case 2:
		vec_words.push_back("��ʦְ��");
		vec_words.push_back("����Ժϵ");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_teacher[vec_int_3[1]].set_tittle(choose_list(vec_tittle, "��ѡ���µĽ�ʦְ��", NULL));
			break;
		case 2:
			vec_obj_teacher[vec_int_3[1]].set_department(choose_list(vec_department, "��ѡ���µ�����Ժϵ", NULL));
			break;
		}
		break;
	case 3:
		vec_words.push_back("����ְ��");
		vec_words.push_back("������ò");
		vec_words.push_back("��ʦְ��");
		vec_words.push_back("����Ժϵ");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_tea_off[vec_int_3[1]].ser_duty(choose_list(vec_duty, "��ѡ���µ�����ְ��", NULL));
			break;
		case 2:
			vec_obj_tea_off[vec_int_3[1]].set_poloticlook(choose_list(vec_politiclook, "��ѡ���µ�������ò", NULL));
			break;
		case 3:
			vec_obj_tea_off[vec_int_3[1]].set_tittle(choose_list(vec_tittle, "��ѡ���µĽ�ʦְ��", NULL));
			break;
		case 4:
			vec_obj_tea_off[vec_int_3[1]].set_department(choose_list(vec_department, "��ѡ���µ�����Ժϵ", NULL));
			break;
		}
		break;
	case 4:
		vec_words.push_back("����ʵ����");
		vec_words.push_back("ʵ����ְ��");

		choice = output_list(vec_words);

		switch (choice)
		{
		case 1:
			vec_obj_reasecher[vec_int_3[1]].ser_lab(choose_list(vec_lab, "��ѡ���µ�ʵ����", NULL));
			break;
		case 2:
			cout << "�������µ�ʵ����ְ��,���16�ַ���";
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

	cout << "�Ѿ��ɹ�ɾ����������Ϣ\n" << endl;
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
	cout << "��������Ҫ��ѯ������:";
	cin.getline(ch, 18);
	string str = ch;

	if (find(vec_department, str) != -1)
	{
		cout << "����" << str << endl;
	}
	else
	{
		cout << str << "������" << endl;
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
	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��������Ա��" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;
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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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

	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��������Ա��" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;
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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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
	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��������Ա��" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;
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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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
	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "������Ա��" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << "����      ���              ����ְ��      ������ò" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��" << endl;
	cout << "---------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��" << endl;
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
	cout << "��ʦ��������Ա��" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;
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
	cout << "��ʦ��������Ա��" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;

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
		cout << "��ʦ��������Ա��" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;

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
		cout << "��ʦ��������Ա��" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;

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
		cout << "��ʦ��������Ա��" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

		cout << "����      ���              ����Ժϵ      ��ʦְ��      ����ְ��      ������ò" << endl;

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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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
	cout << "�о���Ա��" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << "����      ���              ����ʵ����      ʵ����ְ��" << endl;
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

void print1_3()//��Ϣ����
{
	cout << endl;
	cout << "��Ϣͳ�ƣ�" << endl;
	cout << "���н�ְ����" << vec_number.size() << "��" << endl;
	cout << "����������Ա��" << vec_obj_official.size() << endl;
	cout << "��ʦ������������Ա��" << vec_obj_tea_off.size() << endl;
	cout << "��ʦ��" << vec_obj_teacher.size() << endl;
	cout << "ʵ����Ա��" << vec_obj_reasecher.size() << endl;
	cout << "����ʵ���ң�" << vec_lab.size() - 1 << "��" << endl;
	cout << "����רҵ��" << vec_department.size() - 1 << "��" << endl;
	cout << endl;
	system("pause");
}

void print3_1()
{
	if (vec_int_3.size() == 0)
	{
		cout << "δ�ҵ��ñ�Ŷ�Ӧ����Ա��������ͳ�ƹ����в��ĺ��ٴβ���\n" << endl;
	}
	else
	{
		int idx = vec_int_3[1];
		cout << "��ϸ��Ա��Ϣ����:" << endl;
		cout << "------------------------------------------" << endl;
		switch (vec_int_3[0])
		{
		case 1:
			cout.setf(std::ios::left);
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_official[idx].get_name();
			cout.width(18);
			cout << vec_obj_official[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����ְ��";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "������ò��";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 2:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_teacher[idx].get_name();
			cout.width(18);
			cout << vec_obj_teacher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����Ժϵ��";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "��ʦְ�ƣ�";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_tittle();
			cout << endl;

			break;
		case 3:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_tea_off[idx].Teacher::get_name();
			cout.width(18);
			cout << vec_obj_tea_off[idx].Teacher::get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����Ժϵ��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "��ʦְ�ƣ�";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_tittle();
			cout << endl;

			cout.width(6);
			cout << "����ְ��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "������ò��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 4:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_reasecher[idx].get_name();
			cout.width(18);
			cout << vec_obj_reasecher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����ʵ���ң�";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_str_lab();
			cout << endl;

			cout.width(6);
			cout << "ʵ����ְ��";
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
		cout << "δ�ҵ���������Ӧ����Ա��������ͳ�ƹ����в��ĺ��ٴβ���\n" << endl;
	}
	else
	{
		int idx = vec_int_3[1];
		cout << "��ϸ��Ա��Ϣ����:" << endl;
		cout << "------------------------------------------" << endl;
		switch (vec_int_3[0])
		{
		case 1:
			cout.setf(std::ios::left);
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_official[idx].get_name();
			cout.width(18);
			cout << vec_obj_official[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����ְ��";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "������ò��";
			cout.width(10);
			cout << vec_obj_official[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 2:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_teacher[idx].get_name();
			cout.width(18);
			cout << vec_obj_teacher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����Ժϵ��";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "��ʦְ�ƣ�";
			cout.width(10);
			cout << vec_obj_teacher[idx].get_str_tittle();
			cout << endl;

			break;
		case 3:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_tea_off[idx].Teacher::get_name();
			cout.width(18);
			cout << vec_obj_tea_off[idx].Teacher::get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����Ժϵ��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_department();
			cout << endl;

			cout.width(6);
			cout << "��ʦְ�ƣ�";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_tittle();
			cout << endl;

			cout.width(6);
			cout << "����ְ��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_duty();
			cout << endl;

			cout.width(6);
			cout << "������ò��";
			cout.width(10);
			cout << vec_obj_tea_off[idx].get_str_politiclook();
			cout << endl;
			cout << endl;
			break;
		case 4:
			cout.width(14);
			cout << "����";
			cout.width(18);
			cout << "���";
			cout << endl;

			cout.width(14);
			cout << vec_obj_reasecher[idx].get_name();
			cout.width(18);
			cout << vec_obj_reasecher[idx].get_id().get_number();
			cout << endl;

			cout.width(6);
			cout << "����ʵ���ң�";
			cout.width(10);
			cout << vec_obj_reasecher[idx].get_str_lab();
			cout << endl;

			cout.width(6);
			cout << "ʵ����ְ��";
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