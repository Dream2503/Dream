#include <stdio.h>

int lenOfString(char str[])
{
    int cnt = 0;

    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}

int main()
{
    char fullName[30];
    int len;
    printf("Enter your full name: ");
    gets(fullName);
    len = lenOfString(fullName);
    printf("Lenght of the string is %d", len);
    return 0;
}