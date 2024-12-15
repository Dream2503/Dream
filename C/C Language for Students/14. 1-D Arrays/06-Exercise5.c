#include <stdio.h>
#define len 10

int main()
{
    int lst[len], notUnique[len] = {-1}, cnt = 0, flag = 1;

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
                for (int k = 0; k < cnt; k++)
                {
                    if (lst[i] == notUnique[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    notUnique[cnt] = lst[i];
                    printf("The non-unique element %d\n", lst[i]);
                    cnt++;
                }
                flag = 1;
                break;
            }
        }
    }
    printf("Total non-unique elements are %d", cnt);
    return 0;
}