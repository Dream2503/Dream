#include <stdio.h>

int main()
{
    int num, cnt = 0, lc = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = num - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
            printf(" ");

        lc++;

        for (int k = 0; k < lc; k++)
        {
            cnt++;
            printf("%d ", cnt);
        }
        printf("\n");
        continue;
    }
    return 0;
}

/*
    1
   2 3
  4 5 6
 7 8 9 10
11 12 13 14 15
*/