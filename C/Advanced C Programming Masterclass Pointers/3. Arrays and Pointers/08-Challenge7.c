#include <stdio.h>

void frequencyArray(int *array, int size) {
    int cnt = 1, skip = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (i != j && array[i] == array[j]) {
                if (j > i)
                    cnt++;
                else {
                    skip = 1;
                    break;
                }
            }
        }
        if (!skip) {
            printf("%d appears %d times\n", array[i], cnt);
            cnt = 1;
        }
    }
}

int main() {
    int lst[] = {5, 6, 7, 6, 5};
    frequencyArray(lst, 5);
    return 0;
}