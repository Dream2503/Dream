#include <stdio.h>

void strcpy(char *str2, char *str1) {
    int cnt = 0;

    do {
        str2[cnt] = str1[cnt];
        cnt++;
    } while(str1[cnt] != '\0');
}

int main() {
    char str1[] = "Hello", str2[7];
    strcpy(str2, str1);
    printf("%s", str2);
    return 0;
}