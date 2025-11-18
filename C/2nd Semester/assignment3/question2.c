/*
Name:- Swapnaraj Mohanty
SIC:- 24BCSH93
Sec:- C2

Q. Write program by using function(intput(), transpose(), display() to input a matrix, transpose it and display the
transposed matrix. Pass necessary parameters in the function.
*/

#include <stdio.h>
#define n 10

void input(int[n][n], int, int);
void transpose(int[n][n], int, int, int[n][n]);
void display(int[n][n], int, int);

int main() {
    int matrix[n][n], row, column, transposed[n][n];

    printf("Enter the no. of rows and column of the matrix: ");
    scanf("%d%d", &row, &column);
    input(matrix, row, column);
    transpose(matrix, row, column, transposed);
    display(transposed, column, row);
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

void transpose(int matrix[n][n], int row, int column, int transposed[n][n]) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            transposed[j][i] = matrix[i][j];
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
