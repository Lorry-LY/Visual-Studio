#include <iostream>
#include <fstream>
#include <string>
#include "account.h"
using namespace std;

int main() {
	cout << "��ӭ�����������ᡷ!\n";
	cout << "��Ҫ�Ľ��е�ѡ�\n";
	cout << "1.��¼\t2.ע��\t\n";
	char a;
	Account account1;
	string name, password;
	while (cin >> a) {
		cin.get();
		if (a == '1') {
			cout << "����������˺ţ�";
			getline(cin, name);
			cout << "������������룺 ";
			getline(cin, password);
			account1.Read_fire(name);
			account1.Show();
			break;
		}
		else if (a == '2') {
			cout << "����������˺ţ�";
			getline(cin, name);
			cout << "������������룺 ";
			getline(cin, password);
			account1 = Account(name, password);
			account1.Set_nickname();
			cout << "���ڶ���Ľ�ɫ���г�ʼ��������\n";
			account1.Set_crown();
			account1.Set_talent();
			account1.Set_totems();
			cout << "�����ʼ����ϣ�\n";
			account1.Show();
			break;
		}
		else {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "������һ���������ţ� ";
		}
	}
	account1.Activities();
	char b;
	while (1) {
		cout << "���������q���˳���������w������";
		cin >> b;
		if (b == 'q')
			break;
		if (b == 'w')
			account1.Activities();
	}
	fstream file(name.c_str(), ios_base::out);
	account1.Write_fire(name);
	cout << "������Ĺ�����";
	return 0;
}