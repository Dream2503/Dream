#include <stdio.h>
#include <stdlib.h>

int *noDuplicateArray(int *array, int size, int *len) {
    int *lst = (int*)malloc(size*sizeof(int));
    int cnt = 0;
    lst[0] = array[0];

    for (int i = 1; i < size; i++) {
        if (lst[cnt] != array[i]) {
            cnt++;
            lst[cnt] = array[i];
        }
    }
    *len = ++cnt;
    return realloc(lst, ++cnt*sizeof(int));
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

int main() {
    int array[] = {1, 3, 3, 5, 6, 7, 7, 7, 8, 12, 12};
    int size;
    int *lst = noDuplicateArray(array, 11, &size);
    printArray(lst, size);
    return 0;
}