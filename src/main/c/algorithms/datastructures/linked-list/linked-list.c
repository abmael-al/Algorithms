#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Create an initialized node.
Node * createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isDiff(int n1, int n2) {
    return (n1 != n2) ? TRUE : FALSE;
}

int isEmpty(Node * node) {
    return (node == NULL) ? TRUE : FALSE;
}