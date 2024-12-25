#include <stdio.h>

int main() {
	int num, i, j;
	printf("Enter the number: ");
	scanf("%d", &num);

	for (i = num; i > 0; i--) {
		for (j = 1; j <= i; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
