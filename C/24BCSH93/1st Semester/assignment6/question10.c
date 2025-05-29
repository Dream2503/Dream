#include <stdio.h>

int main() {
    int lr, ur;
    printf("Enter the lower range and the upper range number: ");
    scanf("%d%d", &lr, &ur);

    for (; lr <= ur; lr++) {
        if (lr % 35 == 0) {
            printf("%d ", lr);
        }
    }
    printf("\n");
    return 0;
}
