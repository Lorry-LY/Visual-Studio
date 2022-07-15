#include "Link.h"

int main()
{
	Link<int>link;
	link.createLink(10);
	link.remove(2);


	link.printline();
	cout << link.at(3)<<link.index(3)<<endl;
	return 0;
}