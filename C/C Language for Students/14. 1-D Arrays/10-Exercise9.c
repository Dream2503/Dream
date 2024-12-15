#include <stdio.h>
#include <stdlib.h>
#define len 6

int main()
{
    int lst[len] = {5, 4, 7, 3, 9, -8}, temp;
    int min = abs(lst[0] + lst[1]), res[3] = {lst[0], lst[1], min};

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i != j)
            {
                temp = lst[i] + lst[j];

                if (abs(temp) < min)
                {
                    min = abs(temp);
                    res[0] = lst[i]; res[1] = lst[j]; res[2] = temp;
                }
            }     
        }
    }
    printf("The minimum sum closest to 0 is of %d and %d = %d", res[0], res[1], res[2]);
    return 0;
}