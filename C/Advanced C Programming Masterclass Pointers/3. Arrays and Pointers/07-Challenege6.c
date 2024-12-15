#include <stdio.h>

void reverseArray(char array[], int size) {
    char temp;
    for (int i = size-1; i >= size/2; i--) {
        temp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = temp;
    }
}

int main() {
    char lst[] = {'a', 'f', 'k', 'd'};
    reverseArray(lst, 4);
    
    for (int i = 0; i < 4; i++)
        printf("%c ", lst[i]);

    return 0;
}