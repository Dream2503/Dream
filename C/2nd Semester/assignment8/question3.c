/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to create a single linked list and reverse it so that the traversal of the list begin from the last
node and end at the first node. That is, last node becomes the first node and first node becomes the last node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *start = NULL;

void create_list(Node *);
void reverse(Node *);
void traverse(Node *);

int main() {
    Node *node = (Node *) malloc(sizeof(Node));
    start = node;

    if (!node) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    create_list(node);
    reverse(node);
    node = start;
    traverse(node);
    return 0;
}

void create_list(Node *node) {
    int ch;

    do {
        printf("Enter an element to append to the list: ");
        scanf("%d", &node->data);
        printf("Enter '1' to continue appending or '0' to stop: ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                node->next = NULL;
                break;

            case 1:
                node->next = (Node *) malloc(sizeof(Node));
                node = node->next;

                if (!node) {
                    printf("Memory was not allocated\n");
                    exit(0);
                }
                break;

            default:
                printf("Invalid input\n");
                exit(0);
        }
    } while (ch != 0);
}

void reverse(Node *node) {
    if (!node || !node->next) {
        return;
    }
    Node *end = NULL, *prev = node;
    node = node->next;

    while (node) {
        prev->next = end;
        end = prev;
        prev = node;
        node = node->next;
    }
    prev->next = end;
    start = prev;
}

void traverse(Node *node) {
    if (!node) {
        printf("\nThe Linked List is empty\n");
    } else {
        int len = 0;
        printf("\nThe elements in the Linked List are: ");

        while (node) {
            printf("%d ", node->data);
            node = node->next;
            len++;
        }
        printf("\nTotal length of the Linked List is %d\n", len);
    }
}
