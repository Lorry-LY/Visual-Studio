//main.cpp

#include"CFraction.h"

template<typename T>		//求数组中最大数的函数模板
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
	CFraction cf1(1, 3);		//构造对象cf1；
	CFraction cf2(2, 3);		//构造对象cf2；
	CFraction cf3(4, 3);		//构造对象cf3；
	cf1.display();			//输出cf1的值
	cf2.display();			//输出cf2的值
	cf3.display();			//输出cf3的值
	int a[5] = { 1,2,3,4,5 };		//构造整形数组a[5]
	int result = max(a, 5);
	cout << result << endl;			//检测普通整形正确性。
	CFraction CFr[3] = { cf1,cf2,cf3 };		//构造CF类数组
	CFraction cf4 = max(CFr, 3);
	cf4.display();			//检测正确性

	return 0;
}
