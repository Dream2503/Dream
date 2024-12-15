#include <stdio.h>

void sort(int array[], int len)
{
    for(int i = 0; i < len - 1 ; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void print_array(int array[], int len)
{
    printf("{");
    for(int i = 0; i < len; i++)
    {
        printf("%d", array[i]);

        if(i < len -1)
        {
            printf(", ");
        }
    }
    printf("}");
}

int main()
{
    int lst[] = {8, 7, 6, 3, 2, 9, 5, 4, 0, 1};
    int len = sizeof(lst) / sizeof(lst[0]);
    sort(lst, len);
    print_array(lst, len);

    return 0;
}