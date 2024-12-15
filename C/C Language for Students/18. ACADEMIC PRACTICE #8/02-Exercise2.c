#include <stdio.h>

int cntChar(char chr)
{
    int var;
    printf("Enter a charecter of sequence: ");
    scanf(" %c", &var);

    if (var != '$')
    {
        if (var == chr)
            return 1 + cntChar(chr);
        
        return cntChar(chr);
    }
    return 0;
}

int main()
{
    char chr;
    printf("Enter a charecter to check: ");
    scanf(" %c", &chr);
    printf("Total number of charecter occurred are %d", cntChar(chr));
    return 0;
}