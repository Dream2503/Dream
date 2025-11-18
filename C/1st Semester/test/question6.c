#include <stdio.h>

typedef struct distance {
    int km, m;
} distance;

distance addDistance(distance, distance);

int main() {
    distance d1, d2, res;
    printf("Enter the km and m value of distance1: ");
    scanf("%d%d", &d1.km, &d1.m);
    printf("Enter the km and m value of distance2: ");
    scanf("%d%d", &d2.km, &d2.m);
    res = addDistance(d1, d2);
    printf("Addition of two distance is %d kilometers and %d meters\n", res.km, res.m);
    return 0;
}

distance addDistance(distance d1, distance d2) {
    distance res = {d1.km + d2.km, d1.m + d2.m};

    if (res.m > 1000) {
        res.km += res.m / 1000;
        res.m %= 1000;
    }
    return res;
}
