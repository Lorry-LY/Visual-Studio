#include "Binary_search.h"


using namespace std;

int main()
{
	vector<int> a = { 5,6,7,8,9, 10 , 11, 12 ,13, 14 };
	int index = binarySearch_C(a, 0, 9, 12);
	cout << a[index] << endl;
	int index2 = binarySearch_R(a, 0, 9, 12);
	cout << a[index2] << endl;
}