#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass(double m);
	~MyClass();

private:
	
};

MyClass::MyClass(double m)
{
}

MyClass::~MyClass()
{
}

int main()
{
	char c = 3;
	MyClass cl(c);
	return 0;
}