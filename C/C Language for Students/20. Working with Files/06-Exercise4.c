#include <stdio.h>

int main()
{
    FILE* fp;
    int num, square;
    fp = fopen("05-outputFile.txt", "r");

    if (fp != NULL)
    {
        for (int i = 1; i<= 10; i++)
        {
            fscanf(fp, "%d %d\n", &num, &square);
            printf("%d %d\n", num, square);
        }
        fclose(fp);
    }
    return 0;
}
