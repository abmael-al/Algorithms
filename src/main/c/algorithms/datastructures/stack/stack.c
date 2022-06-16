#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_LIST -1

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
    if(isEmpty(stack)) {
        return ERR_EMPTY_LIST;
    }

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

int pop(Node **stack) {
    if(isEmpty(*stack)) {
        return ERR_EMPTY_LIST;
    }

    Node *poppedItem = *stack;
    int poppedValue = poppedItem->value;

    if(isEmpty((*stack)->next)) {
        *stack = NULL;
    }
    else if(!isEmpty((*stack)->next)) {
        *stack = (*stack)->next;
    }

    free(poppedItem);

    return poppedValue;
}
