//  Q1. Write a program to generate an interrupt signal SIGINT.

#include <signal.h>
#include <stdio.h>

int main() {
    printf("Raising SIGINT\n");
    raise(SIGINT);
    return 0;
}
