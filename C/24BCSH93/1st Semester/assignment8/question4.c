#include <stdio.h>

int main() {
    int row1, column1, row2, column2, i, j, k;
    printf("Enter the dimension of first matrix: ");
    scanf("%d%d", &row1, &column1);
    printf("Enter the dimension of second matrix: ");
    scanf("%d%d", &row2, &column2);

    if (column1 != row2) {
        printf("Invalid row for matrix multiplication\n");
        return 0;
    }
    int mat1[row1][column1], mat2[row2][column2], res[row1][column2];
    printf("Enter the elements of the first matrix row wise:\n");

    for (i = 0; i < row1; i++) {
        for (j = 0; j < column1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix row wise:\n");

    for (i = 0; i < row2; i++) {
        for (j = 0; j < column2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    for (k = 0; k < row1; k++) {
        for (i = 0; i < column2; i++) {
            res[k][i] = 0;

            for (j = 0; j < column1; j++) {
                res[k][i] += mat1[k][j] * mat2[j][i];
            }
        }
    }
    printf("The resultant matrix elements are:\n");

    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
