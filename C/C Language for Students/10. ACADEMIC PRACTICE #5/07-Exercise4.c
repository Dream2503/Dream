#include <stdio.h>

char toLower(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return letter - 'A' + 'a';

    return -1;
}

char toUpper(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return letter - 'a' + 'A';

    return -1;
}

int main()
{
    return 0;
}
