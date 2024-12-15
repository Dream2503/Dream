#include <stdio.h>

int main()
{
    float num1, num2, num3, max, min;
    printf("Enter number1: ");
    scanf("%f", &num1);
    printf("Enter number2: ");
    scanf("%f", &num2);
    printf("Enter number3: ");
    scanf("%f", &num3);

    max = num1;
    min = num2;

    if (num1 < num2)
    {
        max = num2;
        min = num1;
    }

    if (max < num3)
        max = num3;
    
    if (num3 < min)
        min = num3;
        
    printf("%.1f %.1f", max, min);

}