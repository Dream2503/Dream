#include <stdio.h>

int strlen(char *str) {
    int cnt = 0;
    
    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}
int strcmp(char *str1, char *str2) {
    int str1len = strlen(str1), str2len = strlen(str2), len, rtn = 0;
    
    if (str1len > str2len)
        len = str1len;
    else
       len = str2len;
    
    for (int i = 0; i < len; i++) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
    }

    if (str1len > str2len)
        return 1;
    else if (str1len < str2len)
        return -1;
    
    return 0;
}

int main() {
    char str1[] = "May", str2[] = "Mike", str3[] = "Mayday";
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str2, str1));
    printf("%d\n", strcmp(str2, str2));
    printf("%d\n", strcmp(str1, str3));
    printf("%d\n", strcmp(str3, str1));
    return 0;
}