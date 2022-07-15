
#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
#include"Stack.cpp"
#include<sstream>
#include<fstream>


int zhongzhui(string str)
{
    Stack<int> numbers(100);
    Stack<char> op(50);
    op.push('=');
    int p = 0;
    int q = 0;
    int temp = 0;
    for (; p < str.length(); p++)
    {
        if ('0' <= str[p] && str[p] <= '9')
        {
            for (q = p + 1; q < str.length(); q++)
            {
                if (!('0' <= str[q] && str[q] <= '9'))
                {
                    break;
                }
            }
            for (int i = p; i < q; i++)
            {
                temp += (int)((str[i] - 48) * pow(10, q - i - 1));
            }
            numbers.push(temp);
            p = q - 1;
            temp = 0;
        }
        else
        {
            switch (str[p])
            {
            case '+':case '-':
                while (1)
                {
                    char op1 = op.getTop();
                    if (op1 == '/' || op1 == '*' || op1 == '-')
                    {
                        op.pop(&op1);
                        int x, y;
                        numbers.pop(&x);
                        numbers.pop(&y);
                        numbers.push(operater(y, op1, x));
                    }
                    else
                    {
                        break;
                    }
                }
                op.push(str[p]);
                break;
            case '*':case '/':case '(':
                op.push(str[p]);
                break;
            case ')':
                while (1)
                {
                    char op1 = op.getTop();
                    if (op1 == '(')
                    {
                        op.pop(&op1);
                        break;
                    }
                    else
                    {
                        op.pop(&op1);
                        int x, y;
                        numbers.pop(&x);
                        numbers.pop(&y);
                        numbers.push(operater(y, op1, x));
                    }
                }
                break;
            case '=':
                while (1)
                {
                    char op1 = op.getTop();
                    if (op1 == '=')
                    {
                        op.pop(&op1);
                        break;
                    }
                    else
                    {
                        op.pop(&op1);
                        int x, y;
                        numbers.pop(&x);
                        numbers.pop(&y);
                        numbers.push(operater(y, op1, x));
                    }
                }
                break;
            }

        }
    }
    numbers.pop(&p);
    return p;
}

string zhouzhuiToHouzhui(string str)
{
    Stack<int> numbers(100);
	Stack<char> op(50);
	op.push('=');
    stringstream result;
    result << " ";
    //string result=" ";
    //char ch[10] = { '\0' };
    int p = 0;
    int q = 0;
    int temp = 0;
    for (; p < str.length(); p++)
    {
        if ('0' <= str[p] && str[p] <= '9')
        {
            for (q = p+1; q < str.length(); q++)
            {
                if (!('0' <= str[q] && str[q] <= '9'))
                {
                    break;
                }
            }
            for (int i = p; i < q; i++)
            {
                result << str[p];
                temp += (int)((str[i] - 48) * pow(10, q - i - 1));
            }
            numbers.push(temp);
            result << " ";
            p = q - 1;
            temp = 0;
        }
        else
        {
            switch (str[p])
            {
            case '+':case '-':
                while (1)
                {
                    
                    char op1 = op.getTop();
                    if ('=' == op1||'('==op1)
                    {
                        op.push(str[p]);
                        break;
                    }
                        /*op.pop(&op1);
                        int x, y;
                        numbers.pop(&x);
                        numbers.pop(&y);
                        numbers.push(operater(y, op1, x));                 */ 
                        op.pop(&op1);
                        result << op1 << " ";     
                        //result += op1+" ";
                }
                break;
            case '*':case '/':
                while (1)
                {
                    char op1 = op.getTop(); 
                    if (op1 == '*' || op1 == '/')
                    {
                        op.pop(&op1);
                        result << op1 << " ";
                        //result += op1 + " ";
                    }
                    else
                    {
                        break;
                    }
                    
                }
                op.push(str[p]);
                break;
            case '(':
                op.push(str[p]);
                break;
            case ')':
                while (1)
                {
                    char op1 = op.getTop();
                    if (op1 == '(')
                    {
                        op.pop(&op1);
                        break;
                    }
                    else
                    {
                        op.pop(&op1);
                        result << op1 << " ";
                        //result += op1 + " ";
                    }
                }
                break;
            case '=':
                while (1)
                {
                    char op1 = op.getTop();
                    if (op1 == '=')
                    {
                        op.pop(&op1);
                        break;
                    }
                    else
                    {
                        op.pop(&op1);
                        result << op1 << " ";
                       // result += op1 + " ";
                    }
                }
                break;
            }
            
        }      
    }
    //cout << endl<< result;
    return result.str();
}

int houzhui(string str)
{
    Stack<int> numbers(100);
    int p = 1;
    int q = 0;
    int temp = 0;
    for (; p < str.length(); p++)
    {
        if ('0' <= str[p] && str[p] <= '9')
        {
            for (q = p + 1; q < str.length(); q++)
            {
                if (' '==str[q])
                {
                    break;
                }
            }
            for (int i = p; i < q; i++)
            {
                
                temp += (int)((str[i] - 48) * pow(10, q - i - 1));
            }
            numbers.push(temp);
            
            p = q ;
            temp = 0;
        }
        else
        {
            int x, y;
            if (str[p] != '=')
            {
                numbers.pop(&x);
                numbers.pop(&y);
                numbers.push(operater(y, str[p], x));
                p ++;
            }
            else
            {
                break;
            }
            
        }
    }
    numbers.pop(&p);
 
    return p;
}

//中缀表达式求职
//int main()
//{
//    fstream file("data.txt", ios_base::in);
//    if (file.is_open())
//    {
//        while (!file.eof())
//        {
//            string str;
//            getline(file,str);
//            cout << "表达式为：" <<str << endl;
//            cout <<"结果为："<< zhongzhui(str)<<endl;
//            
//        }
//        file.close();
//    }
//    else
//    {
//        cout << "文件打开失败。";
//    }
//    system("pause");
//    return 0;
//}



//后缀表达式
int main()
{
    fstream file("data.txt", ios_base::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            string str;
            getline(file, str);
            cout << "表达式为：" << str << endl;
            string str1 = zhouzhuiToHouzhui(str);
            cout <<"后缀表达式："<< str1 << endl <<"结果："<< houzhui(str1) << endl;
            
        }
        file.close();
        
    }
    else
    {
        cout << "文件打开失败。";
    }
    system("pause");
	return 0;
}
