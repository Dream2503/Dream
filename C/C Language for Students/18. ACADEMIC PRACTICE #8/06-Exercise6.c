#include <stdio.h>

int lucasSequence(int num)
{
    if (num == 0)
        return 2;
    
    else if (num == 1)
        return 1;
    
    return lucasSequence(num - 1) + lucasSequence(num - 2);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Lucas Sequence element is %d", lucasSequence(num));
    return 0;
}