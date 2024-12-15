#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int cnt = 0;

    while (cnt < num)
    {
        printf("*");
        cnt++;
    }
    return 0;
    
}