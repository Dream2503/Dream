/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program by using function to input the above sparse matrix you have obtained in Q1 and convert that to a
general matrix form and display. Verify whether it is the same matrix you have inputted in Q1
*/

#include <stdio.h>
#define n 10

void read_sparse(int[n][3]);
void create_matrix(int[n][3], int[n][n]);
void display_matrix(int[n][n], int, int);

int main() {
    int triplet[n][3], matrix[n][n];

    read_sparse(triplet);
    create_matrix(triplet, matrix);
    display_matrix(matrix, triplet[0][0], triplet[0][1]);
    return 0;
}

void read_sparse(int triplet[n][3]) {
    int i;

    printf("Enter the no. of rows, columns and no. of non-zero elements of the sparse matrix: ");
    scanf("%d%d%d", &triplet[0][0], &triplet[0][1], &triplet[0][2]);

    printf("Enter the triplet elements:\n");
    for (i = 1; i <= triplet[0][2]; i++) {
        scanf("%d%d%d", &triplet[i][0], &triplet[i][1], &triplet[i][2]);
    }
}

void create_matrix(int triplet[n][3], int matrix[n][n]) {
    int i, j, k = 1;

    for (i = 0; i < triplet[0][0]; i++) {
        for (j = 0; j < triplet[0][1]; j++) {
            if (k <= triplet[0][2] && i == triplet[k][0] && j == triplet[k][1]) {
                matrix[i][j] = triplet[k++][2];
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void display_matrix(int matrix[n][n], int row, int column) {
    int i, j;

    printf("The matrix elements are:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
