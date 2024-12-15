#include <stdio.h>

int main()
{
    FILE* fp;
    char ch;
    int i = 1;
    fp = fopen("01-exerciseFile.txt", "r");

    if (fp != NULL)
    {
        while ((ch = fgetc(fp)) != -1)
        {
            if (ch == '\n')
                i++;
        }
        printf("\nTotal number of line: %d", i);
        fclose(fp);
    }
    return 0;
}