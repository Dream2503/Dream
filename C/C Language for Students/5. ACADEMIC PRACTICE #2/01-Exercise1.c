#include <stdio.h>

int main()
{
    int a1, d, n, an;
    printf("Enter value of a1: ");
    scanf("%d", &a1);
    printf("Enter the value of d: ");
    scanf("%d", &d);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    an = a1 + (n - 1) * d;
    printf("Value of an is %d", an);
    return 0;

}