#include <stdio.h>
#define len 10

int main()
{
    int lst[len], cnt = 0, flag = 1;

    for (int i = 0; i < len; i++)
    {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &lst[i]);
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (lst[i] == lst[j] && i != j)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("The unique element %d\n", lst[i]);
            cnt++;
        }
        flag = 1;
    }
    printf("Total unique elements are %d", cnt);
    return 0;
}