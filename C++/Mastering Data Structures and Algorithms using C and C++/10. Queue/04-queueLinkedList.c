#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct Queue {Node *start, *end;} Queue;

Queue *create() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->start = queue->end = NULL;
    return queue;
}
bool isEmpty(Queue *queue) {return !queue->start;}
void enqueue(Queue *queue, int value) {
    if (isEmpty(queue)) {
        queue->start = queue->end = (Node*)malloc(sizeof(Node));
        queue->start->data = value;
        queue->end->next = NULL;
        return;
    }
    queue->end->next = (Node*)malloc(sizeof(Node));
    queue->end = queue->end->next;
    queue->end->data = value;
    queue->end->next = NULL;
}
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = queue->start;
    queue->start = queue->start->next;
    int value = temp->data;
    free(temp);
    return value;
}
int first(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->start->data;
}
int last(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->end->data;
}

int main() {
    Queue *queue = create();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    return 0;
}