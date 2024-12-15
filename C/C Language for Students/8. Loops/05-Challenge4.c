#include <stdio.h>

int main()
{
    int num, pow, res = 1;
    printf("Enter a number and the power to be raised: ");
    scanf("%d %d", &num, &pow);

    for (int i = 0; i < pow; i++)
        res *= num;
    
    printf("%d ^ %d = %d", num, pow, res);
    return 0;   
}