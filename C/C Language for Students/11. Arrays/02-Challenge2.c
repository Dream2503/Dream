#include <stdio.h>

int main()
{
    int lst[10];
    int maxIdx = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &lst[i]);
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (lst[i] > lst[maxIdx])
            maxIdx = i;
    }
    printf("Max number index = %d", maxIdx);
    return 0;
}