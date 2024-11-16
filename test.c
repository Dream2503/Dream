#include <stdio.h>

int main() {
    int size, i, temp;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];

    printf("Enter all %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < size/2; i++) {
        temp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = temp;
    }
    printf("Reversed array is: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

/* OUTPUT -
Enter the size of the array: 5
Enter all 5 elements: 1 2 3 4 5
Reversed array is: 5 4 3 2 1 
*/