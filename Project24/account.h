#pragma once
#include <iostream>
#include <string>
#include "character.h"
using namespace std;
class Account {
private:
	string user_name;  //����һ���˺�
	string password;   //����һ������
	string nickname;   // ���˺�����Ϸ����ǳ�
	Character person;
public:
	Account() :user_name(""), password(""), nickname(""), person() {}
	Account(string a, string b) :user_name(a), password(b) {}
	~Account() {};
	void Set_nickname();
	void Set_crown() { person.Set_crown(); }       //ѡ����������
	void Set_talent() { person.Set_talent(); }     //�����츳
	void Set_totems() { person.Set_totems(); }      //��������ͼ��
	void Set_weapon() { person.Set_weapon(); }           //������������
	void Set_pet() { person.Set_pet(); }             //�����������
	void Upgrade_s(int n = 1) { person.Upgrade_s(); }    //��������
	void Upgrade_b(int n = 1) { person.Upgrade_b(); }
	void Time_to_grade() { person.Time_to_grade(); }  //��������
	void Activities();
	void Show() const;
	void Write_fire(string firename) const;
	void Read_fire(string firename);
};
void Account::Set_nickname() {
	cout << "���Լ���һ���ƺ���,";
	cout << "ע�ⲻ�����������ַ�,Ҳ���ܳ��������ַ���\n";
	cout << "������֣� ";
	string a = "[_.`~!@#$ % ^&*() += | {}':;', \\[\\]<> / ? ~��@#�� % ���� & *�������� + | {}������������������������] | \n | \r | \t";
	string b;
	basic_string<char>::iterator iter1;
	basic_string<char>::iterator iter2;
	while (getline(cin, b)) {
		if (b.size() > 6) {
			b.clear();
			cout << "������һ�������������ַ������ƣ� ";
		}
		else {
			int i = 0;
			for (iter1 = a.begin(); iter1 != a.end(); iter1++) {
				for (iter2 = b.begin(); iter2 != b.end(); iter2++) {
					if (*iter2 == *iter1)
						i++;
					if (i != 0)
						break;
				}
				if (i != 0)
					break;
			}
			if (i != 0) {
				b.clear();
				while (cin.get() != '\n')
					continue;
				cout << "������һ�������������ַ������ƣ� ";
			}
			else if (i == 0) {
				nickname = b;
				break;
			}
		}
	}
	nickname = b;
}
void Account::Show()const {
	cout << nickname << " ,�����ڵ����������ǣ� \n";
	person.Show();
}
void Account::Activities() {
	cout << "������Ҫ��ʲô��\n";
	cout << "1.����\t2.����\t\n";
	cout << "3.��\t4.��������\t\n";
	cout << "���������ǣ� ";
	char a, b;
	while (cin >> a) {
		if (a == '1') {
			cout << "�̿�����꣬���Ŭ�����������ر���\n";
			cout << "���������У����������q�˳�����:";
			cin >> b;
			if (b == 'q') {
				cout << "��������Ľ�����\n";
				person.Time_to_grade();
				person.Show();
			}
			break;
		}
		else if (a == '2') {
			cout << "�����п����˽⵽�ܶ࣬�������޵�ϰ�ԣ��񶷼��ɣ��ȵȡ�\n";
			break;
		}
		else if (a == '3') {
			cout << "�����ɸ�\n";
			break;
		}
		else if (a == '4') {
			cout << "��׳��Ŭ�����ϴ�ͽ�˱�ѽ��\n";
			break;
		}
		else {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "û�����ѡ��,������һ������ѡ� ";
		}
	}
}
void Account::Write_fire(string firename)const {
	ofstream fout(firename.c_str(), ios_base::out | ios_base::app);
	fout << user_name << " " << password << " " << nickname << " ";
	fout.close();
	person.Write_fire(firename);
}

void Account::Read_fire(string firename) {
	ifstream fin(firename.c_str(), ios_base::in);
	if (!fin.is_open()) {
		cout << "�޷�������ļ�";
		exit(EXIT_FAILURE);
	}
	fin >> user_name >> password >> nickname;
	person.Read_fire(firename);
}