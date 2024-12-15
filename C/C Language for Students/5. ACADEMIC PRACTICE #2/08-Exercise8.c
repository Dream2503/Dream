#include <stdio.h>

int main()
{
    int num, hun, rem, ten, uni, res;
    printf("Enter a 3-Digit number: ");
    scanf("%d", &num);
    hun = num / 100;
    rem = num % 100;
    ten = rem / 10;
    uni = rem % 10;
    res = uni * 100 + ten * 10 + hun;
    printf("Result is %d", res);
}