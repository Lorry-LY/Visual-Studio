#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
void Sorts(T a[], int n);
template<class T>
void Searchs(T a[], int n,T sea);
template<class T>
T sum(T a[], int n);


int main()
{
	int a[5] = { 1,2,1,6,1 };
	Searchs(a, 5, 1);
	Sorts(a, 5);
	cout << "对元素求和得：" << sum(a, 5) << endl;
	return 0;
}

template<class T>
void Sorts(T a[], int n)
{
	sort(a, a + n);
	cout << "数组重新排序后的结果：";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

template<class T>
void Searchs(T a[], int n,T sea)
{
	cout << "该数组符合查找的元素位置有：";
	for (int i = 0; i < n; i++)
	{
		if (a[i] == sea)
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}

template<class T>
T sum(T a[], int n)
{
	int sums = 0;
	for (int i = 0; i < n; i++)
	{
		sums += a[i];
	}
	return sums;
}
