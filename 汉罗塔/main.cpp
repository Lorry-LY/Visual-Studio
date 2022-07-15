#include<iostream>

using namespace std;
void move(int n, int x, int y) {
    printf("the %dth plate from %c to %c\n", n, x + 65, y + 65);
}
void hanoi(int n, int A, int B, int C) {
    if (n == 1)
        move(n, A, C);
    else {
        hanoi(n - 1, A, C, B);
        move(n, A, C);
        hanoi(n - 1, B, A, C);
    }
}
int main()
{
    int n;
    printf("Assuming the top plate is the first plate\nplease input the number of plate : ");
    cin >> n;
    hanoi(n, 0, 1, 2);
}