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

int dequeue(Queue *queue) {
    if(isEmpty(*queue)) {
        return ERR_EMPTY_QUEUE;
    }
    
    const int dequeuedElement = queue->queue[queue->head];

    int isItTheLastElementInTheQueue = queue->head == queue->tail;
    
    if(isItTheLastElementInTheQueue) {
        queue->head = -1;
        queue->tail = -1;
    }
    else {
        queue->head = (queue->head + 1) % MAX_SIZE;
    }

    return dequeuedElement;
}

void print(const Queue queue) {
    int tail = queue.tail;
    int head = queue.head;

    while(head != tail) {
        printf("%.f ", queue.queue[head]);

        head = (head + 1) % MAX_SIZE;
    }
}

int main() {
    Queue queue;

    initQueue(&queue);

    enqueue(1, &queue);
    enqueue(2, &queue);
    enqueue(3, &queue);
    enqueue(4, &queue);
    enqueue(5, &queue);
    enqueue(6, &queue);
    enqueue(7, &queue);
    enqueue(8, &queue);
    enqueue(9, &queue);
    enqueue(10, &queue);

    print(queue);

   return 0; 
}