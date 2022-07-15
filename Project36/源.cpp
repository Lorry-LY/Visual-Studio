#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>

int main()
{
    int sum = 0;
    printf("this program sums a series of integers.\n");
    printf("enter integers (0 to terminate):\n");

    do {
        int n;
        std::cin >> n;
        getchar();
        sum += n;
        if (0 == n)
        {
            break;
        }
    } while (1);
    printf("the sum is: %d\n",sum);
    return 0;
}