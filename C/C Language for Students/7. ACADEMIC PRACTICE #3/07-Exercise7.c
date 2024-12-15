#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Enter number1: ");
    scanf("%d", &num1);
    printf("Enter number2: ");
    scanf("%d", &num2);
    printf("Enter number3: ");
    scanf("%d", &num3);

    if ((num1 % num2 == 0 || num2 % num1 == 0) && (num2 % num3 == 0 || num3 % num2 == 0) && (num3 % num1 == 0 || num1 % num3 == 0))
        printf("Divisible");

    else
        printf("Non-Divisible");
    
    return 0;
}