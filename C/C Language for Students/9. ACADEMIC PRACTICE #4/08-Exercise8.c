#include <stdio.h>

int main()
{
    int num, inp, chk = 0, is_ascending = 1;
    printf("Enter the total number: ");
    scanf("%d", &num);
    printf("Enter the sequence of numbers: \n");

    do
    {
        scanf("%d", &inp);

        if (inp < chk)
            is_ascending = 0;

        chk = inp;
        num--;
    } while (num > 0);

    if (is_ascending)
        printf("Very ascending");
    
    else
        printf("Not very ascending");
    
    return 0;    
}