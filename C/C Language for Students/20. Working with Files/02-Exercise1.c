#include <stdio.h>

int main()
{
    FILE* fp;
    char ch;
    int i = 0;
    fp = fopen("01-exerciseFile.txt", "r");

    if (fp != NULL)
    {
        while ((ch = fgetc(fp)) != -1)
        {
            printf("%c", ch);
            i++;
        }
        printf("\nTotal number of characters: %d", i);
        fclose(fp);
    }    
    return 0;
}