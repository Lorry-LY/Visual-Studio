#include<iostream>
#include<string>

using namespace std;

class Chararray
{
public:
	Chararray(int size) :_len(size), _pstr(new char[_len]) {};
	~Chararray()
	{
		delete[] _pstr;
	}
	char& operator [](const int index)
	{
		static char ch = '\0';
		if (index >= 0 && index <= _len)
			return _pstr[index];
		else
			cout << "下标越界" << endl;
		return ch;
	}
private:
	int _len;
	char* _pstr;
};

int main()
{
	string te = "hello world";
	static_cast<char*>(te);
	int len = strlen(te);
	Chararray cha(len);
	for (int i = 0; i < len; i++)
	{
		cout << cha[i];
	}
	cout << endl;
	return 0;
}