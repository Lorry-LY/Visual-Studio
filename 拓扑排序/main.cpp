#include "Topologic.h"

int main()
{
	Gragh gragh;
	string str = "1 2 3 4";
	cout << "请输入节点：" << endl;
	char spilit;
	do
	{
		char ch = getchar();
		gragh.addNode(ch);
		spilit = getchar();
	} while (spilit != '\n');
	cout << "请输入边：" << endl;
	char ch1, ch2, ch3;
	while(true)
	{
		ch1 = getchar();
		ch2 = getchar();
		ch3 = getchar();		
		getchar();
		if (ch1 == 'E' && ch2 == 'O' && ch3 == 'F')break;
		gragh.addSide({ ch1,ch3 });
	}

	Topologic topo(gragh);
	topo.sort();

	return 0;
}