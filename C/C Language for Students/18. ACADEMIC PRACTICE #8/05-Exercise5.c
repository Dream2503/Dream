#include <stdio.h>

void printToNum(int num)
{
    if (num >= 1)
    {
        printToNum(num - 1);
        printf("%d ", num);
    }
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printToNum(num);
    return 0;
}