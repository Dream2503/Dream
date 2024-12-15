#include <stdio.h>

int main()
{
    int num;
    printf("ENter a number: ");
    scanf("%d", &num);

    for (int i = num; i > 0; i--)
        printf("%d ", i);
    
    printf("\n");

    for (int i = 1; i <= num; i++)
        printf("%d ", i);

    return 0;
}