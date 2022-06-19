#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int hasHigherPrecedence(char operator, char operatorComparedAgainst) {
    return (operator == '/' && operatorComparedAgainst != '*')
        || (operatorComparedAgainst < operator);
}

void infixToPostfix(char expr[]) {
    Node* stack = NULL;
    int currentModifiedIndex = -1;

    int i;
    for(i = 0; expr[i]; i++) {
        const char token = expr[i];

        if(isalnum(token)) {
            expr[++currentModifiedIndex] = token;
        }

        else if(isOperator(token)) {
            while(!isEmpty(stack) && !hasHigherPrecedence(top(stack), token)) {
                expr[++currentModifiedIndex] = top(stack);

                pop(&stack);
            }

            push(token, &stack);
        }
    }

    while(!isEmpty(stack)) {
        expr[++currentModifiedIndex] = top(stack);

        pop(&stack);
    }
}

int main() {
    char expr[] = { "A+B*C" };

    infixToPostfix(expr);

    printf("%s", expr);

    return 0;
}
