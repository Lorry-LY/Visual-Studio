//Queue.h

#pragma once

#include<iostream>

using namespace std;

class Queue;

class Node
{
public:
	int data;
	Node* preNode;

	Node(int data, Node* preNode)
	{
		this->data = data;
		this->preNode = preNode;
	}

	friend class Queue;
};

class Queue
{
public:
	Queue()
	{
		tail = NULL;
	}

	void push(int data);
	int pop();

private:
	Node* tail;

};

