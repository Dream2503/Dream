#include <stdio.h>

int checkSignArray(int array[], int size) {
    if (size <= 1)
        return 1;
    
    if ((*array > 0 && *(array + 1) < 0) || (*array < 0 && *(array + 1) > 0))
        return checkSignArray(array + 1, size - 1);
    else
        return 0;
}

int main() {
    int lst[] = {1, -2, 4, 5, -3};
    printf("%d", checkSignArray(lst, 5));
    return 0;
}