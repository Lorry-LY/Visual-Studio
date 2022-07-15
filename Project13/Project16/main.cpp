

#include<stdio.h>
#include<string.h>



int add(int a, int b);
int des(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int check_error(char str[], int len);
int calcutor(char* str,int len);

int op1, op2;
char op;
int kuohao_l, kuohao_r;
int t2=0;
char ppy[10] = {'/0'};

int main()
{
	char str[50];
	char ch[40];
	int result = 0;
	printf("请输入计算式，例如：5+5*(5-2):\n");
opens:
	int len1 = 0;
	while ((ch[len1++] = getchar()) != '\n');
	len1--;
	int len = 0;
	if (result < 0)
	{
		str[0] == '-';
		len++;
	}
	for (int i=0; i < t2; i++,len++)
	{
		str[len] = ppy[i];
	}
	for (int i=0; i < len1; i++,len++)
	{
		str[len] = ch[i];
	}
	char* p = str;
	int error = check_error(p, len);
	if (error == 5)
	{
		goto ends;
	}
	if (error == 2)
	{
		printf("输入错误：算式中有非法字符。请重新输入：\n");
		goto opens;
	}
	if (error == 1)
	{
		printf("输入错误：算式中有逻辑错误。请重新输入：\n");
		goto opens;
	}
	result = calcutor(p, len);
	if (result == 98789)
	{
		printf("输入错误：除数不能为0。请重新输入：\n");
		goto opens;
	}
	else
	{
		static int coure = 1;
		if (coure == 1)
		{
			printf("如果想要继续算，请直接在后面输入。如果想退出，请在最后输入/0。\n");
		}
		coure++;
		printf("=%d", result);
		goto opens;
	}
	ends:

	return 0;
}

int check_error(char str[], int len)
{
	kuohao_l = 0;
	kuohao_r = 0;
	for (int i = 0; i < len; i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')')
				return 2;
		}
		if (str[i] == '(')
		{
			kuohao_l++;
			if (i == len - 1)
				return 1;
			if ('0' <= str[i - 1] && str[i - 1] <= '9')
				if ('0' <= str[i + 1] && str[i + 1] <= '9')
					return 1;
			if (str[i + 1] == ')')
				return 1;
			int error = 1;
			for (int j = i + 1; j < len; j++)
			{
				if (str[j] == ')')
				{
					error = 0;
					break;
				}
			}
			if (error)
				return 1;
		}
		if (str[i] == ')')
		{
			kuohao_r++;
			if (!i)
				return 1;
			if (str[i] == '(')
				return 1;
			if ('0' <= str[i - 1] && str[i - 1] <= '9')
				if ('0' <= str[i + 1] && str[i + 1] <= '9')
					return 1;
			int error = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[j] == '(')
				{
					error = 0;
					break;
				}
			}
			if (error)
				return 1;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if (i == len - 1)
				return 1;
			if (!(str[i - 1] == ')' && str[i + 1] == '('))
			{
				if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '(' || str[i - 1] == ')')
				{
					if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '(' || str[i + 1] == ')')
					{
						return 1;
					}
				}
				else if (str[i+1] == '*' || str[i+1] == '/' || str[i+1] == ')')
				{
					return 1;
				}
				if (!(str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '(' || str[i + 1] == ')'))
				{
					if (str[i - 1] == '*' || str[i - 1] == '/' )
					{
						return 1;
					}
				}
				
			}
		}
		if (str[i] == '*'||str[i]=='/')
		{
			if (i == 0 || i == len - 1)
				return 1;
			if (!(str[i - 1] == ')' && str[i + 1] == '('))
			{
				if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '(' || str[i - 1] == ')')
				{
					if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '(' || str[i + 1] == ')')
					{
						return 1;
					}
				}
				else if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ')' || str[i + 1] == '+' || str[i + 1] == '-')
				{
					return 1;
				}
				if (!(str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '(' || str[i + 1] == ')'))
				{
					if (str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '(' || str[i - 1] == '+' || str[i - 1] == '-')
					{
						return 1;
					}
				}
			}
		}
	}
	if (kuohao_l != kuohao_r)
	{
		return 1;
	}
	if (str[len - 2] == '/' && str[len - 1] == '0')
	{
		return 5;
	}
	return 0;
}

int calcutor(char* str, int len)
{
	int k_begin=0, k_end=len;
	for (; kuohao_l >= 0; kuohao_l--)
	{
		if (kuohao_l == 0)
		{
			k_begin = -1;
			k_end = len;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (*(str + i) == '(')
				{
					k_begin = i;
				}
				if (str[i] == ')')
				{
					k_end = i;
					break;
				}
			}
		}
		int n_begin, n_end, n_len = 0, number[10] = {0}, num;
		for (int j = k_begin +1; j <= k_end; j++)
		{
			if ('0' <= str[j] && str[j] <= '9')
			{
				n_begin = j;
				for (j++;j<=len; j++)
				{
					if (!('0' <= str[j] && str[j] <= '9'))
					{
						n_end = j;
						break;
					}
				}
				num = 0;
				for (int k =0;k<n_end-n_begin;k++)
				{
					num = num * 10 + (str[n_begin + k ] - '0');
				}
				number[n_len++] = num;
			}
		}
		if (str[k_begin + 1] == '-')
		{
			number[0] *= (-1);
		}
		int c_len = 0;
		char ops[10];
		for (int j = k_begin + 2; j < k_end; j++)
		{
			if (!('0' <= str[j] && str[j] <= '9'))
			{
				if (('0' <= str[j - 1] && str[j - 1] <= '9'))
				{
					ops[c_len++] = str[j];
				}
				else if (str[j] == '-')
				{
					number[c_len] *= (-1);
				}
			}
		}
		for (int j = 0; j < c_len; )
		{
			if(ops[j]=='*')
			{
				number[j] = number[j] * number[j + 1];
				for (int k = j + 2; k < n_len; k++)
				{
					number[k - 1] = number[k];
					ops[k - 2] = ops[k - 1];
				}
				n_len--; c_len--;
			}
			else if (ops[j] == '/')
			{
				if (number[j+1] == 0)
				{
					return 98789;
				}
				number[j] = number[j] / number[j + 1];
				for (int k = j + 2; k < n_len; k++)
				{
					number[k - 1] = number[k];
					ops[k - 2] = ops[k - 1];
				}
				n_len--; c_len--;
			}
			else
			{
				j++;
			}
		}
		for (int j = 0; j < c_len; )
		{
			if (ops[j] == '+')
			{
				number[j] = number[j] + number[j + 1];
				for (int k = j + 2; k < n_len; k++)
				{
					number[k - 1] = number[k];
					ops[k - 2] = ops[k - 1];
				}
				n_len--; c_len--;
			}
			else if (ops[j] == '-')
			{
				number[j] = number[j] - number[j + 1];
				for (int k = j + 2; k < n_len; k++)
				{
					number[k - 1] = number[k];
					ops[k - 2] = ops[k - 1];
				}
				n_len--; c_len--;
			}
			else
			{
				j++;
			}
		}
		int n0_len,fushu=1;
		if (number[0] < 0)
		{
			fushu = -1;
			number[0] *= (-1);
		}
		if(number[0]>0)
		{
			int temp = number[0];
			for (n0_len = 0; temp != 0; n0_len++)
			{
				temp /= 10;
			}
		}
		if (!number[0])
		{
			fushu = 0;
			n0_len = 1;
		}
		int t1 = 0;
		t2 = 0;
		char pty[10];
		while (number[0])
		{
			pty[t1++] = number[0] % 10 + '0';
			number[0] /= 10;
		}
		pty[t1] = 0;
		t1--;
		while (t1 >= 0)
		{
			ppy[t2++] = pty[t1--];

		}
		ppy[t2] = '\0';
		if (number == 0)
		{
			ppy[0] == 0;
		}
		if (k_begin == -1)
		{
			k_begin = 0;
			
		}
		if (fushu == -1)
		{
			str[k_begin] = '-';
			for (int j = k_begin+1; j < k_begin + t2+1; j++)
			{
				str[j] = ppy[j - k_begin-1];
			}
			for (int k = k_end + 1; k < len; k++)
			{
				str[k - (k_end -  k_begin) + n0_len] = str[k];
			}
			if (k_end == len)
			{
				len = t2 + 1;
			}
			else
			{
				len = len - (k_end - k_begin) + n0_len;
			}
			str[len] = '\0';
		}
		else
		{
			for (int j = k_begin; j < k_begin + t2; j++)
			{
				str[j] = ppy[j - k_begin];
			}
			for (int k = k_end + 1; k < len; k++)
			{
				str[k - (k_end -  k_begin) + n0_len-1] = str[k];
			}
			if (k_end == len)
			{
				len = t2;
			}
			else
			{
				len = len - (k_end - k_begin) + n0_len - 1;
			}
			str[len] = '\0';
		}
	}

	int rezult = 0;
	if (str[0] == '-')
	{
		for (int k = 1; k < len; k++)
		{
			rezult = rezult * 10 + str[k] - '0';
		}
		rezult *= (-1);
	}
	else
	{
		for (int k = 0; k < len; k++)
		{
			rezult = rezult * 10 + str[k] - '0';
		}
	}
	return rezult;
}

