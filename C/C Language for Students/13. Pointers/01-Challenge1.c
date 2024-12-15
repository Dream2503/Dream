#include <stdio.h>

int main()
{
    int grade1 = 90, grade2 = 80;
    printf("values for grade1 and grade2 are %d %d\n", grade1, grade2);
    printf("addresses for grade1 and grade2 are %p %p", &grade1, &grade2);
    return 0;
}