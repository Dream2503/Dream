#include <stdio.h>
#include <math.h>

int main() {
	int x1, x2, y1, y2;
	printf("Enter x1, x2, y1, y2: ");
	scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
	float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
	printf("Distance between the points: %.2f\n", distance);
	return 0;
}
