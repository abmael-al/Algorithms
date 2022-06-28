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

int handleOperation(char operator, Node **stack) {
    int result;
    int operand1 = pop(stack) - '0';
    int operand2 = pop(stack) - '0';
            
    switch (operator) {
        case '*':
            result = operand2 * operand1;
            break;
                
        case '/':
            result = operand2 / operand1;
            break;
                
        case '+':
            result = operand2 + operand1;
            break;
                
        case '-':
            result = operand2 - operand1;
            break;
    }

    return result;
}

int evaluatePostfixExpression(char expr[]) {
    Node *stack = NULL;

    int i;
    for(i = 0; expr[i]; i++) {
        const int token = expr[i]; 

        if(isdigit(token)) {
            push(token, &stack);
        }
        else if(isOperator(token)) {
            int result = handleOperation(token, &stack);
            
            push(result, &stack);
        }     
    }
    
    int result = pop(&stack);
    
    free(stack);

    return result;
}

int main() {
    char postifxExpr[] = { "98+56-*" };

    int result = evaluatePostfixExpression(postifxExpr);

    printf("\nResult: %d", result); // Result: -17 

    return 0;
}