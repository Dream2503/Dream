#include <stdio.h>

int idxSumTwo(int *array, int size, int value, int *idx1, int *idx2) {
    *idx1 = 0, *idx2 = size - 1;

    while(*idx1 < *idx2) {
        if (array[*idx1] + array[*idx2] < value)
            *idx1++;
        else if (array[*idx1] + array[*idx2] > value)
            *idx2--;
        else
            return 1;
    }
    *idx1 = *idx2 = 0;
    return 0;
}

int main() {
    int lst[] = {1, 3, 4, 7, 9, 10, 12};
    int value = 13, i, j;
    idxSumTwo(lst, 7, value, &i, &j);
    printf("%d %d", i, j);
    return 0;
}