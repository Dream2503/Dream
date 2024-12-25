#include <stdio.h>

int main() {
	int row, column, i, j, row_sum = 0, column_sum = 0;
	printf("Enter the dimension of the matrix: ");
	scanf("%d%d", &row, &column);
	int mat[row][column];
	printf("Enter the elements of the matrix row wise:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			row_sum += mat[i][j];
			column_sum += mat[j][i];
		}
		printf("Sum of row%d is %d\n", i+1, row_sum);
		printf("Sum of column%d is %d\n", i+1, column_sum);
		row_sum = column_sum = 0;
	}
	return 0;
}
