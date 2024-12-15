#include <stdio.h>

int main()
{
    float dist, spd, time;
    printf("Enter Distance: ");
    scanf("%f", &dist);
    printf("Enter Speed: ");
    scanf("%f", &spd);
    
    time = dist / spd;
    printf("Time taken is %.2f", time);
    return 0;
}