//CFraction.cpp

#include "CFraction.h"

void CFraction::display()		//���������
{
	cout << this->cfz << '/' << this->cfm << endl;
}

bool operator>(CFraction& cf1, CFraction& cf2)		//������>ȫ�����ء���;������ģ���ж�ʱ�õ�������boolֵ�����ж�
{
	float num1, num2;
	num1 = (float)cf1.cfz / cf1.cfm;
	num2 = (float)cf2.cfz / cf2.cfm;
	if (num1 > num2)
	{
		return true;
	}
	else return false;
}