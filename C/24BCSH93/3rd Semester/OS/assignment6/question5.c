/*  Q5. Create a process to display the message as follows.
            Parent starts
            1 2 3 ... 10
            Parent ends
            Child starts
            1 2 3 ... 10
            Child ends
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid = fork(), i;

    if (pid > 0) {
        printf("Parent Starts\n");

        for (i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("\nParent Ends\n");
        wait(NULL);
    } else if (pid == 0) {
        sleep(1);
        printf("Child Starts\n");

        for (i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("\nChild Ends\n");
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}
