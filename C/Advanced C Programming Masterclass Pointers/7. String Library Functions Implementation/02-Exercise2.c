#include <stdio.h>
#include <stdlib.h>

int strlen(char *str) {
    int cnt = 0;
    
    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}
char *strcat(char *str1, char *str2) {
    int str1len = strlen(str1), str2len = strlen(str2); 
    char *res = (char*)malloc(str1len+str2len+1);

    for (int i = 0; i < str1len; i++)
        res[i] = str1[i];
    
    for (int i = 0; i < str2len; i++)
        res[str1len+i] = str2[i];
    
    res[str1len+str2len] = '\0';
    return res;
}

int main() {
    char str1[] = "Hello ", str2[] = "World";
    char *res = strcat(str1, str2);
    printf("%s", res);
    return 0;
}