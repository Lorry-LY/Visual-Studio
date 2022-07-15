#include <iostream>
#include <fstream>
#include <string>
#include "account.h"
using namespace std;

int main() {
	cout << "欢迎来到《阴阳冕》!\n";
	cout << "你要的进行的选项：\n";
	cout << "1.登录\t2.注册\t\n";
	char a;
	Account account1;
	string name, password;
	while (cin >> a) {
		cin.get();
		if (a == '1') {
			cout << "请输入你的账号：";
			getline(cin, name);
			cout << "请输入你的密码： ";
			getline(cin, password);
			account1.Read_fire(name);
			account1.Show();
			break;
		}
		else if (a == '2') {
			cout << "请输入你的账号：";
			getline(cin, name);
			cout << "请输入你的密码： ";
			getline(cin, password);
			account1 = Account(name, password);
			account1.Set_nickname();
			cout << "正在对你的角色进行初始化···\n";
			account1.Set_crown();
			account1.Set_talent();
			account1.Set_totems();
			cout << "人物初始化完毕！\n";
			account1.Show();
			break;
		}
		else {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "请输入一个合理的序号： ";
		}
	}
	account1.Activities();
	char b;
	while (1) {
		cout << "你可以输入q来退出或者输入w继续：";
		cin >> b;
		if (b == 'q')
			break;
		if (b == 'w')
			account1.Activities();
	}
	fstream file(name.c_str(), ios_base::out);
	account1.Write_fire(name);
	cout << "等着你的归来！";
	return 0;
}