#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    
    free(matrix);
}
void createMatrix(int ***matrix, int rows, int columns) {
    *matrix = (int**)calloc(rows, sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int*)calloc(columns, sizeof(int));
        if (!(*matrix)[i]) freeMatrix(*matrix, rows);

        for (int j = 0; j < columns; j++) {
            printf("Enter the value of %dth row and %dth column: ", i+1, j+1);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}
void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        
        printf("\n");
    }
}

int main() {
    int rows = 3, columns = 3;
    int **matrix;
    createMatrix(&matrix, rows, columns);
    printMatrix(matrix, rows, columns);
    return 0;
}