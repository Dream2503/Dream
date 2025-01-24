#include <stdio.h>

int main() {
	float unit1, unit2, units, total;
	printf("Enter the previous month and current month reading: ");
	scanf("%f%f", &unit1, &unit2);
	units = unit2 - unit1;
	
	if (units <= 100) {
		total += 3.2 * units;
		units = 0;
	} else {
		units -= 100;
		total += 320;
	}
	if (units <= 200) {
		total += 5.4 * units;
		units = 0;
	} else {
		units -= 200;
		total += 1080;
	}
	total += 6 * units;
	printf("Total price is %f\n", total);
	return 0;
}