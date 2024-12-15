#include <stdio.h>
#define len 5

int main()
{
    int lst[len] = {5, 7, 1, 5, 2}, chk, max = 0;

    for (int i = 0; i < len - 1; i++)
    {
        chk = lst[i] + lst[i+1];

        if (chk > max)
            max = chk;
    }
    printf("The maximum adjecent sum is %d", max);
    return 0;
}