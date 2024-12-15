#include <stdio.h>

int minNum(int num)
{
    int var, max;
    printf("Enter a number of the sequence: ");
    scanf("%d", &var);

    if (num > 1)
    {
        max = minNum(num - 1);

        if (var > max)
            return max;        
    }
    return var;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The minimum number is %d", minNum(num));
    return 0;
}