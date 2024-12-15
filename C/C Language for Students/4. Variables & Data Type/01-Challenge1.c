#include <stdio.h>

int main()
{
    int current_year;
    int current_age;

    printf("Enter Current Year: ");
    scanf("%d", &current_year);
    printf("Enter Current Age: ");
    scanf("%d", &current_age);
    printf("Your Born Year is %d", current_year - current_age);
    return 0;
}