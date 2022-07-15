#include"Queue.h"

int main()
{
	Queue queue;
	queue.push(2);
	queue.push(3);
	queue.push(4);

	for (int i = 0; i < 3; i++)
	{
		cout << queue.pop() << " ";
	}
	cout << endl;

	return 0;
}

