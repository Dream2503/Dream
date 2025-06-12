#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int size, start, end, *array;
} Queue;

Queue *create(int size) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->size = size + 1;
    queue->start = queue->end = 0;
    queue->array = (int *) malloc(queue->size * sizeof(int));
    return queue;
}

bool isFull(Queue *queue) {
    return (queue->end + 1) % queue->size == queue->start;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        queue->end = (queue->end + 1) % queue->size;
        queue->array[queue->end] = value;
    }
}

bool isEmpty(Queue *queue) {
    return queue->start == queue->end;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    queue->start = (queue->start + 1) % queue->size;
    return queue->array[queue->start];
}

int first(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->start];
}

int last(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->end];
}

int main() {
    Queue *queue = create(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    return 0;
}
