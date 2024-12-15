#include <stdio.h>
#include <stdlib.h>

int findSpecificValueMaxSum(int *array, int size) {
    int *cntArray = (int*)calloc(size+1, sizeof(int));
    int max = 0;

    for (int i = 0; i < size; i++)
        cntArray[array[i]]++;
    
    for (int i = 0; i <= size; i++) {
        if (cntArray[i] * i > cntArray[max] * max)
            max = i;
    }
    free(cntArray);
    return max;
}

int main() {
    int array[] = {2, 1, 3, 2, 4, 2, 2};
    printf("%d", findSpecificValueMaxSum(array, 7));
    return 0;
}