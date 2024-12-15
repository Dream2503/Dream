#include <stdio.h>
#include <stdlib.h>
typedef struct Matrix {int *array, len;} Matrix;

void set(Matrix *matrix, int i, int j, int value) {if (i >= j) matrix->array[(i*(i-1)/2)+j-1] = value; }
int get(Matrix matrix, int i, int j) {
    if (i >= j) return matrix.array[(i*(i-1)/2)+j-1];
    else return 0;
}
void display(Matrix matrix) {
    for (int i = 1; i <= matrix.len; i++) {
        for (int j = 1; j <= matrix.len; j++) {
            if (i >= j) printf("%d ", matrix.array[(i*(i-1)/2)+j-1]);
            else printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Matrix matrix;
    int value;
    printf("Enter dimension of the matrix: ");
    scanf("%d", &matrix.len);
    matrix.array = (int*)malloc(matrix.len*(matrix.len-1)/2*sizeof(int));
    printf("Enter all elements:\n");

    for (int i = 1; i <= matrix.len; i++)
        for (int j = 1; j <= matrix.len; j++) {
            scanf("%d", &value);
            set(&matrix, i, j, value);
        }
    printf("\n\n");
    display(matrix);
    return 0;
}