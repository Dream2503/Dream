#include <stdio.h>

int main() {
    int lr, ur;
    printf("Enter the lower range and upper range of the numbers: ");
    scanf("%d%d", &lr, &ur);

    for (; lr <= ur; lr++)
        if (lr % 2) {
            printf("%d ", lr);
        }
    printf("\n");
    return 0;
}
