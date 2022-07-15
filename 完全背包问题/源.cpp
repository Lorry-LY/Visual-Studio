#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int knapsack_limitnum(int* W, int* V, int* N, int* res, int n, int C)
{
    int value = 0;
    int** f = new int* [n];
    for (int i = 0; i < n; i++)
    {
        f[i] = new int[C + 1];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < C + 1; j++)
            f[i][j] = 0;

    for (int y = 1; y < C + 1; y++)
    {
        int count = min(N[0], y / W[0]);
        f[0][y] = (y < W[0]) ? 0 : (count * V[0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int y = 1; y < C + 1; y++)
        {
            if (y < W[i])
            {
                f[i][y] = f[i - 1][y];
            }
            else {
                int count = min(N[i], y / W[i]);
                f[i][y] = f[i - 1][y];
                for (int k = 1; k <= count; k++)
                {
                    int temp = f[i - 1][y - W[i] * k] + k * V[i];
                    if (temp >= f[i][y])
                        f[i][y] = temp;
                }
            }
        }
    }


    value = f[n - 1][C];
    int j = n - 1;
    int y = C;
    while (j)
    {
        int count = min(N[j], y / W[j]);
        for (int k = count; k > 0; k--)
        {
            if (f[j][y] == (f[j - 1][y - W[j] * k] + k * V[j]))
            {
                res[j] = k;
                y = y - k * W[j];
                break;
            }
        }
        j--;
    }
    res[0] = f[0][y] / V[0];


    for (int i = 0; i < n; i++)
    {
        delete f[i];
        f[i] = 0;
    }
    delete[] f;
    f = 0;
    return value;
}

void test1()
{
    int T;
    cin >> T;
   
    while (T--)
    {
        int n, C;
        cin >> n >> C;
        int* W = new int[n];
        int* V = new int[n];
        int* N = new int[n];
        int* res = new int[n];
        for (int i = 0; i < n; i++)
            res[i] = 0;
        for (int i = 0; i < n; i++)cin >> W[i];
        for (int i = 0; i < n; i++)cin >> V[i];
        for (int i = 0; i < n; i++)cin >> N[i];
        int value = knapsack_limitnum(W, V, N, res, n, C);
        cout << value << endl;
        delete res; res = 0;
        delete N; N = 0;
        delete V; V = 0;
        delete W; W = 0;
    }
}


int main()
{
    test1();
    return 0;
}
