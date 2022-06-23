// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in forward order. Write a function that adds the two numbers and 
// returns the sum as a linked list.

// EXAMPLE
// lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
// Output: 9 -> 1 -> 2. That is, 912. 

#include <stdio.h>
#include <stdlib.h>

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

int size(Node *head) {
    int size = 0;
    Node *iterator = head;

    if(isEmpty(head)) {
        return size;
    }

    while(!isEmpty(iterator)) {
        ++size;

        iterator = iterator->next;
    }

    return size;
}

void walk(int steps, Node **node) {
    if(isEmpty(*node)) {
        return;
    }

    int i;
    for(i = 0; i < steps; i++) {
        if(isEmpty(*node)) {
            return;
        }

        *node = (*node)->next;
    }
}

void swap(Node **head1, Node **head2) {
    Node *helper = *head1;

    *head1 = *head2;

    *head2 = helper;
}
