#include <stdio.h>

typedef struct date {int day, month, year;} Date;

int main()
{
    Date dt;
    printf("Enter day: ");
    scanf("%d", &dt.day);
    printf("Enter month: ");
    scanf("%d", &dt.month);
    printf("Enter year: ");
    scanf("%d", &dt.year);
    dt.day += 1;
    printf("The nest day is %d/%d/%d", dt.day, dt.month, dt.year);
    return 0;
}