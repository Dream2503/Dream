#include <stdio.h>

int isSorted(int *array, int size, int *res) {
    for (int i = 1; i < size; i++) {
        if (array[i-1] > array[i]) {
            *res = 0;
            return 0;
        } else if (array[i-1] < array[i] && *res)
            *res = 1;
        else 
            *res = 0;
    }
    return 1;
}

int isSortedRecur(int *array, int size, int *res) {
    int rtn = 1;

    if (size >= 2) {
        if (array[size-2] > array[size-1]) {
            *res = 0;
            return 0;
        } else if (array[size-2] < array[size-1] && *res)
            *res = 1;
        else
            *res = 0;

        rtn = isSortedRecur(array, size-1, res);
    }
    return rtn;
}

int main() {
    int lst[] = {1, 2, 5, 7, 10}, res, rtn;
    rtn = isSortedRecur(lst, 5, &res);
    printf("return = %d\nreference = %d", rtn, res);
    return 0;   
}