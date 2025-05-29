#include <stdio.h>

int main() {
    int days, months, years;
    printf("Enter the total days: ");
    scanf("%d", &days);
    years = days / 365;
    days %= 365;
    months = days / 30;
    days %= 30;
    printf("%d years, %d months, %d days\n", years, months, days);
    return 0;
}
