/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program to perform the following operations on Binary Search Tree (BST).
	(i) Create a BST by inserting nodes into the BST
	(ii) Traverse the BST in in-order
	(iii) Traverse the BST in pre-order
	(iv) Traverse the BST in post-order
	(v) Search for a node in BST
	(vi) Find the node with the minimum value in the BST
	(vii) Find the node with the maximum value in the BST
	(viii) Delete a node with a particular value from the BST
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
} Node;

Node *root = NULL;

Node *insert(Node*, int);
Node *search(Node*, int);
Node *min(Node*);
Node *max(Node*);
Node *delete(Node*, int);
void in_order(Node*);
void pre_order(Node*);
void post_order(Node*);

int main() {
	Node *node;
	int ch, element;

	// printf("Enter the list of element to create BST (-1 to end the list): ");
	// while (1) {
	// 	scanf("%d", &element);

	// 	if (element != -1) {
	// 		root = insert(root, element);
	// 	} else {
	// 		break;
	// 	}
	// }
	// printf("The in-order Traversal: ");
	// in_order(root);

	while (1) {
		printf("\n\n\tMenu-Driven program for BST\n");
		printf("1. Insert a data into the BST\n");
		printf("2. Traverse in pre-order\n");
		printf("3. Traverse in in-order\n");
		printf("4. Traverse in post-order\n");
		printf("5. Search for a node\n");
		printf("6. Find the minimum node\n");
		printf("7. Find the maximum node\n");
		printf("8. Delete a particular node\n");
		printf("0. Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch (ch) {
			case 1:
				printf("\nEnter an element to insert into the BST: ");
				scanf("%d", &element);
				root = insert(root, element);
				printf("The in-order Traversal: ");
				in_order(root);
				break;
			
			case 2:
				if (root) {
					printf("The pre-order traversal: ");
					pre_order(root);
				} else {
					printf("Tree is empty\n");
				}
				break;

			case 3:
				if (root) {
					printf("The in-order traversal: ");
					in_order(root);
				} else {
					printf("Tree is empty\n");
				}
				break;

			case 4:
				if (root) {
					printf("The post-order traversal: ");
					post_order(root);
				} else {
					printf("Tree is empty\n");
				}
				break;

			case 5:
				printf("\nEnter the key to search: ");
				scanf("%d", &element);
				node = search(root, element);

				if (node) {
					printf("Key found\n");
				} else {
					printf("Key not found\n");
				}
				break;

			case 6:
				node = min(root);

				if (node) {
					printf("\nThe minimum value is: %d", node->data);
				} else {
					printf("The tree is empty\n");
				}
				break;

			case 7:
				node = max(root);

				if (node) {
					printf("\nThe maximum value is: %d", node->data);
				} else {
					printf("The tree is empty\n");
				}
				break;

			case 8:
				printf("\nEnter the value to delete from the BST: ");
				scanf("%d", &element);
				root = delete(root, element);
				
				if (root) {
					printf("The in-order traversal: ");
					in_order(root);
				} else {
					printf("Tree is empty\n");
				}
				break;

			case 0:
				printf("\nThank you for using the program\n");
				return 0;

			default:
				printf("Invalid input, Try again...\n");
		}
	}
}

Node *insert(Node *root, int value) {
	if (!root) {
		root = (Node*)malloc(sizeof(Node));

		if (!root) {
			printf("Memory was not allocated\n");
			exit(0);
		}
		root->data = value;
		root->left = root->right = NULL;
	} else if (value < root->data) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}
	return root;
}

Node *search(Node *root, int key) {
	if (root && key < root->data) {
		root =  search(root->left, key);
	} else if (root && key > root->data) {
		root = search(root->right, key);
	}
	return root;
}

Node *min(Node* root) {
	if (root && root->left) {
		return min(root->left);
	}
	return root;
}

Node *max(Node* root) {
	if (root && root->right) {
		return max(root->right);
	}
	return root;
}

Node *delete(Node *root, int key) {
	if (!root) {
		printf("Key not found\n");
	} else if (key < root->data) {
		root->left = delete(root->left, key);
	} else if (key > root->data) {
		root->right = delete(root->right, key);
	} else {
		Node *temp;

		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		} else if (root->left == NULL || root->right == NULL) {
			temp = root;

			if (root->left) {
				root = root->left;
			} else {
				root = root->right;
			}
			free(temp);
		} else {
			temp = min(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	return root;
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