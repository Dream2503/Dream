#include <stdlib.h>

int* countingSort(int arr_count, int* arr, int* result_count) {
    int count[100] = {}, i, j, k = 0;
    int* res = (int*)malloc(sizeof(int) * arr_count);

    for (i = 0; i < arr_count; i++) {
        count[arr[i]]++;
    }
    for (i = 0; i < 100; i++) {
        for (j = 0; j < count[i]; j++) {
            res[k++] = i;
        }
    }
    *result_count = arr_count;
    return res;
}
