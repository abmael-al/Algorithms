#include <stdio.h>
#include <stdlib.h>

#define PALINDROME 1
#define NOT_PALINDROME 0

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

int isEmpty(Node* node) {
    return node == NULL;
}

void push(int value, Node **head) {
    Node* node = createNode(value);

    if(isEmpty(*head)) {
        *head = node;

        return;
    }

    node->next = *head;
    
    *head = node;
}

void print(Node* head) {
    printf("\n");

    while(head) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

int validate(Node *node1, Node *node2) {
    return (node1->value == node2->value) ? PALINDROME : NOT_PALINDROME;
}

void isPalindromeUtil(Node *end, Node **begin, int *validator) {
    if(isEmpty(end)) {
        return;
    }

    isPalindromeUtil(end->next, begin, validator);

    if(!(*validator)) {
        return;
    }

    *validator = validate(end, *begin);

    *begin = (*begin)->next;
}   

int isPalindrome(Node *head) {
    if(isEmpty(head)) {
        return NOT_PALINDROME;
    }

    int validation;
    Node* begin = head;
    Node* end = head;

    isPalindromeUtil(end, &begin, &validation);

    return validation;
}

int main() {
    Node *palindrome = NULL;

    push(1, &palindrome);
    push(2, &palindrome);
    push(2, &palindrome);
    push(1, &palindrome);
 
    print(palindrome);

    printf("Is palindrome [PALINDROME LIST]: %d\n", isPalindrome(palindrome));


    Node* notPalindrome = NULL;

    push(1, &notPalindrome);
    push(2, &notPalindrome);
    push(3, &notPalindrome);
    push(4, &notPalindrome);

    print(notPalindrome);

    printf("Is palindrome [NOT PALINDROME LIST]: %d\n", isPalindrome(notPalindrome));

    return 0;
}