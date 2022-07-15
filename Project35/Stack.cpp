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
			std::cout << "算式计算过程出错，请检查除数是否为0。";
		}
	}



