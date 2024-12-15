#include <stdio.h>

int findMax(int array[], int size) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int main() {
    int lst[] = {80, 85, 72, 90};
    int max = findMax(lst, sizeof(lst)/sizeof(lst[0]));
    printf("max = %d", max);
    return 0;
}