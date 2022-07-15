#include <iostream>	

#include <string>

using namespace std;

int main()
{
    char ch[1001];
    int letters[26] = { 0 };
    int len, i, sum = 0;
    gets_s(ch);
    len = strlen(ch);

    for (i = 0; i < len; i++)
        letters[ch[i] - 'a']++;

    for (i = 0; i < len; i++)
    {
        if (letters[ch[i] - 'a'] == 1)
        {
            cout << ch[i] << endl;
            break;
        }
    }
    return 0;
}