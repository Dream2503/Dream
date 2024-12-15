#include <stdio.h>

int isGoodNeighbour(int array[], int size) {
    for (int i = 1; i < size - 1; i++)
        if (array[i] == array[i-1] + array[i+1])
            return 1;
    
    return 0;
}

int main() {
    int lst[] = {1, 4, 1, 4, 2};
    printf("%d", isGoodNeighbour(lst, 5));
    return 0;
}