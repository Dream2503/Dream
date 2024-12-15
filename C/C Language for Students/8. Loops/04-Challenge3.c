#include <stdio.h>

int main()
{
    int grade;

    do
    {
        printf("Enter a valid grade: ");
        scanf("%d", &grade);
    } while (grade < 0 || grade > 100);

    printf("Grade = %d", grade);
    return 0;
}