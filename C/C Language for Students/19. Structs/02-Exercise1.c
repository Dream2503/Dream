#include <stdio.h>

typedef struct point{int x, y;} Point;

void printPoint(Point point) {printf("Point(%d, %d)", point.x, point.y);}

Point inputPoint()
{
    Point point;
    printf("Enter the x-coord: ");
    scanf("%d", &point.x);
    printf("Enter the y-coord: ");
    scanf("%d", &point.y);
    return point;
}

int main()
{       
    Point p = inputPoint();
    printPoint(p);
    return 0;
}