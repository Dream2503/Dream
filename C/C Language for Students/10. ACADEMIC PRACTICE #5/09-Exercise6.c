#include <stdio.h>

float lowerThanDigit(int num, int digit)
{
    int cnt = 0 , sum = 0;
    
    if (num < 0)
        num = num * -1;
    
    while (num != 0)
    {
        if (num % 10 < digit)
        {
            cnt++;
            sum += num % 10;
        }
        num /= 10;
    }
    printf("Total amount if digit is %d\n", cnt);
    return (float)sum / cnt;
}

int main()
{
    int num, digit;
    float avg;
    printf("Enter a number and the digit: ");
    scanf("%d %d", &num, &digit);
    avg = lowerThanDigit(num, digit);
    printf("Average = %.2f", avg);
    return 0;
}