#include <stdio.h>

int main()
{
    float num1, num2;
    printf("Enter a number: ");
    scanf("%f", &num1);
    printf("Enter a number: ");
    scanf("%f", &num2);

    if (num1 == num2)
        printf("True");
    
    else
        printf("False");

    return 0;
}