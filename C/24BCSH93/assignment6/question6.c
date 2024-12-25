#include <stdio.h>

int main() {
	int num, i, j, space = 0;
	printf("Enter the number: ");
	scanf("%d", &num);

	for (i = num; i >= 1; i--) {
		for (j = 1; j <= space; j++) {
			printf("  ");
		}
		for (j = 1; j <= i*2-1; j++) {
			printf("* ");
		}
		space++;
		printf("\n");
	}
	return 0;
}
