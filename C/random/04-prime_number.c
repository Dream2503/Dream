#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool flag = true;
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        printf("%d is a prime number", num);
    }

    else
    {
        printf("%d is not a prime number", num);
    }

    return 0;
}

    