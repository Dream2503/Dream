#include <stdio.h>
#define len 4

int main()
{
    int lst[len] = {5, 4, 7, 3}, var;
    var = lst[0];

    for (int i = 1; i < len; i++)
        lst[i-1] = lst[i];
    
    lst[len-1] = var;

    for (int i = 0; i < len; i++)
        printf("Enter element #%d: %d\n", i + 1, lst[i]);

    return 0;
}