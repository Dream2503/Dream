/*  Q4. Create a process to display the message as follows.
            Child starts
            1 2 3 ... 10
            Child ends
            Parent ends
*/

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int pid = fork(), i;

    if (pid > 0) {
        wait(NULL);
        printf("Parent Ends\n");
    } else if (pid == 0) {
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
