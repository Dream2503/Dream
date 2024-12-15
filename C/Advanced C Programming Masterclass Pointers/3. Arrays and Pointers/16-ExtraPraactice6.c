#include <stdio.h>

int func(float *array, int size) {
    if (size == 1)
        return 1;
    
    if (((int)*array < (int)*(array + 1)) && (*array - (int)*array) > (*(array + 1) - (int)*(array + 1)))
        return func(array + 1, size - 1);
      
    return 0;
}

int main() {
    float lst[] = {1.4, 3.25, 4.26};
    printf("%d", func(lst, 3));
    return 0;
}