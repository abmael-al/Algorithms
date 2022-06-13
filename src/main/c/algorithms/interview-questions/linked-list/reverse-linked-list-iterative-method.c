#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Given the head of a singly linked list, reverse the list.

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int isEmpty(Node * node) {
    return (node == NULL) ? TRUE : FALSE;
}

void reverse(Node **head) {
    if(isEmpty(*head)) {
        return;
    }

    Node* previous = NULL;
    Node* next = NULL;
    Node* current = *head;

    while(current) {
        next = current->next;

        current->next = previous;

        previous = current;
        
        current = next;
    }

    *head = previous;
}
