#include <stdio.h>

int main()
{
    int num1, num2, res;
    char opr;
    printf("Enter number1: ");
    scanf("%d", &num1);
    printf("Enter operator: ");
    scanf(" %c", &opr);
    printf("Enter number: ");
    scanf("%d", &num2);

    switch(opr)
    {
        case '+':
            res = num1 + num2;
            break;
        
        case '-':
            res = num1 - num2;
            break;
        
        case '*':
            res = num1 * num2;
            break;
        
        case '/':
            if (num2 == 0)
                printf("Division by zero is undefined");
            
            else
                res = num1 / num2;
        
        case '%':
            res = num1 % num2;
        
        default:
            printf("Invalid operator for calculation");
            break;
    }
    printf("%d %c %d = %d", num1, opr, num2, res);
    return 0;
}