//  Q5. Write a program to interact between parent process and child process using open signals.

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int child_pid, parent_pid;

void parent_handler(int signal) {
    printf("Parent: Received signal %d from child\n", signal);
    printf("Parent: Communication complete.\n");
    exit(0);
}

void child_handler(int signal) {
    printf("Child: Received signal %d from parent\n", signal);
    printf("Child: Sending signal back to parent...\n");
    kill(parent_pid, SIGUSR1);
    exit(0);
}

int main() {
    parent_pid = getpid();
    child_pid = fork();

    if (child_pid > 0) {
        signal(SIGUSR1, parent_handler);
        sleep(1);

        printf("Parent: Sending SIGUSR2 to child...\n");
        kill(child_pid, SIGUSR2);

        while (1) {
            pause();
        }
    } else if (child_pid == 0) {
        signal(SIGUSR2, child_handler);
        printf("Child: Waiting for signal from parent...\n");

        while (1) {
            pause();
        }
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}
