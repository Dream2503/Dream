#include <stdio.h>

int main()
{
    int secs, hrs, rem_secs, mins;
    printf("Enter the total seconds: ");
    scanf("%d", &secs);
    hrs = secs / 3600;
    rem_secs = secs % 3600;
    mins = rem_secs / 60;
    secs = rem_secs % 60;

    if (hrs < 10)
        printf("0%d", hrs);
    
    printf("%d", hrs);
    
    if (mins < 10)
        printf(":0%d:", mins);
    
    printf(":%d:", mins);
    
    if (secs < 10)
        printf("0%d", secs);
    
    printf("%d", secs);
    return 0;
}