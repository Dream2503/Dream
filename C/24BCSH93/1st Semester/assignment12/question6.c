#include <stdio.h>

int sCount(char *);

int main() {
    char str[30];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Size of the string is %d\n", sCount(str));
    return 0;
}

int sCount(char *str) {
    int size = 0;

    while (*str != '\0') {
        size++;
        str++;
    }
    return size;
}
