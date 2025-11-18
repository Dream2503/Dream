/*  Q8. Write a program where the parent process creates two child processes. The first child prints numbers from 1–5, and after it finishes, the
        second child prints numbers from 6–10. The parent waits for both children. [Sequential execution]
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid1 = fork(), i;

    if (pid1 > 0) {
        waitpid(pid1, NULL, 0);
        int pid2 = fork();

        if (pid2 > 0) {
            waitpid(pid2, NULL, 0);
        } else if (pid2 == 0) {
            for (i = 6; i <= 10; i++) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            printf("Fork Failed for Second Child\n");
        }
    } else if (pid1 == 0) {
        for (i = 1; i <= 5; i++) {
            printf("%d ", i);
        }
    } else {
        printf("Fork Failed for First Child\n");
    }
    return 0;
}
