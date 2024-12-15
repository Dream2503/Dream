#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 10 && num <= 99)
        printf("double-digit");
    
    else if (num >= 100 && num <= 999)
        printf("triple-digit");
    
    else
        printf("neither double/triple");
    
    return 0;
    
}