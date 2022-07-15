#pragma once
#include <fstream>
#include <string>
using namespace std;

class Five_elements { //���л��࣬������ľ��ˮ��������
protected:
	int attack;              //������
	int ability_power;       //��ǿ
	int armor;               //����
	int magic_resist;        //ħ��
	int magic_power;         //����ֵ
	string totems;           //ͼ��
public:
	Five_elements();
	Five_elements(int att, int abi, int arm, int mag_r, int mag_p, string tot = "");
	virtual ~Five_elements() {}
	virtual void Yin_totems() = 0;
	virtual void Yang_totems() = 0;
	virtual void Upgrade_small(int n = 1) = 0;
	virtual void Upgrade_big(int n = 1) = 0;    //����������������ǿ
	virtual void Show() const;    //չʾ��������
	virtual void Write_fire(string filename) const;  //����������д���ļ�
	virtual void Read_fire(string firename); //���ļ��ж�ȡ������Ϣ
};
Five_elements::Five_elements()
	:attack(80), ability_power(50), armor(30), magic_resist(30), magic_power(100), totems("") {};
Five_elements::Five_elements(int att, int abi, int arm, int mag_r, int mag_p, string tot) :
	attack(att), ability_power(abi), armor(arm), magic_resist(mag_r), magic_power(mag_p), totems(tot) {}

void Five_elements::Show() const {
	cout << "�������� " << attack << "\t��ǿ�� " << ability_power << endl
		<< "���ף� " << armor << "\tħ���� " << magic_resist << endl
		<< "ħ���� " << magic_power << endl;
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
	void Yin_totems() { totems = "̫��"; }  //������ͼ��
	void Yang_totems() { totems = "�׻�"; } //������ͼ��
	void Upgrade_small(int n = 1);            //С����
	void Upgrade_big(int n = 1);             //������
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
	if (totems == "̫��")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	else if (totems == "�׻�")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	Five_elements::Show();
	cout << "��������-��͸�ԣ� " << penetration << endl;
}

class Wood : public Five_elements {
private:
	int renew;
public:
	Wood() :Five_elements(40, 60, 30, 30, 140, ""), renew(20) {};
	Wood(int att, int abi, int arm, int mag_r, int mag_p, string tot, int ren)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), renew(ren) {};
	void Yin_totems() { totems = "����"; }
	void Yang_totems() { totems = "����"; }
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
	if (totems == "����")
		cout << "���ԣ� ��ľ\tͼ�ڣ� " << totems << endl;
	else if (totems == "����")
		cout << "���ԣ� ��ľ\tͼ�ڣ� " << totems << endl;
	Five_elements::Show();
	cout << "��������-�����ָ��� " << renew << endl;
}

class Water : public Five_elements {
private:
	int recovery;
public:
	Water() :Five_elements(35, 65, 30, 30, 125, ""), recovery(5) {};
	Water(int att, int abi, int arm, int mag_r, int mag_p, string tot, int rec)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), recovery(rec) {};
	void Yin_totems() { totems = "����"; }
	void Yang_totems() { totems = "���"; }
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
	if (totems == "����")
		cout << "���ԣ� ��ˮ\tͼ�ڣ� " << totems << endl;
	else if (totems == "���")
		cout << "���ԣ� ��ˮ\tͼ�ڣ� " << totems << endl;
	Five_elements::Show();
	cout << "��������-�����Իظ��� " << recovery << endl;
}

class Fire : public Five_elements {
private:
	int critical_strike;
public:
	Fire() :Five_elements(95, 0, 40, 35, 100, ""), critical_strike(10) {};
	Fire(int att, int abi, int arm, int mag_r, int mag_p, string tot, int cri)
		:Five_elements(att, abi, arm, mag_r, mag_p, tot), critical_strike(cri) {};
	void Yin_totems() { totems = "Ο��"; }
	void Yang_totems() { totems = "��ȸ"; }
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
	if (totems == "Ο��")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	else if (totems == "��ȸ")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	Five_elements::Show();
	cout << "��������-������ " << critical_strike << endl;
}

class Earth :public Five_elements {
public:
	Earth() :Five_elements(70, 20, 60, 55, 95, "") {};
	Earth(int att, int abi, int arm, int mag_r, int mag_p, string tot)
		:Five_elements(att, abi, arm * 3, mag_r * 2, mag_p, tot) {};
	void Yin_totems() { totems = "����"; }
	void Yang_totems() { totems = "���"; }
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
	if (totems == "����")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	else if (totems == "���")
		cout << "���ԣ� ����\tͼ�ڣ� " << totems << endl;
	Five_elements::Show();
	cout << "��������-���ߵĿ��� \n";
}