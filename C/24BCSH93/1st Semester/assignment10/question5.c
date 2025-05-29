#include <stdio.h>

int sum(int[], int);
int oddCnt(int[], int);
void printEven(int[], int);
int min(int[], int);

int main() {
    int size, i, choice, res;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("\nSelect an operation to perform on the array\n");
    printf("1 - Sum of all the array elements\n");
    printf("2 - Count the odd elements os the array\n");
    printf("3 - Even elements of the array\n");
    printf("4 - Smallest element of the array\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nSum of all the elements of the array is %d\n", sum(array, size));
            break;
        case 2:
            printf("\nTotal number of odd elements in the array is %d\n", oddCnt(array, size));
            break;
        case 3:
            printEven(array, size);
            break;
        case 4:
            printf("\nSmallest element of the array is %d\n", min(array, size));
            break;
        default:
            printf("\nInvalid Choice\n");
    }
    return 0;
}

int sum(int array[], int size) {
    int res = 0, i;

    for (i = 0; i < size; i++) {
        res += array[i];
    }
    return res;
}

int oddCnt(int array[], int size) {
    int cnt = 0, i;

    for (i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            cnt++;
        }
    }
    return cnt;
}

void printEven(int array[], int size) {
    int i;
    printf("\nAll the even numbers in the array are: ");

    for (i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int min(int array[], int size) {
    int i, low = array[0];

    for (i = 0; i < size; i++) {
        if (low > array[i]) {
            low = array[i];
        }
    }
    return low;
}
