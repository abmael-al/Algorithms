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
