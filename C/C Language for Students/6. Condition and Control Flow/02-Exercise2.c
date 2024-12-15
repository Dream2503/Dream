#include <stdio.h>

int main()
{
    float num1, num2;
    printf("Enter number1: ");
    scanf("%f", &num1);
    printf("Enter number2: ");
    scanf("%f", &num2);

    if (num1 > num2)
        printf("Maximum: %.1f\nMinimum: %.1f", num1, num2);
    
    else
        printf("Maximum: %.1f\nMinimum: %.1f", num2, num1);

    return 0;
}