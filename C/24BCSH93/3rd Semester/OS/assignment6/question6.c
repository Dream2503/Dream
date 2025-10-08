/*  Q6. Create a process to display the message as follows.
            Parent starts
            Child starts
            1 2 3 ... 10 // Parent Process
            Parent ends
            1 2 3 ... 10 // Child Process
            Child ends
*/


#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid = fork(), i;

    if (pid > 0) {
        printf("Parent Starts\n");
        sleep(1);

        for (i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("\nParent Ends\n");
        wait(NULL);
    } else if (pid == 0) {
        printf("Child Starts\n");
        sleep(1);

        for (i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("\nChild Ends\n");
    } else {
        printf("Fork Failed\n");
    }
    return 0;
}
