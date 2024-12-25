#include <stdio.h>

int main() {
	int row, column, i, j;
	printf("Enter the dimension of the matrix: ");
	scanf("%d%d", &row, &column);
	int mat[row][column], trace = 0;
	printf("Enter the elements of the matrix row wise:\n");

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (i = 0; i < row && i < column; i++) {
		trace += mat[i][i];
	}
	printf("The trace of the matrix is %d\n", trace);
	return 0;
}
