//  Q4. Write a program to generate a SIGALRM signal.

#include <signal.h>
#include <stdio.h>

int main() {
    printf("Raising SIGALRM\n");
    raise(SIGALRM);
    return 0;
}
