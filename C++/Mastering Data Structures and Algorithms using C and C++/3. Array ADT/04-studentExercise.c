#include <stdio.h>

void missingElementNaturalNumber(int *array, int size, int high) {
    int sum = 0, res = high * (high + 1) / 2;
    for (int i = 0; i < size; i++) sum += array[i];
    printf("missing element is %d", res - sum);
}
void missingElementSequence(int *array, int size) {
    int difference = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] - i != difference) {
            printf("missing element is %d", difference + i);
            break;
        }
}
void missingMoreElementSequence(int *array, int size) {
    int difference = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] - i != difference) {
            while (difference + i < array[i]) {
                printf("missing element is %d\n", difference + i);
                difference++;
            }
        }
}
void missingMoreElementSequenceHash(int *array, int size, int low, int high) {
    int hash[high+1];
    for (int i = low; i <= high; i++) hash[i] = 0;
    for (int i = 0; i < size; i++) hash[array[i]]++;
    for (int i = low; i <= high; i++) if (!hash[i]) printf("missing element is %d\n", i);
}
void duplicateSortedArray(int *array, int size) {
    int last_duplicate = 0;

    for (int i = 1; i < size; i++) 
        if (array[i] == array[i-1] && last_duplicate != array[i]) {
            last_duplicate = array[i];
            printf("duplicate element is %d\n", array[i++]);
        }
}
void countDuplicateSortedArray(int *array, int size) {
    int last_duplicate = 0, cnt = 1;

    for (int i = 1; i < size; i++) 
        if (array[i] == array[i-1]) {
            cnt++;
            for (int j = i + 1; j < size; j++, i++) {
                if (array[j] != array[j-1]) break;
                cnt++;
            }
            printf("duplicate element is %d, %d times\n", array[i++], cnt);
            cnt = 1;
        }
}
void countDuplicateArray(int *array, int size) {
    int cnt = 1;
    for (int i = 0; i < size; i++) {
        if (array [i] == -1) continue;

        for (int j = i + 1; j < size; j++) {
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
void countDuplicateArrayHash(int *array, int size, int low, int high) {
    int hash[high+1];
    for (int i = low; i <= high; i++) hash[i] = 0;
    for (int i = 0; i < size; i++) hash[array[i]]++;
    for (int i = low; i <= high; i++) if (hash[i] > 1) printf("duplicate element is %d, %d times\n", i, hash[i]);
}
void pairSumArray(int *array, int size, int sum) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] + array[j] == sum)
                printf("%d + %d = %d\n", array[i], array[j], sum);
        }
    }
}
void pairSumArrayHash(int *array, int size, int sum, int high) {
    int hash[high+1];
    for (int i = 0; i <= high; i++) hash[i] = 0;
    for (int i = 0; i < size; i++) hash[array[i]]++;
    for (int i = 0; i < size; i++) {
        if (array[i] <= sum && hash[sum-array[i]]) {
            printf("%d + %d = %d\n", array[i], sum - array[i], sum);
            hash[array[i]]--;
        }
    }
}
void pairSumSortedArray(int *array, int size, int sum) {
    int i = 0, j = size - 1;
    while (i < j) {
        if (array[i] + array[j] == sum) printf("%d + %d = %d\n", array[i++], array[j--], sum);
        else if (array[i] + array[j] > sum) j--;
        else i++;
    }
}
void maxMin(int *array, int size) {
    int max = array[0], min = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] < min) min = array[i];
        else if (array[i] > max) max = array[i];
    }
    printf("max -> %d\nmin -> %d", max, min);
}

int main() {
    int array[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    maxMin(array, 10);
}