#include<stdio.h> 
#define PI 3.14159 
void main()
{
    double r, a, c;
    r = 10;
    a = PI * r * r;
    c = 2 * PI * r;
    printf("r=%lf,a=%lf,c=%lf\n", r, a, c);
    getchar();

}