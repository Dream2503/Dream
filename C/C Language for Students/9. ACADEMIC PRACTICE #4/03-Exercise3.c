#include <stdio.h>

int main()
{
    int num, time;
    printf("Enter a number and the number of time to print: ");
    scanf("%d %d", &num, &time);

    for (int i = 1; i <= time; i++)
        printf("%d x %d = %d\n", num, i, num * i);
    
    return 0;
}