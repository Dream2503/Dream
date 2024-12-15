#include <stdio.h>

int main()
{
    char fileName[20], ch;
    int frequencyArray[26] = {0}, idx = 25;
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
    for (int i = 25; i >= 0; i--)
        if (frequencyArray[i] > frequencyArray[idx])
            idx = i;
            
    printf("%c = %d\n", idx + 'a', frequencyArray[idx]);
    return 0;
}