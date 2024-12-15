#include <stdio.h>

int main()
{
    int num, pow, res = 1;
    printf("Enter a number and power to raise: ");
    scanf("%d %d", &num, &pow);

    while (pow > 0)
    {
        res *= num;
        pow--;
    }
    printf("%d", res);
    return 0;

}