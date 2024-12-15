#include <stdio.h>
#define len 6

int main()
{
    int lst[len] = {5, 4, 7, 3, 9, 8}, num;
    printf("Enter the number of element to shift: ");
    scanf("%d", &num);
    int temp[num];

    for (int i = 0; i < num; i++)
        temp[i] = lst[i];

    for (int i = num; i < len; i++)
        lst[i-num] = lst[i];
    
    for (int i = len - 1; i >= num; i--)
        lst[i] = temp[i-num];

    for (int i = 0; i < len; i++)
        printf("Enter element #%d: %d\n", i + 1, lst[i]);

    return 0;
}