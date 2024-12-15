#include <stdio.h>

int main()
{
    int lst[10] = {8, 9, 1, 7, 5, 1, 9, 8, 6, 1};
    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        if (lst[i] > max)
            max = lst[i];
    }
    printf("Max = %d", max);
    return 0;
}