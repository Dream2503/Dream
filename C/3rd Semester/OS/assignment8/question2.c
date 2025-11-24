//  Q2. Write a program to display the signal number of SIGINT and SIGQUIT signal.

#include <signal.h>
#include <stdio.h>

int main() {
    printf("Signal No. of SIGINT: %d\n", SIGINT);
    printf("Signal No. of SIGQUIT: %d", SIGQUIT);
    return 0;
}
