/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to create two single linked lists with values of the nodes in ascending order, Then write a function
to merge both the list into a single list so that all the nodes will be in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void create_list(Node *);
Node *merge(Node *, Node *);
void traverse(Node *);

int main() {
    Node *node1 = (Node *) malloc(sizeof(Node));
    Node *node2 = (Node *) malloc(sizeof(Node));

    if (!node1 || !node2) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    printf("Creating List1:\n");
    create_list(node1);
    printf("Creating List2:\n");
    create_list(node2);

    Node *node = merge(node1, node2);
    printf("Merged List:\n");
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

Node *merge(Node *node1, Node *node2) {
    Node *node = NULL, *res = NULL;

    if (!node1) {
        return node2;
    }
    if (!node2) {
        return node1;
    }
    if (node1->data < node2->data) {
        res = node1;
        node1 = node1->next;
    } else {
        res = node2;
        node2 = node2->next;
    }
    node = res;

    while (node1 && node2) {
        if (node1->data < node2->data) {
            node->next = node1;
            node1 = node1->next;
        } else {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }
    if (node1) {
        node->next = node1;
    } else {
        node->next = node2;
    }
    return res;
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
