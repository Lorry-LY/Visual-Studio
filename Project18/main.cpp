//main.cpp

#include"List.h"

int main()
{
	List list;
	list.CreateList(6);
	list.display();
	list.InsertLinkList(12, 3);
	list.display();
	cout << list.FindLinkList(12) << endl;
	list.DeleteLinkList(3);
	list.display();
	list.UpdataLinkList(12, 3);
	list.display();
	list.DeleteList();

	return 0;
}