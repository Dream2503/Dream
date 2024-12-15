#include <stdio.h>
#include <stdlib.h>

int **createLowerTriangularMatrix(int rowsColumns) {
    int **matrix = (int**)calloc(rowsColumns, sizeof(int*));

    for (int i = 0; i < rowsColumns; i++){
        matrix[i] = (int*)calloc(i+1, sizeof(int));

        for (int j = 0; j <= i; j++) {
            printf("Enter the value of %dth row and %dth column: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}
void printLowerTriangularMatrix(int **matrix, int rowsColumns) {
    for (int i = 0; i < rowsColumns; i++) {
        for (int j = 0; j < rowsColumns; j++) {
            if (j > i)
                printf("0 ");
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createUpperTriangularMatrix(int rowsColumns) {
    int **matrix = (int**)calloc(rowsColumns, sizeof(int*));

    for (int i = 0; i < rowsColumns; i++) {
        matrix[i] = (int*)calloc(rowsColumns-i, sizeof(int*));

        for (int j = 0; j < rowsColumns-i; j++) {
            printf("Enter the value of %dth row and %dth column: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}
void printUpperTriangularMatrix(int **matrix, int rowsColumns) {
    for (int i = 0; i < rowsColumns; i++) {
        for (int j = 0; j < rowsColumns; j++) {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", matrix[i][j-i]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int **matrix = createUpperTriangularMatrix(n);
    printUpperTriangularMatrix(matrix, n);
    return 0;
}