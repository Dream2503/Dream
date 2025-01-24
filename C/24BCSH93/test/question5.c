#include <stdio.h>

int main() {
	int row, i, j, cnt = 1;
	printf("Enter the rows: ");
	scanf("%d", &row);
	
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", cnt);
			cnt++;
		}
		printf("\n");
	}
	return 0;
}