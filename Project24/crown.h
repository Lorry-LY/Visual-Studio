#pragma once
#include <fstream>
#include <string>
using namespace std;

class Five_elements { //五行基类，衍生金，木，水，火，土类
protected:
	int attack;              //攻击力
	int ability_power;       //法强
	int armor;               //护甲
	int magic_resist;        //魔抗
	int magic_power;         //灵力值
	string totems;           //图腾
public:
	Five_elements();
	Five_elements(int att, int abi, int arm, int mag_r, int mag_p, string tot = "");
	virtual ~Five_elements() {}
	virtual void Yin_totems() = 0;
	virtual void Yang_totems() = 0;
	virtual void Upgrade_small(int n = 1) = 0;
	virtual void Upgrade_big(int n = 1) = 0;    //人物升级，属性增强
	virtual void Show() const;    //展示人物属性
	virtual void Write_fire(string filename) const;  //将人物属性写入文件
	virtual void Read_fire(string firename); //从文件中读取人物信息
};
Five_elements::Five_elements()
	:attack(80), ability_power(50), armor(30), magic_resist(30), magic_power(100), totems("") {};
Five_elements::Five_elements(int att, int abi, int arm, int mag_r, int mag_p, string tot) :
	attack(att), ability_power(abi), armor(arm), magic_resist(mag_r), magic_power(mag_p), totems(tot) {}

void Five_elements::Show() const {
	cout << "攻击力： " << attack << "\t法强： " << ability_power << endl
		<< "护甲： " << armor << "\t魔抗： " << magic_resist << endl
		<< "魔力： " << magic_power << endl;
}
void Five_elements::Write_fire(string firename)const {
	ofstream fout(firename.c_str(), ios_base::out | ios_base::app);
	fout.seekp(ios::end);
	fout << attack << " " << ability_power << " " << armor << " " << magic_resist << " "
		<< magic_power << " " << totems.c_str();
	fout.close();
}
void Five_elements::Read_fire(string firename) {
	ifstream fin(firename.c_str(), ios_base::in);
	fin >> attack >> ability_power >> armor >> magic_resist >> magic_resist >> totems;
	fin.close();
}

class Metal : public Five_elements {
private:
	int penetration;
public:
	Metal() :Five_elements(80, 0, 35, 35, 90, ""), penetration(30) {};
	void Yin_totems() { totems = "太阴"; }  //阴属性图腾
	void Yang_totems() { totems = "白虎"; } //阳属性图腾
	void Upgrade_small(int n = 1);            //小升级
	void Upgrade_big(int n = 1);             //大升级
	void Show() const;
};
void Metal::Upgrade_small(int n) {
	for (int i = 0; i < n; i++) {
		attack += 2;
		armor += 2;
		magic_resist += 1;
		magic_power += 3;
		penetration += 1;
	}
}
void Metal::Upgrade_big(int n) {
	for (int i = 0; i < n; i++) {
		attack += 10;
		armor += 8;
		magic_resist += 5;
		magic_power += 20;
		penetration += 5;
	}
}
void Metal::Show() const {
	if (totems == "太阴")
		cout << "属性： 辛金\t图腾： " << totems << endl;
	else if (totems == "白虎")
		cout << "属性： 庚金\t图腾： " << totems << endl;
	Five_elements::Show();
	cout << "特殊属性-穿透性： " << penetration << endl;
}

class Wood : public Five_elements {
private:
	int renew;
public:
	Wood() :Five_elements(40, 60, 30, 30, 140, ""), renew(20) {};
	Wood(int att, int abi, int arm, int mag_r, int mag_p, string tot, int ren)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), renew(ren) {};
	void Yin_totems() { totems = "六合"; }
	void Yang_totems() { totems = "青龙"; }
	void Upgrade_small(int n = 1);
	void Upgrade_big(int n = 1);
	void Show() const;
};
void Wood::Upgrade_small(int n) {
	for (int i = 0; i < n; i++) {
		ability_power += 2;
		armor += 2;
		magic_resist += 1;
		magic_power += 5;
		renew += 2;
	}
}
void Wood::Upgrade_big(int n) {
	for (int i = 0; i < n; i++) {
		ability_power += 10;
		armor += 5;
		magic_resist += 5;
		magic_power += 25;
		renew += 5;
	}
}
void Wood::Show() const {
	if (totems == "六合")
		cout << "属性： 乙木\t图腾： " << totems << endl;
	else if (totems == "青龙")
		cout << "属性： 甲木\t图腾： " << totems << endl;
	Five_elements::Show();
	cout << "特殊属性-立即恢复： " << renew << endl;
}

class Water : public Five_elements {
private:
	int recovery;
public:
	Water() :Five_elements(35, 65, 30, 30, 125, ""), recovery(5) {};
	Water(int att, int abi, int arm, int mag_r, int mag_p, string tot, int rec)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), recovery(rec) {};
	void Yin_totems() { totems = "玄武"; }
	void Yang_totems() { totems = "天后"; }
	void Upgrade_small(int n = 1);
	void Upgrade_big(int n = 1);
	void Show() const;
};
void Water::Upgrade_small(int n) {
	for (int i = 0; i < n; i++) {
		ability_power += 3;
		armor += 1;
		magic_resist += 2;
		magic_power += 6;
		recovery += 2;
	}
}
void Water::Upgrade_big(int n) {
	for (int i = 0; i < n; i++) {
		ability_power += 10;
		armor += 4;
		magic_resist += 7;
		magic_power += 30;
		recovery += 4;
	}
}
void Water::Show() const {
	if (totems == "玄武")
		cout << "属性： 癸水\t图腾： " << totems << endl;
	else if (totems == "天后")
		cout << "属性： 壬水\t图腾： " << totems << endl;
	Five_elements::Show();
	cout << "特殊属性-持续性回复： " << recovery << endl;
}

class Fire : public Five_elements {
private:
	int critical_strike;
public:
	Fire() :Five_elements(95, 0, 40, 35, 100, ""), critical_strike(10) {};
	Fire(int att, int abi, int arm, int mag_r, int mag_p, string tot, int cri)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), critical_strike(cri) {};
	void Yin_totems() { totems = "螣蛇"; }
	void Yang_totems() { totems = "朱雀"; }
	void Upgrade_small(int n = 1);
	void Upgrade_big(int n = 1);
	void Show() const;
};
void Fire::Upgrade_small(int n) {
	for (int i = 0; i < n; i++) {
		attack += 3;
		armor += 3;
		magic_resist += 2;
		magic_power += 1;
		critical_strike += 2;
	}
}
void Fire::Upgrade_big(int n) {
	for (int i = 0; i < n; i++) {
		attack += 12;
		armor += 9;
		magic_resist += 5;
		magic_power += 13;
		critical_strike += 3;
	}
}
void Fire::Show() const {
	if (totems == "螣蛇")
		cout << "属性： 丁火\t图腾： " << totems << endl;
	else if (totems == "朱雀")
		cout << "属性： 丙火\t图腾： " << totems << endl;
	Five_elements::Show();
	cout << "特殊属性-暴击： " << critical_strike << endl;
}

class Earth :public Five_elements {
public:
	Earth() :Five_elements(70, 20, 60, 55, 95, "") {};
	Earth(int att, int abi, int arm, int mag_r, int mag_p, string tot)
		:Five_elements(att, abi, arm * 3, mag_r * 2, mag_p, tot) {};
	void Yin_totems() { totems = "天乙"; }
	void Yang_totems() { totems = "天空"; }
	void Upgrade_small(int n = 1);
	void Upgrade_big(int n = 1);
	void Show() const;
};
void Earth::Upgrade_small(int n) {
	for (int i = 0; i < n; i++) {
		attack += 1;
		ability_power += 1;
		armor += 6;
		magic_resist += 6;
		magic_power += 2;
	}
}
void Earth::Upgrade_big(int n) {
	for (int i = 0; i < n; i++) {
		attack += 8;
		ability_power += 7;
		armor += 25;
		magic_resist += 20;
		magic_power += 7;
	}
}
void Earth::Show() const {
	if (totems == "天乙")
		cout << "属性： 己土\t图腾： " << totems << endl;
	else if (totems == "天后")
		cout << "属性： 戊土\t图腾： " << totems << endl;
	Five_elements::Show();
	cout << "特殊属性-极高的抗性 \n";
}