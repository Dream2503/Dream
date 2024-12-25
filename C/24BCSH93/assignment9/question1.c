#include <stdio.h>

float areaOfCircle(float);

int main() {
	float radius;
	printf("Enter the radius: ");
	scanf("%f", &radius);
	printf("Area of the circle is %f\n", areaOfCircle(radius));
	return 0;
}

float areaOfCircle(float r) {
	float pi = 3.14159;
	return pi * r * r;
}
