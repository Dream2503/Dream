#include <stdio.h>
#define len 10

int main()
{
    int table[len][len];

    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            table[i-1][j-1] = j * i;
    
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            printf("%5d", table[i][j]);
            
        printf("\n");
    }
    return 0;
}