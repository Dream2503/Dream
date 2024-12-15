#include <stdio.h>

int main()
{
    int num, digit, rem_num, even = 0, odd = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i *= 10)
    {
        rem_num = num / i;
        digit = rem_num % 10;

        if (digit % 2 == 0)
            even += digit;
        
        else
            odd += digit;
    }
    printf("Result = %d", even - odd);
    return 0;
}