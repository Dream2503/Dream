#include <stdio.h>

int sumEven()
{
    int var;
    printf("Enter a number of sequence: ");
    scanf("%d", &var);

    if (var != -1)
    {
        if (var % 2 == 0)
            return var + sumEven();
        
        return sumEven();
    }
    return 0;
}

int main()
{
    printf("Total sum of even numbers in the sequence are %d", sumEven());
    return 0;   
}