#include <stdio.h>

int main()
{
    int num, sequence, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the numbers in sequence: \n");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &sequence);
        
        if (sequence % 2 != 0)
            sum += sequence;   
    }
    printf("Sum of all odd numbers = %d", sum);
    return 0;
}