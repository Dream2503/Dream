#include <math.h>
#include <stdio.h>

int main() {
    int a, b, c, determinant;
    float root1, root2;
    printf("Enter the values of a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a == 0 || b == 0) {
        printf("No solution exists\n");
    } else {
        determinant = (b * b) - (4 * a * c);

        if (determinant < 0) {
            printf("No real roots exists\n");
        } else {
            root1 = (-b + sqrt(determinant)) / (2.0 * a);

            if (determinant == 0) {
                printf("only one root exist %f\n", root1);
            } else {
                printf("root1 = %f\n", root1);
                root2 = (-b - sqrt(determinant)) / (2.0 * a);
                printf("root2 = %f\n", root2);
            }
        }
    }
    return 0;
}
