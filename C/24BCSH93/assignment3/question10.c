#include <stdio.h>

int main() {
	float basic_salary, gross_salary;
	printf("Enter the basic salary: ");
	scanf("%f", &basic_salary);
	gross_salary = basic_salary;

	if (basic_salary <= 10000) gross_salary += 0.2 * basic_salary + 0.8 * basic_salary;
	else gross_salary += 0.3 * basic_salary + 0.95 * basic_salary;
	printf("The gross salary is %f\n", gross_salary);
	return 0;
}
