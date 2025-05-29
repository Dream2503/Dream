/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Queue by using Linked List, It should have the following operations(functions):
    (i) void insert(int) to insert an element into the Queue.
    (ii) int delete() to remove an element from the Queue.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void insert(int);
int delete();
void traverse();

int main() {
    int ch, element;

    while (1) {
        printf("\n\t\tMenu-Driven program for Queue\n");
        printf("1. Insert an element to the Queue\n");
        printf("2. Delete an element from the Queue\n");
        printf("3. Display Queue\n");
        printf("4. To exit the program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                traverse();
                break;

            case 2:
                element = delete ();

                if (element != -1) {
                    printf("Deleted element %d from the Queue\n", element);
                    traverse();
                }
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Thank you for using the program\n");
                return 0;

            default:
                printf("Invalid choice. Try again\n");
        }
    }
}

void insert(int element) {
    if (!rear) {
        rear = (Node *) malloc(sizeof(Node));
        front = rear;
    } else {
        rear->next = (Node *) malloc(sizeof(Node));
        rear = rear->next;
    }
    if (!rear) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    rear->data = element;
    rear->next = NULL;
}

int delete() {
    if (!front) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = front;
    int res = front->data;
    front = front->next;

    if (!front) {
        rear = NULL;
    }
    free(temp);
    return res;
}

void traverse() {
    if (!front) {
        printf("The Queue is empty\n");
    } else {
        Node *node = front;
        printf("The elements in the Queue are: ");

        while (node) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}
