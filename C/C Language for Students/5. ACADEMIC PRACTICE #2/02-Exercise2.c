#include <stdio.h>

int main()
{
    int a1, an, n;
    float sn;
    printf("Enter value of a1: ");
    scanf("%d", &a1);
    printf("Enter the value of an: ");
    scanf("%d", &an);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    sn = (a1 + an) * n / 2;
    printf("Value of sn is %.2f", sn);
    return 0;

}