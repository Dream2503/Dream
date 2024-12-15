#include <stdio.h>
#define len 5

int main()
{
    int lst[5] = {1, 2, 5, 3, 10};
    int isRelSort = 0, isSort = 0, isNotSort = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (lst[i] < lst[i+1])
            isRelSort = 1;
        
        else if (lst[i] == lst[i+1])
            isSort = 1;
        
        else
            isNotSort = 1;
    }
    if (isRelSort && !isSort && !isNotSort)
        printf("Really Sorted");
    
    else if (isRelSort && isSort && !isNotSort)
        printf("Sorted");
    
    else
        printf("Not Sorted");
    
    return 0;
}