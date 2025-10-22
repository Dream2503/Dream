/*  Q9. Write a program where the parent creates a child process, and that child creates another (grandchild). Each process prints its own PID and its
        parent’s PID.
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent's pid: %d\n", getpid());
        wait(NULL);
    } else if (pid == 0) {
        int cpid = fork();

        if (cpid > 0) {
            printf("Child's pid: %d\n", getpid());
            wait(NULL);
        } else if (cpid == 0) {
            printf("Grand-Child's pid: %d\n", getpid());
        } else {
            printf("Fork Failed for Grand Child\n");
        }
    } else {
        printf("Fork Failed for First Child\n");
    }
}
