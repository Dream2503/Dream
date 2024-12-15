#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 2; i <= num * 2; i += 2)
        printf("%d ", i);

    return 0;
}