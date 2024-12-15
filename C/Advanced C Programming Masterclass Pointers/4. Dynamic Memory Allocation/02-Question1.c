#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *myRealloc(void *srcblock, unsigned oldsize, unsigned newsize) {
    void *result = malloc(newsize);

    if (newsize < oldsize)
        newsize = oldsize;
    
    memcpy(result, srcblock, newsize);
    return result;
}

int main() {
    int *array, *temp;
    array = (int*)malloc(3 * sizeof(int));
    if (array == NULL) return 1;
    array[0] = 3; array[1] = 2; array[2] = 1;
    temp = (int*)myRealloc(array, 3*sizeof(int), 4*sizeof(int));
    if (temp == NULL) return 1;
    array = temp;

    for (int i = 0; i < 4; i++)
        printf("%d ", *(array + i));

    return 0;
}