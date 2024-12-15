#include <stdio.h>
#define len 4

int main()
{
    int lst[len] = {1, 4, 6, 2}, is_palindrome = 0;

    for (int i = 0; i < len/2; i++)
    {
        if (lst[i] == lst[len-1-i])
            is_palindrome = 1;

        else
            is_palindrome = 0;
    }
    
    if (is_palindrome)
        printf("The array is a palindrome");

    else
        printf("The array is not a palindrome");
               
    return 0;
}