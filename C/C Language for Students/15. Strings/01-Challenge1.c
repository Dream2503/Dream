#include <stdio.h>

int main()
{
    char firstLastName[] = "Swapnaraj Moahnty";
    int cnt = 0;
    printf("Your full name is - ");

    while (firstLastName[cnt] != '\0')
    {
        printf("%c", firstLastName[cnt]);
        cnt++;
    }
    return 0;
}