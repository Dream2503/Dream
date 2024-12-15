#include <stdio.h>

int noOfDigit(int num)
{
    int main, rest;
    main = num / 10;

    if (main == 0)
        return 1;

    return 1 + noOfDigit(main);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("No. of digits are %d", noOfDigit(num));
    return 0;
}