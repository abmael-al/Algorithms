#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 11
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

    int isItTheLastElementInTheQueue = queue->head == (queue->tail - 1);
    
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

    printf("\nQueue: ");
    while(head != tail) {
        printf("%.f ", queue.queue[head]);

        head = (head + 1) % MAX_SIZE;
    }
    
    printf("\n");
}

int main() {
    Queue sampleQueue;

    initQueue(&sampleQueue);

    enqueue(1, &sampleQueue);
    enqueue(2, &sampleQueue);
    enqueue(3, &sampleQueue);
    enqueue(4, &sampleQueue);
    enqueue(5, &sampleQueue);
    enqueue(6, &sampleQueue);
    enqueue(7, &sampleQueue);
    enqueue(8, &sampleQueue);
    enqueue(9, &sampleQueue);
    enqueue(10, &sampleQueue);

    print(sampleQueue);
    
    printf("\nValue returned from dequeue on the (NOT EMPTY) sample queue: %d", dequeue(&sampleQueue));

    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);
    dequeue(&sampleQueue);

    printf("\nValue returned from dequeue on the (EMPTY) sample queue: %d [ERR_EMPTY_QUEUE]", dequeue(&sampleQueue));

   return 0; 
}