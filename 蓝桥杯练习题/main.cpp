#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int N = 1000;

int main()
{
    // 请在此输入您的代码
    int n, m;
    scanf("%d %d", &n, &m);
    int t[N] = { 0 }, w[N] = { 0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
        int k = 0;
        for (int j = 0; j < m; j++)
        {
            if (w[k] > w[j])
            {
                k = j;
            }
        }
        w[k] += t[i];
    }
    int Max = 0;
    for (int i = 0; i < m; i++)
    {
        if (Max < w[i])
        {
            Max = w[i];
        }
    }
    cout << Max;

    return 0;
}