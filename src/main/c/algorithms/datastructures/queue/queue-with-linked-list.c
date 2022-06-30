#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_QUEUE -1;

typedef struct Node {
    double value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

Node * createNode(const double value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isEmpty(Queue queue) {
    return queue.head == NULL;
}

void initQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(const double value, Queue *queue) {
    Node *node = createNode(value);

    if(isEmpty(*queue)) {
        queue->head = node;
        queue->tail = node;

        return;
    }

    Node *nowSecondToLast = queue->tail; 

    nowSecondToLast->next = node;

    queue->tail = node;
}

double dequeue(Queue *queue) {
    if(isEmpty(*queue)) {
        return ERR_EMPTY_QUEUE;
    }

    Node *dequeued = queue->head;
    Node *next = dequeued->next;
    const double dequeuedValue = dequeued->value; 

    int isItTheOnlyNodeInTheQueue = queue->tail == queue->head;
    if(isItTheOnlyNodeInTheQueue) {
        // In this case, next is going to be equal to NULL
        queue->tail = next;
    }

    queue->head = next;

    free(dequeued);

    return dequeuedValue;
}

void print(Queue queue) {
    printf("\n");

    Node *iterator = queue.head;
    
    while(iterator) {
        printf("%.f ", iterator->value);
        
        iterator = iterator->next;
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

    dequeue(&queue);

    print(queue);

    return 0;
}