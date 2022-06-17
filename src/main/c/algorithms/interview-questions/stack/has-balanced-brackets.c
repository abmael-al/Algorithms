#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_STACK -1
#define NOT_BALANCED 0
#define BALANCED 1

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

int isCorrespondentCloseBracket(char open, int close) {
    return open == '(' && close == ')' 
        || open == '[' && close == ']'
        || open == '{' && close == '}';
}

int isCloseBracket(char chr) {
    return chr == ')' 
        || chr == ']' 
        || chr == '}';
}

int isOpenBracket(char chr) {
    return chr == '(' 
        || chr == '[' 
        || chr == '{';
}

void freeStack(Node **stack) {
    Node* helper = NULL;

    while(!isEmpty(*stack)) {
        helper = *stack;
        *stack = (*stack)->next;

        free(helper);
    }
}

int handleLoopConclusion(Node **stack) {
    if(isEmpty(*stack)) {
        return BALANCED;
    }
    else if(!isEmpty(*stack)) {
        freeStack(stack);

        return NOT_BALANCED;
    }
}

int handleCloseBracket(char closeBracket, Node **stack) {
    char openBracket = top(*stack);

    if(isEmpty(*stack)) {
        return NOT_BALANCED;
    }
    else if(isCorrespondentCloseBracket(openBracket, closeBracket)) {
        pop(stack);
        return BALANCED;
    }
    else if(!isCorrespondentCloseBracket(openBracket, closeBracket)) {
        return NOT_BALANCED;
    }
}

int hasBalancedBrackets(char expr[]) {
    Node* stack = NULL;

    int i;
    for(i = 0; expr[i]; i++) {
        if(isOpenBracket(expr[i])) {
            push(expr[i], &stack);
        }
        else if(isCloseBracket(expr[i])) {
            int isStillBalanced = handleCloseBracket(expr[i], &stack);

            if(!isStillBalanced) {
                return NOT_BALANCED;
            }
        }
    }

    return handleLoopConclusion(&stack);
}

int main() {
    char balancedExpr[] = { "(2+5)*[4+2]+(2}" };

    printf("\nHas balanced brackets: %d", hasBalancedBrackets(balancedExpr));

    char notBalancedExpr[] = { "(2+1*1" };
    
    printf("\nHas balanced brackets: %d", hasBalancedBrackets(notBalancedExpr));

    return 0;
}