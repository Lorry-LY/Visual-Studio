#pragma once
#include <iostream>
#include <string>
#include "character.h"
using namespace std;
class Account {
private:
	string user_name;  //设置一个账号
	string password;   //设置一个密码
	string nickname;   // 该账号在游戏里的昵称
	Character person;
public:
	Account() :user_name(""), password(""), nickname(""), person() {}
	Account(string a, string b) :user_name(a), password(b) {}
	~Account() {};
	void Set_nickname();
	void Set_crown() { person.Set_crown(); }       //选择人物属性
	void Set_talent() { person.Set_talent(); }     //人物天赋
	void Set_totems() { person.Set_totems(); }      //设置人物图腾
	void Set_weapon() { person.Set_weapon(); }           //设置人物武器
	void Set_pet() { person.Set_pet(); }             //设置人物灵宠
	void Upgrade_s(int n = 1) { person.Upgrade_s(); }    //人物升级
	void Upgrade_b(int n = 1) { person.Upgrade_b(); }
	void Time_to_grade() { person.Time_to_grade(); }  //修炼升级
	void Activities();
	void Show() const;
	void Write_fire(string firename) const;
	void Read_fire(string firename);
};
void Account::Set_nickname() {
	cout << "给自己起一个称呼吧,";
	cout << "注意不能输入特殊字符,也不能超过六个字符。\n";
	cout << "你的名字： ";
	string a = "[_.`~!@#$ % ^&*() += | {}':;', \\[\\]<> / ? ~！@#￥ % …… & *（）—— + | {}【】‘；：”“’。，、？] | \n | \r | \t";
	string b;
	basic_string<char>::iterator iter1;
	basic_string<char>::iterator iter2;
	while (getline(cin, b)) {
		if (b.size() > 6) {
			b.clear();
			cout << "请输入一个不超过六个字符的名称： ";
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
				cout << "请输入一个不含有特殊字符的名称： ";
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
	cout << nickname << " ,你现在的人物属性是： \n";
	person.Show();
}
void Account::Activities() {
	cout << "今天你要干什么？\n";
	cout << "1.修炼\t2.读书\t\n";
	cout << "3.格斗\t4.无所事事\t\n";
	cout << "你想做的是： ";
	char a, b;
	while (cin >> a) {
		if (a == '1') {
			cout << "刻苦的少年，你的努力将会有所回报。\n";
			cout << "正在修炼中，你可以输入q退出修炼:";
			cin >> b;
			if (b == 'q') {
				cout << "来看看你的进步。\n";
				person.Time_to_grade();
				person.Show();
			}
			break;
		}
		else if (a == '2') {
			cout << "从书中可以了解到很多，比如灵兽的习性，格斗技巧，等等。\n";
			break;
		}
		else if (a == '3') {
			cout << "百炼成钢\n";
			break;
		}
		else if (a == '4') {
			cout << "少壮不努力，老大徒伤悲呀！\n";
			break;
		}
		else {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "没有这个选项,请输入一个合理选项： ";
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
		cout << "无法打开这个文件";
		exit(EXIT_FAILURE);
	}
	fin >> user_name >> password >> nickname;
	person.Read_fire(firename);
}