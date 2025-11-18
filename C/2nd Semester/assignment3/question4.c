/*
Name:- Swapnaraj Mohanty
SIC:- 24BCSH93
Sec:- C2

Q. Write program by using function(intput(), multiply(), display() to input two matrices and do the matrix
multiplication after checking suitable condition. Pass necessary parameters in the function.
*/

#include <stdio.h>
#define n 10

void input(int[n][n], int, int);
void multiply(int[n][n], int, int, int[n][n], int, int, int[n][n]);
void display(int[n][n], int, int);

int main() {
    int matrix1[n][n], row1, column1, matrix2[n][n], row2, column2, res[n][n];

    printf("Enter the no. of rows and columns of the matrix1: ");
    scanf("%d%d", &row1, &column1);
    printf("Enter the no. of rows and columns of the matrix2: ");
    scanf("%d%d", &row2, &column2);

    if (column1 != row2) {
        printf("Invalid dimension for matrix multiplication\n");
        return 0;
    }
    input(matrix1, row1, column1);
    input(matrix2, row2, column2);
    multiply(matrix1, row1, column1, matrix2, row2, column2, res);
    display(res, row1, column2);
    return 0;
}

void input(int matrix[n][n], int row, int column) {
    int i, j;

    printf("Enter the matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiply(int matrix1[n][n], int row1, int column1, int matrix2[n][n], int row2, int column2, int res[n][n]) {
    int i, j, k;

    for (k = 0; k < row1; k++) {
        for (i = 0; i < column2; i++) {
            res[k][i] = 0;

            for (j = 0; j < column1; j++) {
                res[k][i] += matrix1[k][j] * matrix2[j][i];
            }
        }
    }
}

void display(int matrix[n][n], int row, int column) {
    int i, j;

    printf("The matrix elements are:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
