//  Q1. Write a program to create a child process, and output the PID of the child process and PID of the parent process.

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent Process, PID=%d\n", getppid());
    } else if (pid == 0) {
        printf("Child Process, PID=%d\n", getpid());
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}
