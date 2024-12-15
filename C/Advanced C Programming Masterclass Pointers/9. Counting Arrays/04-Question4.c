#include <stdio.h>
#include <stdlib.h>

int findLargestMissingValue(int *array, int size) {
    int *cntArray = (int*)calloc(size+1, sizeof(int));
    int max = 0;

    for (int i = 0; i < size; i++)
        cntArray[array[i]]++;
    
    for (int i = size; i >= 0; i--) {
        if (cntArray[i] == 0) {
            free(cntArray);
            return i;
        }       
    }
    free(cntArray);
    return -1;
}

int main() {
    int array[] = {2, 1, 3, 2, 7, 2, 2};
    printf("%d", findLargestMissingValue(array, 7));
    return 0;
}