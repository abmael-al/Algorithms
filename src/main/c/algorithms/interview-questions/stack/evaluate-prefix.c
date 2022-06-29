#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERR_EMPTY_STACK -1

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(const int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isEmpty(const Node* stack) {
    return stack == NULL;
}

int top(const Node *stack) {
    if(isEmpty(stack)) {
        return ERR_EMPTY_STACK;
    }

    return stack->value;
}

void push(const int value, Node **stack) {
    Node* node = createNode(value);

    if(isEmpty(*stack)) {
        *stack = node;

        return;
    }

    node->next = *stack;
    
    *stack = node;
}

int pop(Node **stack) {
    if(isEmpty(*stack)) {
        return ERR_EMPTY_STACK;
    }

    Node* poppedNode = *stack;
    int poppedValue = poppedNode->value;

    *stack = (*stack)->next;

    free(poppedNode);

    return poppedValue;
}
