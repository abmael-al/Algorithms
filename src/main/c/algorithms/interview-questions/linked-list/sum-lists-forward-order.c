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

int diff(int n1, int n2) {
    return abs(n1 - n2);
}

void addSameSize(Node *head1, Node *head2, Node **result, int *carry) {
    if(isEmpty(head1)) {
        return;
    }

    int sum;

    addSameSize(head1->next, head2->next, result, carry);
    
    sum = (head1->value + head2->value + *carry);
    *carry = sum / 10;
    sum = sum % 10;

    push(sum, result);
}

void addCarryToRemaining(Node *head, Node *current, Node **result, int *carry) {
    if(isEmpty(head)) {
        return;
    }

    int sum;

    if(head != current) {
        addCarryToRemaining(head->next, current, result, carry);

        sum = (head->value + *carry);
        
        *carry = sum / 10;
        sum = sum % 10;

        push(sum, result);
    }
}

void sum(Node *head1, Node* head2, Node **result) {
    if(isEmpty(head1)) {
        *result = head2;

        return;
    }
    else if(isEmpty(head2)) {
        *result = head1;

        return;
    }

    Node *current = NULL;
    int sizeHead1 = size(head1);
    int sizeHead2 = size(head2);
    int carry = 0;

    if(sizeHead1 == sizeHead2) {
        addSameSize(head1, head2, result, &carry);
    }
    else {
        int szDiff = diff(sizeHead1, sizeHead2);
    
        if(sizeHead1 < sizeHead2) {
            swap(&head1, &head2);
        }

        current = head1;
        walk(szDiff, &current);

        addSameSize(current, head2, result, &carry);

        addCarryToRemaining(head1, current, result, &carry);
    }

    if(carry) {
        push(carry, result);
    }
}
