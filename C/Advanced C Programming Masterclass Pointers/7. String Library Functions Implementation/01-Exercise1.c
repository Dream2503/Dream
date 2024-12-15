#include <stdio.h>

int strlen(char *str) {
    int cnt = 0;
    
    while (str[cnt] != '\0')
        cnt++;
    
    return cnt;
}

int main() {
    char str[] = "Tech";
    printf("%d", strlen(str));
    return 0;
}