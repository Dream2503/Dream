#include <stdio.h>

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
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	printf("The resultant matrix elements are:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}