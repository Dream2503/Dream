#include <stdio.h>

int main() {
    float bs, gs;
    printf("Enter the basic salary: ");
    scanf("%f", &bs);
    gs = bs;

    if (bs <= 10000) {
        gs += 0.2 * bs + 0.8 * bs;
    } else {
        gs += 0.3 * bs + 0.95 * bs;
    }
    printf("The gross salary is %f\n", gs);
    return 0;
}
