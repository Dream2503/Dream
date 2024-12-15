#include <stdio.h>

int cntEven()
{
    int var;
    printf("Enter a number of sequence: ");
    scanf("%d", &var);

    if (var != -1)
    {
        if (var % 2 == 0)
            return 1 + cntEven();
        
        return cntEven();
    }
    return 0;
}

int main()
{
    printf("Total number of even numbers in the sequence are %d", cntEven());
    return 0;   
}