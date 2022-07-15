#include "Queue.h"


void Queue::push(int data)
{
	Node* newNode = new Node(data, tail);
	tail = newNode;
}

int Queue::pop()
{
	Node* tempNode = tail;
	if (tempNode)
	{
		int tempData;
		while (tempNode->preNode != NULL)
		{		
			tempNode = tempNode->preNode;
		}
		tempData = tempNode->data;
		delete tempNode;
		tempNode = NULL;
		return tempData;
	}
	else
	{
		cout << "¶ÓÁÐÎª¿Õ£¡" << endl;
		return 0;
	}
}