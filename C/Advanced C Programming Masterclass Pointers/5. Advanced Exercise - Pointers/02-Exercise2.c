#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void splitEvenOdd(int *srcArray, int size, int **even, int *lenEven, int **odd, int *lenOdd) {
    *even = (int*)malloc(size*sizeof(int)), *odd = (int*)malloc(size*sizeof(int));
    *lenEven = *lenOdd = 0;

    for (int i = 0; i < size; i++) {
        if (srcArray[i] % 2 == 0) {
            (*even)[*lenEven] = srcArray[i];
            (*lenEven)++;
        } else {
            (*odd)[*lenOdd] = srcArray[i];
            (*lenOdd)++;
        }
    }
    *even = realloc(*even, (*lenEven)*sizeof(int)); *odd = realloc(*odd, (*lenOdd)*sizeof(int));
}

int main() {
    int lst[8] = {12, 5, 7, 8, 3, 10, 4, 9}, *even, *odd, lenEven, lenOdd;
    splitEvenOdd(lst, 8, &even, &lenEven, &odd, &lenOdd);
    printArray(even, lenEven); printArray(odd, lenOdd);
    return 0;
}