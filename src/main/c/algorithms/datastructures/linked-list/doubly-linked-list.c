#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_LIST -1
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node * createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

int isDiff(int n1, int n2) {
    return (n1 != n2) ? TRUE : FALSE;
}

int isEmpty(Node *node) {
    return (node == NULL) ? TRUE : FALSE;
}

int isNotEmpty(Node *node) {
    return (node != NULL) ? TRUE : FALSE;
}

// Returns number of data elements in list.
// Time complexity: O(n)
int size(Node *head) {
    Node *iterator = head;
    int size = 0;

    if(isEmpty(head)) {
        return size;
    }

    while(isNotEmpty(iterator)) {
        ++size;
        iterator = iterator->next;
    }

    return size;
}

// Returns front node.
// Time complexity: O(1)
Node * front(Node *head) {
    if(isEmpty(head)) {
        return NULL;
    }

    return head;
}

// Returns back node.
// Time complexity: O(n)
Node * back(Node *head) {
    if(isEmpty(head)) {
        return NULL;
    }

    while(isNotEmpty(head->next)) {
        head = head->next;
    }

    return head;
}

// Returns the value of the nth item.
// Time complexity: O(n)
int valueAt(int position, Node *head) {
    if(isEmpty(head)) {
        return ERR_EMPTY_LIST;
    }

    Node *iterator = head;
    int currPos = 1;

    while(isDiff(currPos, position) && isNotEmpty(iterator->next)) {
        ++currPos;
        iterator = iterator->next;
    }

    if(isDiff(currPos, position)) {
        return ERR_EMPTY_LIST;
    }

    return iterator->value;
}