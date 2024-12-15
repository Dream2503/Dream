#include <stdio.h>

int evenPos = 1;

int evenOddFunc(int num)
{
    int main, rest;

    if (num)
    {
        main = num / 10;
        rest = num % 10;

        if ((rest % 2 == 0 && evenPos == 1) || (rest % 2 == 1 && evenPos == 0))
        {
            evenPos = !evenPos;
            evenOddFunc(main);
        }
        else
            return 0;
    }
    else
        return 1;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Result = %d", evenOddFunc(num));
    return 0;
}