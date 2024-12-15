#include <stdio.h>

int maxNum(int num)
{
    int var, max;
    printf("Enter a number of the sequence: ");
    scanf("%d", &var);

    if (num > 1)
    {
        max = maxNum(num - 1);

        if (var < max)
            return max;        
    }
    return var;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The maxiumum number is %d", maxNum(num));
    return 0;
}