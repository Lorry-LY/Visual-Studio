//List.cpp

#include "List.h"

List::List()
{
	head = new Node;
	head->id = 0;
	head->next = NULL;
	size = 0;
}

List::~List()
{
	delete head;
}

int  List::CreateList(int size)
{
	if (size < 0)
	{
		return 0;
	}
	Node* ptemp = this->head;
	Node* pnew = NULL;
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		pnew = new Node;
		pnew->next = NULL;
		cout << "输入第" << i + 1 << "个元素的值：";
		cin >> pnew->id;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	return 1;
}

int List::DeleteList()
{
	Node* ptemp;
	if (this->head == NULL) {
		cout << "链表为空。" << endl;
		return 0;
	}
	while (this->head)
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	return 1;
}

int List::InsertLinkList(int id, int n)
{
	Node* ptemp;
	if (this->head == NULL)
	{
		cout << "链表为空。" << endl;
		return 0;
	}
	if (n == 1)
	{
		Node* pnew = new Node;
		pnew->id = id;
		pnew->next = this->head->next;
		this->head->next = pnew;
		this->size++;
	}
	if (n > this->size)
	{
		ptemp = this->head;
		while (ptemp->next != NULL)
		{
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->id = id;
		pnew->next = NULL;
		ptemp->next = pnew;
		this->size++;
		return 1;
	}
	else
	{
		ptemp = this->head;
		for (int i = 1; i < n; i++)
		{
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->id = id;
		pnew->next = ptemp->next;
		ptemp->next = pnew;
		this->size++;
	}
}

int List::DeleteLinkList(int n)
{
	Node* ptemp;
	Node* ptemp2;
	if (n > this->size)
	{
		cout << "超出链表范围。" << endl;
		return 0;
	}
	if (n == 1)
	{
		ptemp = this->head->next;
		this->head->next = ptemp->next;
		free(ptemp);
		this->size--;
		return 1;
	}
	if (n == this->size)
	{
		ptemp = this->head;
		for (int i = 1; i < this->size; i++)
		{
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = NULL;
		free(ptemp2);
		this->size--;
		return 1;
	}
	else
	{
		ptemp = this->head;
		for (int i = 1; i < n; i++)
		{
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = ptemp2->next;
		free(ptemp2);
		this->size--;
		return 1;
	}
}

int List::UpdataLinkList(int id, int n)
{
	if (n<0 || n>this->size)
	{
		cout << "超出链表范围。" << endl;
		return 0;
	}
	Node* ptemp = this->head;
	for (int i = 0; i < n; i++)
	{
		ptemp = ptemp->next;
	}
	ptemp->id = id;
	return 1;
}

int List::FindLinkList(int id)
{
	Node* ptemp = this->head;
	for (int i = 1; i < this->size; i++)
	{
		ptemp = ptemp->next;
		if (ptemp->id == id)
		{
			return i;
		}
	}
	return 0;
}

void List::display()
{
	Node* ptemp = this->head;
	for (int i = 1; i <= this->size; i++)
	{
		ptemp = ptemp->next;
		cout << ptemp->id << ' ';
	}
	cout << endl;
}

