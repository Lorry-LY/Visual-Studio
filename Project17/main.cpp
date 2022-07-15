#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void swap(const T &a, const T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void heapsort(vector<T>& arr, int n)
{
	int i, j, temp;
	T t;
	for (i = n / 2; i > 0; i--)
	{
		t = arr[i];
		temp = i;
		for (j = 2 * temp; j <= n; j *= 2)
		{
			if (arr[j] > arr[j + 1])j++;
			if (j<n && arr[j]>arr[j + 1])j++;
			if (arr[temp] <= arr[j])break;
			arr[temp] = arr[j];
			temp = j;
		}
		arr[temp] = t;
	}
}

int main()
{
	int n, i, temp;
	cin >> n;
	vector<int>arr;
	arr.push_back(n);
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	heapsort<int>(arr, n);
	for (i = n; i > 1; i--)
	{
		swap(arr[1], arr[i]);
		heapsort<int>(arr, i - 1);
	}
	for (i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}

