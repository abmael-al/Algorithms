#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_STACK -1

typedef struct Node {
    char chr;
    struct Node* next;
} Node;

Node* createNode(char chr) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->chr = chr;
    node->next = NULL;

    return node;
}

int isEmpty(Node* stack) {
    return stack == NULL;
}

char top(Node *stack) {
    if(isEmpty(stack)) {
        return ERR_EMPTY_STACK;
    }

    return stack->chr;
}

void push(char chr, Node **stack) {
    Node* node = createNode(chr);

    if(isEmpty(*stack)) {
        *stack = node;

        return;
    }

    node->next = *stack;
    
    *stack = node;
}

char pop(Node **stack) {
    if(isEmpty(*stack)) {
        return ERR_EMPTY_STACK;
    }

    Node* poppedNode = *stack;
    int poppedChar = poppedNode->chr;

    if(isEmpty((*stack)->next)) {
        *stack = NULL;
    }
    else if(!isEmpty((*stack)->next)) {
        *stack = (*stack)->next;
    }

    free(poppedNode);

    return poppedChar;
}

void populateStackWithString(Node **stack, char str[]) {
    for(int i = 0; str[i]; i++) {
        push(str[i], stack);
    }
}

void reconstructString(char str[], Node **stack) {
    for(int i = 0; str[i]; i++) {
        str[i] = top(stack);
        pop(stack);
    }
}

char* reverseString(char string[]) {
    Node *stack = NULL;

    populateStackWithString(&stack, string);

    reconstructString(string, &stack);

    return string;
}

int main() {
    char string[] = { "Banana" }; 
    
    reverseString(string);
    
    printf("%s\n", string);

    return 0;
}