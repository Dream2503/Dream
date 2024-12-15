#include <stdio.h>

int isPalindromeRecur(int *array, int size) {
    if (size <= 1)
        return 1;

    if (array[0] == array[size - 1])
        return isPalindromeRecur(array + 1, size - 2);
    
    return 0;

}

int main() {
    int lst[] = {1, 2, 2, 1};
    printf("%d", isPalindromeRecur(lst, 4));
    return 0;
}