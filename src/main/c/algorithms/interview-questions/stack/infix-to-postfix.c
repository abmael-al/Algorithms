#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int isOperator(char chr) {
    return (chr == '*')
        || (chr == '/')
        || (chr == '+')
        || (chr == '-');
}

int hasHigherPrecedence(char operatorComparedAgainst, char operator) {
    return (operator == '/' && operatorComparedAgainst != '*')
        || (operatorComparedAgainst < operator);
}

int isOpenBracket(char chr) {
    return chr == '(' 
        || chr == '[' 
        || chr == '{';
}

