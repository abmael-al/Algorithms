#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node *next;
} Node; 

typedef struct Stack {
    Node *top;
} Stack;

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
