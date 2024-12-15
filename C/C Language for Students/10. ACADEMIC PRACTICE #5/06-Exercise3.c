#include <stdio.h>

int power(int num, int pow)
{
    int res = 1;

    for (int i = 0; i < pow; i++)
        res *= num;
    
    return res;
}

int lengthToNumber9(int lenght)
{
    int res = 0;

    for (int i = lenght - 1; i >= 0; i--)
        res += 9 * power(10, i);
    
    return res;
}

int lengthToNumber(int lenght)
{
    int res =0, cnt = 0;

    for (int i = lenght - 1; i >= 0; i--)
    {
        cnt++;
        res += cnt * power(10, i);
    }
    return res;
}

int main()
{
    int num;
    printf("Enter a lenght: ");
    scanf("%d", &num);

    if (num > 9)
        printf("Result is %d", lengthToNumber9(num));
    
    else
        printf("Result is %d", lengthToNumber(num));

    return 0;
}