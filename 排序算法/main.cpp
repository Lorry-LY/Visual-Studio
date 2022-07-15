#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "cardinal_sort.h"

using namespace std;

#include <sstream>

bool cmp(int x, int y)
{
    stringstream s1;
    s1 << x;
    string xx;
    s1 >> xx;
    stringstream s2;
    s2 << y;
    string yy;
    s2 >> yy;
    string str1 = xx + yy;
    string str2 = yy + xx;
    stringstream num1, num2;
    long long number1, number2;
    num1 << str1, num1 >> number1;
    num2 << str2, num2 >> number2;
    if (number1 > number2)return true;
    else return false;
}

string largestNumber(vector<int>& nums) {
    vector<int> result;
    result.push_back(nums.back());
    nums.pop_back();
    while (nums.size())
    {
        int data = nums.back();
        nums.pop_back();
        if (result.size() == 1) {
            if (cmp(result[0], data))result.push_back(data);
            else result.insert(result.begin(), data);
        }
        else
        {
            int left = 0, right = result.size() - 1;
            while (true)
            {
                if (left == result.size() -1) {
                    result.push_back(data);
                    break;
                }
                if (right == 0) {
                    result.insert(result.begin(), data);
                    break;
                }
                int middle = (left + right) / 2;
                bool b1 = cmp(result[middle], data), b2 = cmp(result[middle + 1], data);
                if (b1 != b2) {
                    result.insert(result.begin() + middle + 1, data);
                    break;
                }
                else if (b1 == true) {
                    left = middle + 1;
                }
                else if (b1 == false) {
                    right = middle;
                }
            }
        }
        
    }
    stringstream stream;
    for (int i = 0; i < result.size(); i++)stream << result[i];
    string str;
    stream >> str;
    cout << str;
    int number1;
    stringstream n;
    n << str;
    n >> number1;
    if (number1 == 0)return "0";
    else return str;
}



int main()
{
    vector<int>a = { 8,51,9,7,27,46,455,6,100,3 };
	//vector<int>a = { 2,2,2,2,2 };
    vector<string> b = { "eat", "tea", "tan", "ate", "nat", "bat" };
    cout << "初始序列：";
    for (int i = 0; i < a.size(); i++)cout << a[i] << " ";
    cout << endl;
    largestNumber(a);
    cout << "排序结果：";
    for (int i = 0; i < a.size(); i++)cout << a[i] << " ";
    cout << endl;
    system("pause");
}


