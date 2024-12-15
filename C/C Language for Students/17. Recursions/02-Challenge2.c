#include <stdio.h>

int sumOfDigit(int num)
{
    int main, rest;
    rest = num % 10;
    main = num / 10;

    if (main == 0)
        return rest;

    return rest + sumOfDigit(main);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of digits are %d", sumOfDigit(num));
    return 0;
}