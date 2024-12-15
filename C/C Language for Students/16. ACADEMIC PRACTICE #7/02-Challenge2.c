#include <stdio.h>

void strcpy(char str2[], char str1[])
{
    int cnt = 0;

    while (str1[cnt] != '\0')
    {
        str2[cnt] = str1[cnt];
        cnt++;
    }
}

int main()
{
    char str1[10] = "Dream", str2[10];
    strcpy(str2, str1);
    printf("str1 = %s\n", str1);
    printf("str2 = %s", str2);
    return 0;
}