#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree {    
    struct Tree *lchild, *rchild;
    int data;
} Tree;
typedef struct ListNode {
    Tree *data;
    struct ListNode *next;
} ListNode;
typedef struct Queue {ListNode *start, *end;} Queue;
typedef struct Stack {ListNode *top;} Stack;

Queue *queueCreate() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->start = queue->end = NULL;
    return queue;
}
bool queueEmpty(Queue *queue) {return !queue->start;}
void enqueue(Queue *queue, Tree *value) {
    if (queueEmpty(queue)) {
        queue->start = queue->end = (ListNode*)malloc(sizeof(ListNode));
        queue->start->data = value;
        queue->end->next = NULL;
        return;
    }
    queue->end->next = (ListNode*)malloc(sizeof(ListNode));
    queue->end = queue->end->next;
    queue->end->data = value;
    queue->end->next = NULL;
}
Tree *dequeue(Queue *queue) {
    if (queueEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    ListNode *temp = queue->start;
    queue->start = queue->start->next;
    Tree *value = temp->data;
    free(temp);
    return value;
}

Tree *treeCreate() {
    Queue *queue = queueCreate();
    Tree *tree = (Tree*)malloc(sizeof(Tree));

    printf("Enter the root value: ");
    scanf("%d", &tree->data);
    
    tree->lchild = tree->rchild = NULL;
    enqueue(queue, tree);

    int value;
    Tree *prev, *current;

    while (!queueEmpty(queue)) {
        prev = dequeue(queue);
        printf("Enter the left child value of node %d: ", prev->data);
        scanf("%d", &value);

        if (value != -1) {
            current = (Tree*)malloc(sizeof(Tree));
            current->data = value;
            current->lchild = current->rchild = NULL;
            prev->lchild = current;
            enqueue(queue, current);
        }
        printf("Enter the right child value of node %d: ", prev->data);
        scanf("%d", &value);

        if (value != -1) {
            current = (Tree*)malloc(sizeof(Tree));
            current->data = value;
            current->lchild = current->rchild = NULL;
            prev->rchild = current;
            enqueue(queue, current);
        }
    }
    return tree;
}

Stack *stackCreate() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
}
void push(Stack *stack, Tree *value) {
    ListNode *new = (ListNode*)malloc(sizeof(ListNode));
    new->data = value;
    new->next = stack->top;
    stack->top = new;
}
bool stackEmpty(Stack *stack) {return stack->top == NULL;}
void display(Stack *stack) {
    if (stackEmpty(stack)) printf("Stack is empty\n");
    else {
        ListNode *current = stack->top;

        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}
Tree *pop(Stack *stack) {
    if (stackEmpty(stack)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    ListNode *temp = stack->top;
    Tree *value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

void preOrderRecur(Tree *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderRecur(root->lchild);
        preOrderRecur(root->rchild);
    }
}
void inOrderRecur(Tree *root) {
    if (root) {
        inOrderRecur(root->lchild);
        printf("%d ", root->data);
        inOrderRecur(root->rchild);
    }
}
void postOrderRecur(Tree *root) {
    if (root) {
        postOrderRecur(root->lchild);
        postOrderRecur(root->rchild);
        printf("%d ", root->data);
    }
}
void preOrderIter(Tree *root) {
    Stack *stk = stackCreate();

    do {
        if (root) {
            printf("%d ", root->data);
            push(stk, root);
            root = root->lchild; 
        } else {
            root = pop(stk);
            root = root->rchild;
        }
    } while (root || !stackEmpty(stk));
}
void inOrderIter(Tree *root) {
    Stack *stk = stackCreate();

    do {
        if (root) {
            push(stk, root);
            root = root->lchild; 
        } else {
            root = pop(stk);
            printf("%d ", root->data);
            root = root->rchild;
        }
    } while (root || !stackEmpty(stk));
}
void postOrderIter(Tree *root) {
    Stack *stk = stackCreate();

    do {
        if (root) {
            push(stk, root);
            root = root->lchild; 
        } else {
            root = pop(stk);
            if (root > 0) {
                push(stk, -(long)root);
                root = root->rchild;
            } else {
                printf("%d ", root->data);
                root = NULL;
            }
        }
    } while (root || !stackEmpty(stk));
}
void levelOrder(Tree *root) {
    Queue *queue = queueCreate();
    printf("%d ", root->data);
    enqueue(queue, root);

    while (!queueEmpty(queue)) {
        root = dequeue(queue);

        if (root->lchild) {
            printf("%d ", root->lchild->data);
            enqueue(queue, root->lchild);
        } if (root->rchild) {
            printf("%d ", root->rchild->data);
            enqueue(queue, root->rchild);
        }
    }
}
int count(Tree *root) {
    if (root) return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}
int sum(Tree *root) {
    if (root) return count(root->lchild) + count(root->rchild) + root->data;
    return 0;
}
int main() {
    Tree *tree = treeCreate();
    levelOrder(tree);
    return 0;
}