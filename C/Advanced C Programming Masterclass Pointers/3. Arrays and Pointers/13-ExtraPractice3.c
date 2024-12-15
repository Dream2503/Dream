#include <stdio.h>

int maxSumArray(int *array, int size) {
    if (size == 2)
        return *array + *(array + 1);

    if (*array + *(array + 1) > maxSumArray(array + 1, size - 1))
        return *array + *(array + 1);
}

int main() {
    int lst[] = {9, 2, 4, 5, 3};
    printf("%d", maxSumArray(lst, 5));
    return 0;
}