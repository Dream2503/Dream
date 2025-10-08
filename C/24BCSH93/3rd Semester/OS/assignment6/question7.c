/*  Q7. Write a program to create two child processes. The first child prints all odd numbers from 1 to 20, and the second child prints all even
        numbers from 1 to 20. The parent  waits for both children.
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid1 = fork(), i;

    if (pid1 > 0) {
        wait(NULL);
        int pid2 = fork();

        if (pid2 > 0) {
            wait(NULL);
        } else if (pid2 == 0) {
            printf("All the even numbers are: ");

            for (i = 2; i <= 20; i += 2) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            printf("Fork Failed for Second Child\n");
        }
    } else if (pid1 == 0) {
        printf("All the odd numbers are: ");

        for (i = 1; i < 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("Fork Failed for First Child\n");
    }
    return 0;
}
