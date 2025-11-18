/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program by using the function defined in Q1 to perform repeated operations on the stack and
display the status of the stack after every operation until the user enters his choice to exit.
*/

#include <stdbool.h>
#include <stdio.h>
#define n 3

int stack[n], top = -1;

void push(int);
int pop();
bool is_full();
bool is_empty();
void display();

int main() {
    int ch, element;

    while (1) {
        printf("\n\t\tMenu-Driven program for stack\n");
        printf("1. Push an element to the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display stack\n");
        printf("4. To exit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                element = pop();

                if (element != -1) {
                    printf("Popped element %d from the stack\n", element);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Thank you for using the program\n");
                return 0;

            default:
                printf("Invalid choice. Try again\n");
        }
    }
}

void push(int element) {
    if (is_full()) {
        printf("Stack Overload\n");
    } else {
        stack[++top] = element;
    }
}

int pop() {
    if (is_empty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

bool is_full() { return top == n - 1; }
bool is_empty() { return top == -1; }

void display() {
    int i;

    if (is_empty()) {
        printf("No elements in the stack\n");
    } else {
        printf("Stack elements: ");

        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
