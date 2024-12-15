#include <stdio.h>

int main()
{
    int num, res;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
        res = num;
    
    else
        res = num * -1;
    
    printf("Absolute value is the number is %d", res);
    return 0;
}