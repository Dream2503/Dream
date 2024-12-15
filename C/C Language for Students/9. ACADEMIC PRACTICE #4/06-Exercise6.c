#include <stdio.h>

int main()
{
    int num, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 15; i <= num; i += 15)
        sum += i;
    
    printf("Sum = %d", sum);
    return 0;
}