#include <stdio.h>

void mul_table(int n)
{
    for(int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n*i);
    }
}

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    mul_table(num);

    return 0;
}