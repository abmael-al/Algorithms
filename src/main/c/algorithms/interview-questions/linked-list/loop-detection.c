#include <stdio.h>
#include <stdlib.h>

// Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop.

// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points 
// to an earlier node, so as to make a loop in the linked list.

// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same C as earlier]
// Output: C 

// Source [BOOK]: Cracking the Coding Interview. Chapter 2, page 95.

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

Node * loopDetection(Node* head) {
    if(isEmpty(head)) {
        return NULL;
    }

    Node *nodeAtBeginningOfTheLoop = NULL;

    Node *slow = head;

    Node *fast = head;

    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            nodeAtBeginningOfTheLoop = slow;

            break;
        }
    }

    return nodeAtBeginningOfTheLoop;
}   
