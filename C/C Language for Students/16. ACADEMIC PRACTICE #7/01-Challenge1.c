#include <stdio.h>

int strlen(char str[])
{
    int cnt = 0;

    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}

int main()
{
    char string[10] = "Dream";
    printf("The lenght of the string is %d", strlen(string));
    return 0;
}