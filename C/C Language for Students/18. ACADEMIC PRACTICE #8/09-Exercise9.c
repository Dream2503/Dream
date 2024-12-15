#include <stdio.h>

int pellSequence(int num)
{
    if (num == 0)
        return 0;
    
    else if (num == 1)
        return 1;
    
    return 2 * pellSequence(num - 1) + pellSequence(num - 2);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Pell Sequence element is %d", pellSequence(num));
    return 0;
}