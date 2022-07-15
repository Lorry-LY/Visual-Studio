#pragma once

#include<iostream>
#include<stdbool.h>
using namespace std;


template <typename T>
class Stack
{
private:
	T* front;	//头
	int top;//栈顶
	int MAX;//栈最大容量

public:
	Stack(int size);
	~Stack();
	bool push(T x);
	bool pop(T* px);
	T getTop();
	bool isEmpty();
	bool isFull();
	int size();

};


template <typename T>
Stack<T>::Stack(int size)
{
	this->MAX = size;
	this->front = new T[MAX];
	top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
	delete front;
}

template <typename T>
bool Stack<T>::push(T x)
{
	if (top >= MAX - 1)
	{
		return false;
	}
	front[++top] = x;
	return true;
}

template <typename T>
bool Stack<T>::pop(T* px)
{
	if (top == -1)
	{
		return false;
	}
	*px = front[top--];
}

template<typename T>
T Stack<T>::getTop()
{
	if (-1 == top)
	{
		return NULL;
	}
	return front[top];
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return -1 == top;
}

template <typename T>
bool Stack<T>::isFull()
{
	return top == MAX - 1;
}

template <typename T>
int Stack<T>::size()
{
	return top;
}

