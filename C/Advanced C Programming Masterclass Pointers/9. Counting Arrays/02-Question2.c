#include <stdio.h>
#include <stdlib.h>

intfFindDominantValue(int *array, int size) {
    int *cntArray = (int*)calloc(size+1, sizeof(int));

    for (int i = 0; i < size; i++)
        cntArray[array[i]]++;
    
    for (int i = 0; i < size; i++) {
        if (cntArray[i] > size/2) {
            free(cntArray);
            return 1;
        }
    }
    free(cntArray);
    return 0;
}

int main() {
    int array[] = {3, 5, 4, 2, 3};
    printf("%d", findDominantValue(array, 5));
    return 0;
}