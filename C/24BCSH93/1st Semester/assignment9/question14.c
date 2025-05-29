#include <stdio.h>

void XSTRCAT(char[], char[]);

int main() {
    char str1[60], str2[30];
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter a string: ");
    scanf("%s", str2);
    XSTRCAT(str1, str2);
    printf("Concatinated string is %s\n", str1);
    return 0;
}

void XSTRCAT(char str1[], char str2[]) {
    int i, j;

    for (i = 0; str1[i]; i++)
        ;
    for (j = 0; str2[j]; j++, i++) {
        str1[i] = str2[j];
    }
    str1[i] = '\0';
}
