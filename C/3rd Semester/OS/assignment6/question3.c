/*  Q3. Write a program that will accept two matrices and create a sub process child. The child has to perform the addition of two matrices and the
        parent has to perform the multiplication of two matrices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int** add_matrix(int**, int, int, int**, int, int);
int** multiply_matrix(int**, int, int, int**, int, int);
int** create_matrix(char[], int, int);
void display_matrix(char[], int**, int, int);
void deallocate(int**, int);

int main() {
    int row1, col1, row2, col2, **res = NULL;
    printf("Enter the dimension of the first matrix: ");
    scanf("%d%d", &row1, &col1);
    int** matrix1 = create_matrix("first", row1, col1);
    printf("Enter the dimension of the second matrix: ");
    scanf("%d%d", &row2, &col2);
    int** matrix2 = create_matrix("second", row2, col2);
    int pid = fork();

    if (pid > 0) {
        res = multiply_matrix(matrix1, row1, col1, matrix2, row2, col2);
        wait(NULL);
        display_matrix("product", res, row1, col2);

        if (res) {
            deallocate(res, row1);
        }
        deallocate(matrix1, row1);
        deallocate(matrix2, row2);
    } else if (pid == 0) {
        res = add_matrix(matrix1, row1, col1, matrix2, row2, col2);
        display_matrix("sum", res, row1, col1);

        if (res) {
            deallocate(res, row1);
        }
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}

int** add_matrix(int** matrix1, int row1, int col1, int** matrix2, int row2, int col2) {
    if (row1 != row2 || col1 != col2) {
        printf("Invalid matrix order for addition\n");
        return NULL;
    }
    int **res = (int**)malloc(row1 * sizeof(int*)), i, j;

    if (!res) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (i = 0; i < row1; i++) {
        res[i] = (int*)malloc(col1 * sizeof(int));

        if (!res[i]) {
            printf("Memory was not allocated");
            exit(0);
        }
        for (j = 0; j < col1; j++) {
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return res;
}

int** multiply_matrix(int** matrix1, int row1, int col1, int** matrix2, int row2, int col2) {
    if (col1 != row2) {
        printf("Invalid matrix order for multiplication\n");
        return NULL;
    }
    int **res = (int**)malloc(row1 * sizeof(int*)), k, i, j;

    if (!res) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (k = 0; k < row1; k++) {
        res[k] = (int*)malloc(col2 * sizeof(int));

        if (!res[k]) {
            printf("Memory was not allocated");
            exit(0);
        }
        for (i = 0; i < col2; i++) {
            res[k][i] = 0;

            for (j = 0; j < row2; j++) {
                res[k][i] += matrix1[k][j] * matrix2[j][i];
            }
        }
    }
    return res;
}

int** create_matrix(char name[], int row, int col) {
    int **matrix = (int**)malloc(row * sizeof(int*)), i, j;

    if (!matrix) {
        printf("Memory was not allocated");
        exit(0);
    }
    printf("Enter elements of the %s matrix:\n", name);

    for (i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));

        if (!matrix[i]) {
            printf("Memory was not allocated");
            exit(0);
        }
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void display_matrix(char name[], int** matrix, int row, int col) {
    if (!matrix) {
        return;
    }
    int i, j;
    printf("\nThe elements in the %s matrix is:\n", name);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void deallocate(int** matrix, int row) {
    int i;

    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
