#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    int isPalindrome = 1;
    printf("Enter a word: ");
    gets(str);
    int len = strlen(str);

    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-1-i])
        {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The given string is a palindrome");
    
    else
        printf("The given string is not a palindrome");

    return 0;
}