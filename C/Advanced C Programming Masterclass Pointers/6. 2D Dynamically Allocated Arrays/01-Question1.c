#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    
    free(matrix);
}
int **createMatrix(int rows, int columns) {
    int **matrix = (int**)calloc(rows, sizeof(int*));
    if (!matrix) return NULL;
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)calloc(columns, sizeof(int));
        if (!matrix[i]) freeMatrix(matrix, rows);

        for (int j = 0; j < columns; j++) {
            printf("Enter the value of %dth row and %dth column: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}
void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        
        printf("\n");
    }
}

void swapRows(void **matrix, int row1, int row2) {
    void *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}
void swapColumns(int **matrix, int rows, int column1, int column2) {
    int temp;

    for (int i = 0; i < rows; i++) {
        temp = matrix[i][column1];
        matrix[i][column1] = matrix[i][column2];
        matrix[i][column2] = temp;
    }
}

int main() {
    int rows = 3, columns = 3;
    int **matrix = createMatrix(rows, columns);
    printMatrix(matrix, rows, columns);
    swapColumns(matrix, 3, 0, 2);
    printf("\n");
    printMatrix(matrix, rows, columns);
    freeMatrix(matrix, rows);
    return 0;
}