/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to perform the following operations on a binary tree by using linked implementation
	(i) Create a binary tree with n nodes recursively
	(ii) Traverse the tree in pre-order recursively and display the contents
	(ii) Traverse the tree in in-order recursively and display the contents
	(ii) Traverse the tree in post-order recursively and display the contents
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
} Node;

Node *root = NULL;

Node *create();
void pre_order();
void in_order();
void post_order();

int main() {
	root = create();
	printf("\nThe pre-order traversal: ");
	pre_order(root);
	printf("\nThe in-order traversal: ");
	in_order(root);
	printf("\nThe post-order traversal: ");
	post_order(root);
	return 0;
}

Node *create() {
	Node *new = (Node*)malloc(sizeof(Node));

	if (!new) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("Enter the value: ");
	scanf("%d", &new->data);
	
	if (new->data == -1) {
		return NULL;
	}
	printf("Enter the left child of %d element\n", new->data);
	new->left = create();
	printf("Enter the right child of %d element\n", new->data);
	new->right = create();
	printf("\n");
	return new;
}

void pre_order(Node *root) {
	if (root) {
		printf("%d ", root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(Node *root) {
    if (root) {
		in_order(root->left);
		printf("%d ", root->data);
		in_order(root->right);
	}
}

void post_order(Node *root) {
    if (root) {
		post_order(root->left);
		post_order(root->right);
		printf("%d ", root->data);
	}
}