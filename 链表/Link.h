#pragma once

#include<iostream>

using namespace std;

template<typename T>
struct LinkNode
{
	T value;
	LinkNode* nextNode;
};

template<typename T>
class Link
{
public:
	Link();
	Link(LinkNode<T>* head);
	LinkNode<T>* createLink(int n);

	int length();
	T at(int i);
	int index(T x);
	void insert(T x, int i);
	T remove(int i);
	void printline();


private:
	LinkNode<T>* head;
	
};



//й╣ож
template<class T>
Link<T>::Link()
{
	head = new LinkNode<T>();
	head->nextNode = NULL;
}

template<class T>
Link<T>::Link(LinkNode<T>* node)
{
	head = new LinkNode<T>();
	head->nextNode = node;
}

template<typename T>
LinkNode<T>* Link<T>::createLink(int n)
{
	if (n <= 0)return nullptr;
	LinkNode<T>* node = head;
	for (int i = 0; i < n; i++)
	{
		LinkNode<T>* newNode = new LinkNode<T>({ i,NULL });
		node->nextNode = newNode;
		node = node->nextNode;
	}
	return head;
}

template<typename T>
int Link<T>::length()
{
	int len = 0;
	if (head->nextNode == NULL)return 0;
	LinkNode<T>* node = head;
	while (node->nextNode != NULL)
	{
		node = node->nextNode;
		len++;
	}
	return len;
}

template<typename T>
T Link<T>::at(int index)
{
	if (index<0 && index>=length())return T();
	LinkNode<T>* node = head->nextNode;
	for (int i = 0; i < index; i++)node = node->nextNode;
	return node->value;
}

template<typename T>
int Link<T>::index(T data)
{
	LinkNode<T>* node = head;
	int location = 0;
	while (node->nextNode!=NULL)
	{
		node = node->nextNode;
		if (node->value == data)return location;
		location++;
	}
	return location;
}

template<typename T>
void Link<T>::insert(T data, int n)
{
	if (n<0 && n>length())return;
	LinkNode<T>* node = head;
	for (int i = 0; i < n; i++)node = node->nextNode;
	LinkNode<T>* newNode = new LinkNode<T>({ data,NULL });
	newNode->nextNode = node->nextNode;
	node->nextNode = newNode;
}

template<typename T>
T Link<T>::remove(int index)
{
	if (index < 0 && index >= length())return T();
	LinkNode<T>* node = head;
	for (int i = 0; i < index; i++)node = node->nextNode;
	LinkNode<T>* deleteNode = node->nextNode;
	node->nextNode = node->nextNode->nextNode;
	T data = deleteNode->value;
	delete deleteNode;
	deleteNode = NULL;
	return data;
}

template<typename T>
void Link<T>::printline()
{
	if (head == NULL || head->nextNode == NULL)return;
	LinkNode<T>* node = head;
	while (node->nextNode != NULL)
	{
		node = node->nextNode;
		cout << node->value << " ";
	}
	cout << endl;
}
