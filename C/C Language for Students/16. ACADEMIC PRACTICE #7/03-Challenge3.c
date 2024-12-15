#include <stdio.h>

int strlen(char str[])
{
    int cnt = 0;

    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}

int strcmp(char str1[], char str2[])
{
    int strlen1 = strlen(str1), strlen2 = strlen(str2);
    int len = strlen1, flag1, flag;
    
    if (strlen1 > strlen2)
        len = strlen2;
    
    if (strlen1 == strlen2)
        flag1 = 0;  
    
    for (int i = 0; i < len; i++)
    {
        if (str1[i] < str2[i])
            return 1;
        
        else if (str1[i] > str2[i])
            return -1;
        
        else
            flag = 0;
    }

    if (flag1 == flag)
        return 0;
}

int main()
{
    char str1[] = "AlphaTech", str2[] = "BalphaTech";
    printf("%d", strcmp(str1, str2));
    return 0;
}