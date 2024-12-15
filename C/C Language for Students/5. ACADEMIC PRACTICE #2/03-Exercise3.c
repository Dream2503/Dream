#include <stdio.h>

int main()
{
    float sal, hrs, res;
    printf("Enter hourly salary: ");
    scanf("%f", &sal);
    printf("Enter total hours in a month: ");
    scanf("%f", &hrs);
    
    res = sal * hrs;
    printf("Monthly Salary is %.2f", res);
    return 0;
}