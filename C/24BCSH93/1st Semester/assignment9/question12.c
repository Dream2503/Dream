#include <stdio.h>

void matAdd(int row, int column, int[row][column], int[row][column], int[row][column]);

int main() {
	int row, column, i, j;
	printf("Enter the dimension of the matrices: ");
	scanf("%d%d", &row, &column);
	int mat1[row][column], mat2[row][column], res[row][column];
	printf("Enter the elements of the first matrix row wise:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}
	printf("Enter the elements of the second matrix row wise:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}
	matAdd(row, column, mat1, mat2, res);
	printf("The resultant matrix elements are:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void matAdd(int row, int column, int mat1[row][column], int mat2[row][column], int res[row][column]) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}