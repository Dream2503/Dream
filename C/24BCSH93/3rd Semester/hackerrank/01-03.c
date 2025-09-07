#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int *res = (int*)malloc(sizeof(int) * 2), i;
    res[0] = 0;
    res[1] = 0;

    for (i = 0; i < 3; i++) {
        if (a[i] < b[i]) {
            res[1]++;
        } else if (a[i] > b[i]) {
            res[0]++;
        }
    }
    *result_count = 2;
    return res;
}
