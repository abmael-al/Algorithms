#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_STACK -1

typedef struct Node {
    double value;
    struct Node *next;
} Node; 

typedef struct Stack {
    Node *top;
} Stack;

typedef struct Queue {
    Stack *enqueue;
    Stack *dequeue;
} Queue;

Node *createNode(const double value) {
    Node* node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

Stack * createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->top = NULL;

    return stack;
}

int isEmpty(const Stack stack) {
    return stack.top == NULL;
}

void push(const double value, Stack *stack) {
    Node *node = createNode(value);

    if(isEmpty(*stack)) {
        stack->top = node;

        return;
    }

    node->next = stack->top;

    stack->top = node;
}

double pop(Stack *stack) {
    if(isEmpty(*stack)) {
        return ERR_EMPTY_STACK;
    }

    Node *poppedNode = stack->top;
    double poppedValue = poppedNode->value;

    stack->top = stack->top->next;

    free(poppedNode);

    return poppedValue;
}

void initQueue(Queue *queue) {
    queue->enqueue = createStack();
    queue->dequeue = createStack();
}

void moveAllElementsTo(Stack *destination, Stack *source) {
    while(source->top) {
        double value = pop(source);

        push(value, destination);
    }
}

void enqueue(const double value, Queue *queue) {
    if(!isEmpty(*queue->dequeue)) {
        moveAllElementsTo(queue->enqueue, queue->dequeue);
    }

    push(value, queue->enqueue);
}

double dequeue(Queue *queue) {
    if(!isEmpty(*queue->enqueue)) {
        moveAllElementsTo(queue->dequeue, queue->enqueue);
    }

    return pop(queue->dequeue);
}
