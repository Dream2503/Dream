/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to find the transpose of sparse matrix as per the specification given below:
(i) read_matrix(a[][max], m, n) to input a sparse matrix in general form.
(ii) create_sparse(a[][max], m, b, b[][3]) to create a sparse matrix in triple form.
(iii) transpose_sparse(a[][3], b[][3]) to transpose the sparse matrix
(iv) display_sparse(b[][3]) to display the sparse matrix in triple form.
*/

#include <stdio.h>
#define n 10

void read_matrix(int[n][n], int, int);
void create_sparse(int[n][n], int, int, int[n][3]);
void transpose_sparse(int[n][3], int[n][3]);
void display_sparse(int[n][3]);

int main() {
    int matrix[n][n], row, column, triplet[n][3], transposed_triplet[n][3];
    printf("Enter the no. of rows and columns of the matrix: ");
    scanf("%d%d", &row, &column);

    read_matrix(matrix, row, column);
    create_sparse(matrix, row, column, triplet);
    transpose_sparse(triplet, transposed_triplet);
    display_sparse(transposed_triplet);

    return 0;
}

void read_matrix(int matrix[n][n], int row, int column) {
    int i, j;

    printf("Enter the matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void create_sparse(int matrix[n][n], int row, int column, int triplet[n][3]) {
    int i, j, k = 0;

    triplet[0][0] = row;
    triplet[0][1] = column;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (matrix[i][j] != 0) {
                k++;
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
            }
        }
    }
    triplet[0][2] = k;
}

void transpose_sparse(int triplet[n][3], int transposed_triplet[n][3]) {
    int i, j, k = 1;

    transposed_triplet[0][0] = triplet[0][1];
    transposed_triplet[0][1] = triplet[0][0];
    transposed_triplet[0][2] = triplet[0][2];

    for (i = 0; i < triplet[0][1]; i++) {
        for (j = 1; j <= triplet[0][2]; j++) {
            if (triplet[j][1] == i) {
                transposed_triplet[k][0] = triplet[j][1];
                transposed_triplet[k][1] = triplet[j][0];
                transposed_triplet[k][2] = triplet[j][2];
                k++;
            }
        }
    }
}

void display_sparse(int triplet[n][3]) {
    int i;

    printf("The sparse triplet matrix is:\n");
    for (i = 0; i <= triplet[0][2]; i++) {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}
