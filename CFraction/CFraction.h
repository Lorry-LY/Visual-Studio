//CFraction.h

#pragma once
#include<iostream>
using namespace std;
class CFraction
{
public:			//������Ա������publicԭ����Ϊ�ⲿ�Բ�����>ȫ������ʱ�õ���
	int cfz;	
	int cfm;
public:
	CFraction()		//�޲ι��캯������;������ģ������������ʱ���õ���
	{
		this->cfm = 1;
		this->cfz = 1;
	}
	CFraction(int cfz, int cfm) :cfz(cfz), cfm(cfm) {};		//���캯������;����������
	CFraction& operator=(CFraction& cf)			//������=�ڲ�����	��;������ģ�帳ֵʱ�õ���
	{
		this->cfz = cf.cfz;
		this->cfm = cf.cfm;
		return *this;
	}
	void display();		//���������
};
bool operator>(CFraction& cf1, CFraction& cf2);






