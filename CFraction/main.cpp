//main.cpp

#include"CFraction.h"

template<typename T>		//��������������ĺ���ģ��
T max(T a[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		if (!(a[0] > a[i]))
		{
			temp = a[0];
			a[0] = a[i];
			a[i] = temp;
		}
	}
	return a[0];
}

int main()
{
	CFraction cf1(1, 3);		//�������cf1��
	CFraction cf2(2, 3);		//�������cf2��
	CFraction cf3(4, 3);		//�������cf3��
	cf1.display();			//���cf1��ֵ
	cf2.display();			//���cf2��ֵ
	cf3.display();			//���cf3��ֵ
	int a[5] = { 1,2,3,4,5 };		//������������a[5]
	int result = max(a, 5);
	cout << result << endl;			//�����ͨ������ȷ�ԡ�
	CFraction CFr[3] = { cf1,cf2,cf3 };		//����CF������
	CFraction cf4 = max(CFr, 3);
	cf4.display();			//�����ȷ��

	return 0;
}
