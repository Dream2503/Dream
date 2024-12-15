#include <stdio.h>

void printArray(int *array, int size) {
    printf("%d ", *array);

    if (size > 1)
        printArray(array + 1, size - 1);
}
void printArrayRev(int *array, int size) {
    printf("%d ", *(array + (size - 1)));

    if (size > 1)
        printArrayRev(array, size - 1);
}

int main() {
    int lst[] = {1, 3, 2, 4};
    printArray(lst, 4);
    printf("\n");
    printArrayRev(lst, 4);
    return 0;
}