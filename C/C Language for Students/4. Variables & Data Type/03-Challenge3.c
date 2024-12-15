#include <stdio.h>

int main()
{
    int grade1, grade2, grade3;
    printf("Enter Grade1: ");
    scanf("%d", &grade1);
    printf("Enter Grade2: ");
    scanf("%d", &grade2);
    printf("Enter Grade3: ");
    scanf("%d", &grade3);

    float average = (grade1 + grade2 + grade3) / 3.0;
    printf("Average Grade is %.2f", average);
    return 0;
}