#include <stdio.h>

int main() {
    char str[20];
    int i, j, size;
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; str[i]; i++)
        ;
    size = i;

    for (i = 0, j = size - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            printf("It is not a palindrome\n");
            return 0;
        }
    }
    printf("It is a palindrome\n");
    return 0;
}
