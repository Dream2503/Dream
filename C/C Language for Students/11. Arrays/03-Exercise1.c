#include <stdio.h>
#define len 5

int main()
{
    int lst[len];
    int isGoodNeibours = 0;

    for (int i = 0; i < len; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &lst[i]);
    }
    
    for (int i = 1; i < len - 1; i++)
    {
        if (lst[i] == lst[i-1] * lst[i+1])
            isGoodNeibours = 1;
    }
    if (isGoodNeibours)
        printf("Good Neibours");
    
    else
        printf("Not Good Neibours");

    return 0;
}