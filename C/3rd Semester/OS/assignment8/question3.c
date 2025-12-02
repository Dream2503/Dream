//  Q3. Write a program to generate a SIGCHLD signal when a child terminates and print the signal number.

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signal) { printf("Signal No. handled: %d\n", signal); }

int main() {
    signal(SIGCHLD, handler);
    int pid = fork();

    if (pid == 0) {
        raise(SIGCHLD);
    } else if (pid < 0) {
        printf("Fork Failed\n");
    }
    return 0;
}
