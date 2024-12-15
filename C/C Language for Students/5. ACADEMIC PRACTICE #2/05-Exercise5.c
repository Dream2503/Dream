#include <stdio.h>

int main()
{
    int seconds, hours, rem_secs, minutes, fin_secs;
    printf("Enter total number of seconds: ");
    scanf("%d", &seconds);
    hours = seconds / 3600;
    rem_secs = seconds % 3600;
    minutes = rem_secs / 60;
    fin_secs = rem_secs % 60;
    printf("%d:%d:%d", hours, minutes, fin_secs);
    return 0;
}