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
