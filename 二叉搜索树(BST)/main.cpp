#include "BST.h"

int main()
{
	BST* b = new BST();
	b->insert(6);
	b->insert(3);
	b->insert(5);
	b->insert(2);
	b->insert(1);
	b->getRoot()->successor();
	b->insert(8);
	b->insert(9);
	b->insert(7);
	b->insert(10);
	b->getRoot()->successor();
	b->getLeftMostNode();
	b->size();
	b->find(7);
	b->find(1);
	b->clear();
	delete b;
	return 0;
}