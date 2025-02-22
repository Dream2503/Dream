#include <stdio.h>
#define max 10

void create(int[10][10], int, int);
void display_sparsh(int[10][10], int, int);
void sparsh_to_triplet(int[10][10], int, int, int[max][3]);
void display_triplet(int[max][3]);
void triplet_to_sparsh(int[max][3], int[10][10]);
void transpose(int[max][3], int[max][3]);

int main() {
    int matrix[10][10], row, column, triple[max][3], res[max][3];

    printf("Enter the row and column of the matrix: ");
    scanf("%d%d", &row, &column);

    create(matrix, row, column);
    sparsh_to_triplet(matrix, row, column, triple);
    transpose(triple, res);
    triplet_to_sparsh(res, matrix);
    display_sparsh(matrix, column, row);

    return 0;
}

void create(int matrix[10][10], int row, int column) {
    int i, j;

    printf("Enter the matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_sparsh(int matrix[10][10], int row, int column) {
    int i, j;

    printf("The matrix elements are:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sparsh_to_triplet(int matrix[10][10], int row, int column, int triple[max][3]) {
    int i, j, k = 1;
    triple[0][0] = row;
    triple[0][1] = column;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (matrix[i][j] != 0) {
                triple[k][0] = i;
                triple[k][1] = j;
                triple[k++][2] = matrix[i][j];
            }
        }
    }
    triple[0][2] = k - 1;
}

void display_triplet(int triple[max][3]) {
    int i;

    printf("The triplet matrix is:\n");
    for (i = 0; i <= triple[0][2]; i++) {
        printf("%d %d %d\n", triple[i][0], triple[i][1], triple[i][2]);
    }
}

void triplet_to_sparsh(int triple[max][3], int matrix[10][10]) {
    int i, j, k = 1;

    for (i = 0; i < triple[0][0]; i++) {
        for (j = 0; j < triple[0][1]; j++) {
            if (i == triple[k][0] && j == triple[k][1]) {
                matrix[i][j] = triple[k++][2];
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void transpose(int triple[max][3], int triple_transpose[max][3]) {
    int i, j, k = 1;

    triple_transpose[0][0] = triple[0][1];
    triple_transpose[0][1] = triple[0][0];
    triple_transpose[0][2] = triple[0][2];

    for (i = 0; i < triple[0][1]; i++) {
        for (j = 1; j <= triple[0][2]; j++) {
            if (triple[j][1] == i) {
                triple_transpose[k][0] = triple[j][1];
                triple_transpose[k][1] = triple[j][0];
                triple_transpose[k][2] = triple[j][2];
                k++;
            }
        }
    }
}