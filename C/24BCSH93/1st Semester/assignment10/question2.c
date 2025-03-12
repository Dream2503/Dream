#include <stdio.h>

void printEvenRange(int, int);

int main() {
	int lr, ur;
	printf("Enter the lower range and upper range: ");
	scanf("%d%d", &lr, &ur);
	printEvenRange(lr, ur);
	return 0;
}

void printEvenRange(int lr, int ur) {
	printf("All the even numbers in the range %d to %d are:\n", lr, ur);

	for (; lr <= ur; lr++) {
		if (lr % 2 == 0) {
			printf("%d ", lr);
		}
	}
	printf("\n");
}