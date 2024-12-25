#include <stdio.h>

int main() {
	int seconds, minutes, hours;
	printf("Enter the seconds: ");
	scanf("%d", &seconds);
	minutes = seconds / 60;
	seconds %= 60;
	hours = minutes / 60;
	minutes %= 60;
	printf("%d Hours %d minutes %d seconds\n", hours, minutes, seconds);
	return 0;
}
