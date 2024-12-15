#include <stdio.h>

int main()
{
    int x, x2, x4, x6, x8;
    printf("Enter a integer: ");
    scanf("%d", &x);
    x2 = x * x;
    x4 = x2 * x2;
    x6 = x4 * x2;
    x8 = x6 * x2;
    printf("x2 = %d\nx4 = %d\nx6 = %d\nx8 = %d", x2, x4, x6, x8);
    return 0;
}