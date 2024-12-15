#include <stdio.h>

int sumArray(int array[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += array[i];
    
    return sum;
}

float averageArray(int array[], int size) {
    return sumArray(array, size) / (float)size;
}

int main() {
    int lst[] = {80, 85, 72, 90};
    float average = averageArray(lst, sizeof(lst)/sizeof(lst[0]));
    printf("max = %.2f", average);
    return 0;
}