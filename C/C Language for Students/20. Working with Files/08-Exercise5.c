#include <stdio.h>

int main()
{
    char fileName[20], ch;
    printf("Enter the name of the file: ");
    scanf("%s", &fileName);
    printf("Enter the character: ");
    scanf(" %c", &ch);

    FILE* fp;
    char chr;
    int cnt;
    fp = fopen(fileName, "r");

    if (fp != NULL)
    {
        while ((chr = fgetc(fp)) != -1)
            if (chr == ch)
                cnt++;
        
        fclose(fp);
    }
    printf("Total number of the character occurrence is %d", cnt);
    return 0;
}