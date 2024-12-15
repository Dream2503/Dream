#include <stdio.h>

int main()
{
    int num, res;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
        res += i;
    
    printf("Result = %d", res);
    return 0;
}