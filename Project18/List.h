//List.h

#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

struct Node {
	int id;
	Node* next;
};

class List
{
private:
	Node* head;
	int size;
public:
	List();
	~List();
	int CreateList(int size);
	int DeleteList();
	int InsertLinkList(int id, int n);
	int DeleteLinkList(int n);
	int UpdataLinkList(int id, int n);
	int FindLinkList(int id);
	void display();
};

#endif // !LIST_H

