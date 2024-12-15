#include <stdio.h>

int main()
{
    char fileName[20], ch;
    int frequencyArray[26] = {0};
    FILE* fp;
    printf("Enter a filename: ");
    scanf("%s", &fileName);
    fp = fopen(fileName, "r");

    if (fp != NULL)
    {
        while ((ch = fgetc(fp)) != -1)
            if (ch >= 'a' && ch <= 'z')
                frequencyArray[ch-'a']++;
        
        fclose(fp);
    }
    for (int i = 0; i < 26; i++)
        printf("%c = %d\n", i +'a', frequencyArray[i]);
    
    return 0;
}