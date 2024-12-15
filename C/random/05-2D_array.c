#include <stdio.h>

int main()
{
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int len = sizeof(array) / sizeof(array[0]);
    int inner_len = sizeof(array[0]) / sizeof(array[0][0]);
    printf("{");

    for(int i = 0; i < len; i++)
    {
        printf("{");

        for(int j = 0; j < inner_len; j++)
        {
            printf("%d", array[i][j]);

            if(j < inner_len -1)
            {
                printf(", ");
            }
        }

        printf("}");
        if(i < len -1)
        {
            printf(",\n");
        }
    }
    printf("}");

    return 0;
}