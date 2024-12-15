#include <stdio.h>

void maxOfTwoDigit(int num)
{
    int tenth, unit, max;
    if (num >= 10 && num <= 99)
    {
        tenth = num / 10;
        unit = num % 10;

        if (tenth > unit)
            max = tenth;
        
        else
            max = unit;

        printf("Maximum of is %d", max);
    }
    else
        printf("Not a 2-digit number");
}

int main()
{
    int num;
    printf("Enter a 2-digit number: ");
    scanf("%d", &num);
    maxOfTwoDigit(num);
}   