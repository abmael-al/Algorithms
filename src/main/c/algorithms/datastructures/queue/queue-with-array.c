#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define ERR_EMPTY_QUEUE -1

typedef struct Queue {
    double queue[MAX_SIZE];
    int head;
    int tail;
} Queue;

void initQueue(Queue *queue) {
    queue->head = -1;
    queue->tail = -1;
}

int isFull(const Queue queue) {
    return ((queue.tail + 1) % MAX_SIZE) == queue.head;
}

int isEmpty(const Queue queue) {
    return (queue.head == -1) && (queue.tail == -1);
}

void enqueue(const double value, Queue *queue) {
    if(isFull(*queue)) {
        return;
    }

    if(isEmpty(*queue)) {
        queue->head = 0;
        queue->tail = 0;
    }

    queue->queue[queue->tail] = value;
    queue->tail = (queue->tail + 1) % MAX_SIZE;
}
