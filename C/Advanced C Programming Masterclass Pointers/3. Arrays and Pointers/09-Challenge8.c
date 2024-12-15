#include <stdio.h>

int secondSmallest(int *array, int size) {
    int firstSmall = array[0], secondSmall = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < firstSmall) {
            secondSmall = firstSmall;
            firstSmall = array[i];
        } else if (array[i] < secondSmall)
            secondSmall = array[i];
    }
    return secondSmall;
}

int main() {
    int lst[] = {4, 9, 5, 6, 9};
    printf("Second smallest number is %d", secondSmallest(lst, 5));
    return 0;
}