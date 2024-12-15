#include <stdio.h>

int main()
{
    int grade, cnt = 0, total = 0;

    while (1)
    {
        printf("Enter grade: ");
        scanf("%d", &grade);

        if (grade != -1)
        {
            total += grade;
            cnt++;
        }
        else
            break;
    }
    printf("Average grade = %d %d %d", total / cnt, total, cnt);
    return 0;    
}