#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void insert(void *array, unsigned length, unsigned valueSize, unsigned idx) {
    void *lst = malloc((--length)*valueSize);
    int sizeTillIdx = idx * valueSize;

    memcpy(lst, array, sizeTillIdx);
    memcpy(lst+sizeTillIdx, array+sizeTillIdx + valueSize, (length-idx)*valueSize);

    memcpy(array, lst, (++length)*valueSize);
}

int main() {
    int lst[] = {9.1, 1.3, 4.7, 7.2};
    int value = 3.2;
    insert(lst, 4, 4, 2);
    printArray(lst, 3);
    return 0;
}