#include <stdio.h>

int charToDigit(char a, char b, char c)
{
    if ((a >= '0' && a <= '9') && (b >= '0' && b <= '9') && (c >= '0' && c <= '9'))
    {
        int A, B, C;
        A = (int)(a - '0') * 100;
        B = (int)(b - '0') * 10;
        C = (int)(c - '0');
        return A + B + C;
    }
    else
        return 0;
}

int main()
{
    char a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%c %c %c", &a, &b, &c);
    printf("Result is %d", charToDigit(a, b ,c));
    return 0;
}