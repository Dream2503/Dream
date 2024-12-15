#include <stdio.h>

int sum = 0;

int sumEvenDigit(int num)
{
    int main, rest;

    if (num)
    {
        main = num / 10;
        rest = num % 10;
        sum += rest;
        sumEvenDigit(main);
    }
    return !(sum % 2);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Result = %d", sumEvenDigit(num));
    return 0;
}