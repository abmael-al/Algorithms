#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isEmpty(Node *stack) {
    return stack == NULL;
}

int top(Node *stack) {
    return stack->value;
}

void push(int value, Node **stack) {
    Node* node = createNode(value);
    
    if(isEmpty(*stack)) {
        *stack = node;

        return;
    }

    node->next = *stack;

    *stack = node;
}
