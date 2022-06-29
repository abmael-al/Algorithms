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

int isOperator(char chr) {
    return (chr == '*')
        || (chr == '/')
        || (chr == '+')
        || (chr == '-');
}

int handleOperation(const char operator, Node **stack) {
    int result;

    const int operand1 = pop(stack);
    const int operand2 = pop(stack);

    switch(operator) {
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

int evaluatePrefixExpression(const char expr[]) {
    const size_t exprLen = strlen(expr);
    Node *stack = NULL;

    int i;
    for(i = exprLen - 1; i >= 0; i--) {
        const char token = expr[i];

        if(isdigit(token)) {
            int tokenToInteger = token - '0';
            
            push(tokenToInteger, &stack);
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
    const char prefixExpr[] = { "-+*23*549" };
    
    int result = evaluatePrefixExpression(prefixExpr);

    printf("\nResult: %d", result); // Result: -17

    return 0;
}