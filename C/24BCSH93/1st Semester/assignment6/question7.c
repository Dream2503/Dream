#include <stdio.h>

int main() {
    int lr, ur, i, flag = 0;
    printf("Enter lower range and upper range number: ");
    scanf("%d%d", &lr, &ur);

    for (; lr <= ur; lr++) {
        flag = 0;

        for (i = 2; i <= lr / 2; i++) {
            if (lr % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d ", lr);
        }
    }
    printf("\n");
    return 0;
}
