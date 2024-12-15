#include <stdio.h>

float averageArray(int *array, int size) {
    if (size == 1)
        return *array;
    
    return (*array + (size - 1) * averageArray(array + 1, size - 1)) / (float)size;
}

int main() {
    int lst[] = {1, 4, 3};
    printf("%f", averageArray(lst, 3));
    return 0;
}