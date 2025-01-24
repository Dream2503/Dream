#include <stdio.h>

int main() {
	int row, column, i, j, zero_elements = 0, non_zero_elements = 0;
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
			if (mat[i][j] == 0) {
				zero_elements++;
			} else {
				non_zero_elements++;
			}
		}
	}
	if (zero_elements > non_zero_elements) {
		printf("It is a sparse matrix\n");
	} else {
		printf("It is not a sparse matrix\n");
	}
	return 0;
}