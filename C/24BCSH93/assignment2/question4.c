#include <stdio.h>

int main() {
	float basic, DA, HRA, OA = 2000;
	printf("Enter the basic amount: ");
	scanf("%f", &basic);
	DA = .42 * basic;
	HRA = .3 * basic;
	printf("Gross Salary: %.2f\n", basic + DA + HRA + OA);
	return 0;
}
