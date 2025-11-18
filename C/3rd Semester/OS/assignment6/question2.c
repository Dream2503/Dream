/*  Q2. Write a program that will create a child process. The parent has to perform the operation of checking whether the accepted number is even or
        odd, and the child has to check whether the number is prime or not.
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int is_prime(int);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int pid = fork();

    if (pid > 0) {
        if (num % 2 == 0) {
            printf("%d is an even number\n", num);
        } else {
            printf("%d is an odd number\n", num);
        }
        wait(NULL);
    } else if (pid == 0) {
        if (is_prime(num)) {
            printf("%d is a prime number\n", num);
        } else {
            printf("%d is not a prime number\n", num);
        }
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}

int is_prime(int num) {
    int i;

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
