#include <math.h>
#include <stdio.h>

struct point {
    int x, y;
};

int main() {
    struct point p1, p2;
    float distance;
    printf("Enter the coordinate of point1: ");
    scanf("%d%d", &p1.x, &p1.y);
    printf("Enter the coordinate of point2: ");
    scanf("%d%d", &p2.x, &p2.y);
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Distance between the points is %f\n", distance);
    return 0;
}
