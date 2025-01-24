#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	printf("Enter the 3 sides of the triangle: ");
	scanf("%d%d%d", &a, &b, &c);
	float s = (a + b + c) / 2.0;
	float area = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("Area of the triangle by Heron's Formula: %.2f\n", area);
	return 0;
}