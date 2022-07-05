#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_LIST -1

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

int main(){
    Node *stack = NULL;

    push(1, &stack);
    push(2, &stack);
    push(3, &stack);
    push(4, &stack);
    push(5, &stack);

    printf("\nTop of the stack: %d", top(stack)); // Top of the stack: 5

    pop(&stack);
    pop(&stack);
    pop(&stack);

    printf("\nTop of the stack: %d", top(stack)); // Top of the stack: 2

    return 0;
}