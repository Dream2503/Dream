#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void copy(int *array, unsigned size, int **rtnArray) {
    *rtnArray = (int*)malloc(size*sizeof(int));
    
    for (int i = 0; i < size; i++)
        (*rtnArray)[i] = array[i];
    
}

int main() {
    int lst[] = {9, 1, 4, 7};
    int *cpylst;
    copy(lst, 4, &cpylst);
    printArray(cpylst, 4);
    return 0;
}