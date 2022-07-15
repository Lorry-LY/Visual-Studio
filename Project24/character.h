#pragma once
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "crown.h"
using namespace std;

class Character {
private:
	Five_elements* p_crown;
	int talent_number;
	string talent;  //人物的天赋
	int grade;   //人物等级
	int recent_experience;  //人物当前经验值
	string title;           //称号
	string weapon;          //武器
	string pet;             //灵宠
	string shuxing;
public:
	Character()
		:p_crown(nullptr), talent_number(0), talent("暂无"), grade(1), recent_experience(0), weapon("暂无"), pet("暂无"), title("暂无"), shuxing("") {}
	~Character() { delete p_crown; }
	void Set_crown();       //选择人物属性
	void Set_talent();      //人物天赋
	void Set_totems();      //设置人物图腾
	void Set_title();            //设置人物称号
	void Set_weapon();           //设置人物武器
	void Set_pet();              //设置人物灵宠
	void Upgrade_s(int n = 1) { p_crown->Upgrade_small(); }    //人物升级
	void Upgrade_b(int n = 1) { p_crown->Upgrade_big(); }
	int Time_to_experience(int n);    //人物修炼升级
	int Every_experience(int n);
	void Time_to_grade();
	void Show() const;
	void Write_fire(string firename) const;
	void Read_fire(string firename);
};

void Character::Set_crown() {
	srand((unsigned)time(0));
	int n = rand() % 5 + 1;
	if (n == 1) {
		p_crown = new Metal();
		shuxing = "金";
	}
	else if (n == 2) {
		p_crown = new Wood();
		shuxing = "木";
	}
	else if (n == 3) {
		p_crown = new Water();
		shuxing = "水";
	}
	else if (n == 4) {
		p_crown = new Fire();
		shuxing = "火";
	}
	else if (n == 5) {
		p_crown = new Earth();
		shuxing = "土";
	}
	talent_number = 0;
}
void Character::Set_talent() {
	srand((unsigned)time(0));
	int n = rand() % 100;
	if (n >= 95)
		talent = "九一开";
	else if (n >= 85)
		talent = "八二开";
	else if (n >= 65)
		talent = "七三开";
	else if (n <= 2)
		talent = "五五开";
	else
		talent = "六四开";
}
void Character::Set_totems() {
	srand((unsigned)time(0));
	int n = rand();
	if (n % 2 == 0)
		p_crown->Yin_totems();
	else
		p_crown->Yang_totems();
}
void Character::Set_title() {
	if (grade <= 10)
		title = "学徒";
	else if (grade <= 20)
		title = "学士";
	else if (grade <= 30)
		title = "师";
	else if (grade <= 40)
		title = "大师";
	else if (grade <= 50)
		title = "宗师";
	else if (grade <= 60)
		title = "大宗师";
	else if (grade <= 70)
		title = "天士";
	else if (grade <= 80)
		title = "天师";
	else if (grade <= 90)
		title = "大天师";
	else
		title = "冕下";
}
void Character::Set_weapon() {
	if (grade < 31)
		cout << "少年，赶快修炼吧，你太弱小了。\n";
	else
		cout << "武器商人正在赶来的路上，你可以先准备冶炼材料。\n";
}
void Character::Set_pet() {
	if (grade < 31)
		cout << "你现在的等级是无法驾驭灵宠的，赶紧强大起来吧。\n";
	else
	{
		cout << "找寻一位实力强大的阴阳魔师为你护航，前往灵兽森林寻找你的灵宠吧！\n";
	}
}
int Character::Time_to_experience(int n) {
	for (int i = 0; i < 10; i++) {
		if (n < (i + 1) * 10 && n >= i * 10)
			return (10 + i * 3);
	}
	return 0;
}
int Character::Every_experience(int n) {
	for (int i = 0; i < 10; i++) {
		if (n < (i + 1) * 10 && n >= i * 10)
			return (70 + i * 20);
	}
	return 0;
}
void Character::Time_to_grade() {
	int m = 0, y = 0;
	cout << "修炼时间（月）：  ";
	cin >> m;
	cout << "修炼时间（天）： ";
	cin >> y;
	y = y + m * 30;
	for (; y >= 0; y--) {
		recent_experience += Time_to_experience(grade);
		if (recent_experience >= Every_experience(grade)) {
			recent_experience -= Every_experience(grade);
			grade += 1;
		}
	}
	Upgrade_s(grade % 10);
	Upgrade_b(grade / 10);
	Set_title();
}
void Character::Show() const {
	p_crown->Show();
	cout << "天赋：  " << talent << "\t等级： " << grade << endl;
	cout << "称号： " << title << endl;
	cout << "武器： " << weapon << "\t灵宠： " << pet << endl;
}
void Character::Write_fire(string firename)const {
	ofstream fout(firename.c_str(), ios_base::out | ios_base::app);
	fout.seekp(ios::end);
	fout << shuxing.c_str() << " " << talent.c_str() << " " << grade << " " << title.c_str() << " " << weapon.c_str()
		<< " " << pet.c_str() << " ";
	fout.close();
	p_crown->Write_fire(firename);
}
void Character::Read_fire(string firename) {
	ifstream fin(firename.c_str(), ios_base::in);
	fin >> shuxing >> talent >> grade >> title >> weapon >> pet;
	Five_elements* pp_crown = nullptr;
	if (shuxing == "金")
		pp_crown = new Metal();
	else if (shuxing == "木")
		pp_crown = new Wood();
	else if (shuxing == "水")
		pp_crown = new Water();
	else if (shuxing == "火")
		pp_crown = new Fire();
	else if (shuxing == "土")
		pp_crown = new Earth();
	p_crown = pp_crown;
	p_crown->Read_fire(firename);
	delete pp_crown;
}