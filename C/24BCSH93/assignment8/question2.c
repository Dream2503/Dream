#include <stdio.h>

int main() {
	int row, column, trans_row, trans_column, i, j;
	printf("Enter the dimension of the matrix: ");
	scanf("%d%d", &row, &column);
	trans_row = column;
	trans_column = row;

	int mat[row][column], res[trans_row][trans_column];
	printf("Enter the elements of the matrix row wise:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			res[j][i] = mat[i][j];
		}
	}
	printf("The transpose matrix elements are:\n");

	for (i = 0; i < trans_row; i++) {
		for (j = 0; j < trans_column; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
