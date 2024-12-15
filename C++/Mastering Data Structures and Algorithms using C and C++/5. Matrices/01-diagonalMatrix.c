#include <stdio.h>
typedef struct Matrix {int array[10], len;} Matrix;

void set(Matrix *matrix, int i, int j, int value) {if (i == j) matrix->array[i-1] = value; }
int get(Matrix matrix, int i, int j) {
    if (i == j) return matrix.array[i-1];
    else return 0;
}
void display(Matrix matrix) {
    for (int i = 0; i < matrix.len; i++) {
        for (int j = 0; j < matrix.len; j++) {
            if (i == j) printf("%d ", matrix.array[i]);
            else printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Matrix matrix;
    matrix.len = 4;
    set(&matrix, 1, 1, 5);
    set(&matrix, 2, 2, 8);
    set(&matrix, 3, 3, 9);
    set(&matrix, 4, 4, 12);
    printf("%d\n", get(matrix, 2, 2));
    display(matrix);
    return 0;
}