#include <stdio.h>
#include <stdlib.h>

int *createArray(int *size) {
    int *temp,  *array = (int*)malloc(sizeof(int));
    int value, idx = 0, len = 1;
    if (array == NULL) return NULL;

    while (1) {
        printf("Enter the element: ");
        scanf("%d", &value);

        if (value == -1) {
            temp = (int*)realloc(array, idx*sizeof(int));
            if (temp == NULL) return NULL;
            array = temp;
            *size = idx;
            return array;
        }
        
        if ((idx + 1) == len) {
            len *= 2;
            temp = (int*)realloc(array, len*sizeof(int));
            if (temp == NULL) return NULL;
            array = temp;
        }
        array[idx] = value;
        idx++;
    }
}

int main() {
    int size, *array = createArray(&size);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}