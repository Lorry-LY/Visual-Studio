#include<iostream>

using namespace std;

class Complex
{

public:
	Complex() :real(0), magic(0) {};
	~Complex() {};

	Complex& operator=(const Complex& c)
	{
		this->real = c.real;
		this->magic = c.magic;
		return *this;
	}

	bool operator<(const Complex& c)
	{
		if (this->real < c.real)return true;
		else if (this->real == c.real && this->magic < c.magic)return true;
		else return false;
	}

	bool operator>(const Complex& c)
	{
		if (this->real < c.real)return false;
		else if (this->real == c.real && this->magic < c.magic)return false;
		else return true;
	}

	Complex& operator++(int i)
	{
		Complex temp(*this);
		real++;
		magic++;
		return temp;
	}

	Complex& operator+(const Complex& c)
	{
		this->real += c.real;
		this->magic += c.magic;
		return *this;
	}

	Complex& operator-(const Complex& c)
	{
		this->real -= c.real;
		this->magic -= c.magic;
		return *this;
	}

	Complex& operator*(const Complex& c)
	{
		int temp1 = this->real * c.real - this->magic * c.magic;
		int temp2 = this->real * c.magic + this->magic * c.real;
		this->real = temp1;
		this->magic = temp2;
		return *this;
	}

	Complex& operator/(const Complex& c)
	{
		Complex temp = *this * c;
		int temp1 = c.real * c.real + c.magic * c.magic;
		temp.real /= 1.0 * temp1;
		temp.magic /= 1.0 * temp1;
		return temp;
	}

	void setReal(int real) { this->real = real; }
	int getReal() { return this->real; }
	void setMagic(int magic) { this->magic = magic; }
	int getMagic() { return this->magic; }


private:
	int real;
	int magic;

};


int main()
{

	return 0;
}