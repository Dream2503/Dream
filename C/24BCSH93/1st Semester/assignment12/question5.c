#include <stdio.h>

int main() {
    char str[30];
    printf("Enter a string: ");
    scanf("%s", str);
    char *ptr = str;
    int size = 0;

    while (*ptr != '\0') {
        size++;
        ptr++;
    }
    printf("Size of the string is %d\n", size);
    return 0;
}
