#include <stdio.h>

int main()
{
    char sentence[100];
    int cnt = 0, len = 1;
    printf("Enter the sentence: ");
    gets(sentence); 

    while (sentence[cnt] != '\0')
    {
        if (sentence[cnt] == ' ')
            len++;
        
        cnt++;
    }
    
    printf("Total number of words in the sentence = %d", len);
    return 0;
}