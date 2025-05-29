#include <stdio.h>

int main() {
    int array[5], cnt = 0, i;
    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < 5; i++) {
        if (array[i] % 2 == 0)
            cnt++;
    }
    printf("No. of even elements are: %d\n", cnt);
    return 0;
}
