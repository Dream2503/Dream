#include <stdio.h>

void missing_element_natural_number(int *array, int size, int high) {
    int sum = 0, res = high * (high + 1) / 2, i;

    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    printf("missing element is %d", res - sum);
}

void missing_element_sequence(int *array, int size) {
    int difference = array[0], i;

    for (i = 1; i < size; i++) {
        if (array[i] - i != difference) {
            printf("missing element is %d", difference + i);
            break;
        }
    }
}

void missing_more_element_sequence(int *array, int size) {
    int difference = array[0], i;

    for (i = 1; i < size; i++) {
        if (array[i] - i != difference) {
            printf("missing element is %d\n", difference + i);
            difference++, i--;
        }
    }
}

void missing_more_element_sequence_hash(int *array, int size, int low, int high) {
    int hash[high + 1], i;

    for (i = low; i <= high; i++) {
        hash[i] = 0;
    }
    for (i = 0; i < size; i++) {
        hash[array[i]]++;
    }
    for (i = low; i <= high; i++) {
        if (!hash[i]) {
            printf("missing element is %d\n", i);
        }
    }
}

void duplicate_sorted_array(int *array, int size) {
    int last_duplicate = 0, i;

    for (i = 1; i < size; i++) {
        if (array[i] == array[i - 1] && last_duplicate != array[i]) {
            last_duplicate = array[i];
            printf("duplicate element is %d\n", array[i++]);
        }
    }
}

void count_duplicate_sorted_array(int *array, int size) {
    int cnt = 1, i, j;

    for (i = 1; i < size; i++) {
        if (array[i] == array[i - 1]) {
            cnt++;

            for (j = i + 1; j < size; j++, i++) {
                if (array[j] != array[j - 1]) {
                    break;
                }
                cnt++;
            }
            printf("duplicate element is %d, %d times\n", array[i++], cnt);
            cnt = 1;
        }
    }
}

void count_duplicate_array(int *array, int size) {
    int cnt = 1, i, j;

    for (i = 0; i < size; i++) {
        if (array[i] == -1) {
            continue;
        }
        for (j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                array[j] = -1;
                cnt++;
            }
        }
        if (cnt > 1) {
            printf("duplicate element is %d, %d times\n", array[i], cnt);
            cnt = 1;
        }
    }
}

void count_duplicate_array_hash(int *array, int size, int low, int high) {
    int hash[high + 1], i;

    for (i = low; i <= high; i++) {
        hash[i] = 0;
    }
    for (i = 0; i < size; i++) {
        hash[array[i]]++;
    }
    for (i = low; i <= high; i++) {
        if (hash[i] > 1) {
            printf("duplicate element is %d, %d times\n", i, hash[i]);
        }
    }
}

void pair_sum_array(int *array, int size, int sum) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] + array[j] == sum) {
                printf("%d + %d = %d\n", array[i], array[j], sum);
            }
        }
    }
}

void pair_sum_array_hash(int *array, int size, int sum, int high) {
    int hash[high + 1];

    for (int i = 0; i <= high; i++) {
        hash[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        hash[array[i]]++;
    }
    for (int i = 0; i < size; i++) {
        if (array[i] <= sum && hash[sum - array[i]]) {
            printf("%d + %d = %d\n", array[i], sum - array[i], sum);
            hash[array[i]]--;
        }
    }
}

void pair_sum_sorted_array(int *array, int size, int sum) {
    int i = 0, j = size - 1;

    while (i < j) {
        if (array[i] + array[j] == sum) {
            printf("%d + %d = %d\n", array[i++], array[j--], sum);
        } else if (array[i] + array[j] > sum) {
            j--;
        } else {
            i++;
        }
    }
}

void max_min(int *array, int size) {
    int max = array[0], min = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }
    printf("max -> %d\nmin -> %d", max, min);
}

int main() {
    int array[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    missing_more_element_sequence(array, 11);
}
