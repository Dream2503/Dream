#include <stdio.h>
#define len 3

int main()
{
    int lst[len] = {1, 2, 2000}, arr[len];

    for (int i = 0; i < len; i++)
        arr[i] = lst[i];
    
    for (int i = 0; i < len; i++)
        printf("%d element of og-%d and copy-%d\n", i+1, lst[i], arr[i]);
    
    return 0;
}