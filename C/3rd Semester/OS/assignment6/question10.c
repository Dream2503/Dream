/*  Q10. Write a program that accepts an integer n from the user and creates only that many child processes. Each child process prints its own PID and
         then exits. The parent waits for all children before terminating.
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int pid = fork();

        if (pid > 0) {
            wait(NULL);
        } else if (pid == 0) {
            printf("Child%d's pid: %d\n", i, getpid());
            _exit(0);
        } else {
            printf("Fork Failed for Child%d\n", i);
        }
    }
}
