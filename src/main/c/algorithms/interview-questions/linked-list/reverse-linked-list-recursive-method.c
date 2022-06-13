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

void reverseLinkedList(Node **head, Node *current, Node* previous) {
    if(isEmpty(current)) {
        *head = previous; 
        return;
    }

    Node *next = current->next;
    
    current->next = previous;

    previous = current;

    current = next;

    reverseLinkedList(head, current, previous);
}

void reverse(Node **head) {
    if(isEmpty(*head)) {
        return;
    }

    reverseLinkedList(head, *head, NULL);
}
