#include <stdio.h>

void minMaxArray(int *array, int size, int *min, int *max) {
    *min = *max = array[0];

    for (int i = 1; i < size; i++) {
        if (*min > array[i])
            *min = array[i];
        
        if (*max < array[i])
            *max = array[i];
    }
}

int main() {
    int grades[] = {80, 90, 100}, min, max;
    minMaxArray(grades, sizeof(grades)/sizeof(grades[0]), &min, &max);
    printf("min = %d\nmax = %d", min, max);
    return 0;
}