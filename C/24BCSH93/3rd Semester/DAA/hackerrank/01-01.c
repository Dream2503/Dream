#include <stdio.h>

void miniMaxSum(int arr_count, int* arr) {
    long int min = arr[0], max = arr[0], sum = 0;
    int i;

    for (i = 0; i < 5; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
        sum += arr[i];
    }
    printf("%ld %ld", sum - max, sum - min);
}
