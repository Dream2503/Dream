#include <stdio.h>

int main()
{
    int day, month, year;
    printf("Enter day month year: ");
    scanf("%d %d %d", &day, &month, &year);

    if (((year % 400 == 0 || year % 4 == 0) && year % 100 != 0) && (day == 29 && month == 2))
    {
        day = 1;
        month = 3;
    } 
    else if ((!(year % 400 == 0 || year % 4 == 0) && year % 100 != 0) && (day == 28 && month == 2))
    {
        day = 1;
        month = 3;
    }
    else if (day == 31 && month == 12)
    {
        day = month = 1;
        year++;
    }
    else if ((day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)))
    {
        day = 1;
        month++;
    }
    else
        day++;
    
    printf("%d %d %d", day, month, year);
    return 0;
}