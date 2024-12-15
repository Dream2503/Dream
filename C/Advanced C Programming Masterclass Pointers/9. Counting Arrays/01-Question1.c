#include <stdio.h>
#include <stdlib.h>

int freqAsValue(int *array, int size, int key) {
    int *cntArray = (int*)calloc(key+1, sizeof(int));

    for (int i = 0; i < size; i++)
        cntArray[array[i]]++;
    
    for (int i = 0; i < key; i++) {
        if (i != cntArray[i]) {
            free(cntArray);
            return 0;
        }
    }
    free(cntArray);
    return 1;
}

int main() {
    int array[] = {3, 2, 2, 1, 3, 3};
    printf("%d", freqAsValue(array, 6, 3));
    return 0;
}