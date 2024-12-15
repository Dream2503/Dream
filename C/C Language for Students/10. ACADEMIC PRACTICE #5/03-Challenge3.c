#include <stdio.h>

int factorial(int num)
{
    int res = 1;

    if (num > 1)
    {
        for (int i = 2; i <= num ; i++)
            res *= i;
    }

    else if (num == 0)
        res = 0;
    
    else
        res = -1;
    
    return res;   
}

int main()
{
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);
    printf("Factorial is %d", factorial(num));
}