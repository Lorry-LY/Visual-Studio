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
	string talent;  //������츳
	int grade;   //����ȼ�
	int recent_experience;  //���ﵱǰ����ֵ
	string title;           //�ƺ�
	string weapon;          //����
	string pet;             //���
	string shuxing;
public:
	Character()
		:p_crown(nullptr), talent_number(0), talent("����"), grade(1), recent_experience(0), weapon("����"), pet("����"), title("����"), shuxing("") {}
	~Character() { delete p_crown; }
	void Set_crown();       //ѡ����������
	void Set_talent();      //�����츳
	void Set_totems();      //��������ͼ��
	void Set_title();            //��������ƺ�
	void Set_weapon();           //������������
	void Set_pet();              //�����������
	void Upgrade_s(int n = 1) { p_crown->Upgrade_small(); }    //��������
	void Upgrade_b(int n = 1) { p_crown->Upgrade_big(); }
	int Time_to_experience(int n);    //������������
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
		shuxing = "��";
	}
	else if (n == 2) {
		p_crown = new Wood();
		shuxing = "ľ";
	}
	else if (n == 3) {
		p_crown = new Water();
		shuxing = "ˮ";
	}
	else if (n == 4) {
		p_crown = new Fire();
		shuxing = "��";
	}
	else if (n == 5) {
		p_crown = new Earth();
		shuxing = "��";
	}
	talent_number = 0;
}
void Character::Set_talent() {
	srand((unsigned)time(0));
	int n = rand() % 100;
	if (n >= 95)
		talent = "��һ��";
	else if (n >= 85)
		talent = "�˶���";
	else if (n >= 65)
		talent = "������";
	else if (n <= 2)
		talent = "���忪";
	else
		talent = "���Ŀ�";
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
		title = "ѧͽ";
	else if (grade <= 20)
		title = "ѧʿ";
	else if (grade <= 30)
		title = "ʦ";
	else if (grade <= 40)
		title = "��ʦ";
	else if (grade <= 50)
		title = "��ʦ";
	else if (grade <= 60)
		title = "����ʦ";
	else if (grade <= 70)
		title = "��ʿ";
	else if (grade <= 80)
		title = "��ʦ";
	else if (grade <= 90)
		title = "����ʦ";
	else
		title = "����";
}
void Character::Set_weapon() {
	if (grade < 31)
		cout << "���꣬�Ͽ������ɣ���̫��С�ˡ�\n";
	else
		cout << "�����������ڸ�����·�ϣ��������׼��ұ�����ϡ�\n";
}
void Character::Set_pet() {
	if (grade < 31)
		cout << "�����ڵĵȼ����޷���Ԧ���ģ��Ͻ�ǿ�������ɡ�\n";
	else
	{
		cout << "��Ѱһλʵ��ǿ�������ħʦΪ�㻤����ǰ������ɭ��Ѱ��������ɣ�\n";
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
	cout << "����ʱ�䣨�£���  ";
	cin >> m;
	cout << "����ʱ�䣨�죩�� ";
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
	cout << "�츳��  " << talent << "\t�ȼ��� " << grade << endl;
	cout << "�ƺţ� " << title << endl;
	cout << "������ " << weapon << "\t��裺 " << pet << endl;
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
	if (shuxing == "��")
		pp_crown = new Metal();
	else if (shuxing == "ľ")
		pp_crown = new Wood();
	else if (shuxing == "ˮ")
		pp_crown = new Water();
	else if (shuxing == "��")
		pp_crown = new Fire();
	else if (shuxing == "��")
		pp_crown = new Earth();
	p_crown = pp_crown;
	p_crown->Read_fire(firename);
	delete pp_crown;
}