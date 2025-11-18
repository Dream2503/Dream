/*
Name:- Swapnaraj Mohanty
SIC:- 24BCSH93
Sec:- C2

Q. Write program by using function(intput(), display() to read a 2D array and display it in matrix format. Pass
necessary parameters in the function.
*/

#include <stdio.h>
#define n 10

void input(int[n][n], int, int);
void display(int[n][n], int, int);

int main() {
    int matrix[n][n], row, column;

    printf("Enter the no. of rows and column of the matrix: ");
    scanf("%d%d", &row, &column);
    input(matrix, row, column);
    display(matrix, row, column);
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
