#include"Stack.h"
	static int operater(int x, char op, int y)
	{
		try
		{
			switch (op)
			{
			case '+':		
				return x + y;
			case '-':
				return x - y;
			case '*':
				return x * y;
			case '/':
				if (0 == y)
				{
					throw - 1;
				}
				return x / y;
			}
		}
		catch (int)
		{
			std::cout << "��ʽ������̳�����������Ƿ�Ϊ0��";
		}
	}



