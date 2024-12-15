#include <stdio.h>

int main()
{
    int num, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 3; i <= num; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    
    printf("Sum = %d", sum);
    return 0;
}