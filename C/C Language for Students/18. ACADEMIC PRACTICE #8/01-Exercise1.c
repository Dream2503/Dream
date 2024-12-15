#include <stdio.h>

int cntEven(int num)
{
    int var;
    printf("Enter a number of sequence: ");
    scanf("%d", &var);

    if (var != -1)
    {
        if (var < num)
            return 1 + cntLessNum(num);
        
        return cntLessNum(num);
    }
    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Total number of numbers less than the number are %d", cntLessNum(num));
    return 0;   
}