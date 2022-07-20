#include <stdio.h>
#include <stdlib.h>

#define PROCEDURE_ALLOWED 1
#define ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED -1
#define ERR_MEMORY_ALLOCATION_NOT_ALLOWED -2

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *tail;
} LinkedList;

// Fully initialize all fields of a linked list.
void InitLinkedList(LinkedList *list) {
    list->tail = NULL;
}

// Create a fully initialized node.
int CreateNode(const int value, Node **dest) {
    Node *node = (Node *)malloc(sizeof(Node));

    if(node == NULL) {
        return ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED;
    }

    node->value = value;
    node->next = NULL;

    *dest = node;

    return PROCEDURE_ALLOWED;
}

// Check if a given pointer to node is empty (pointing to NULL).
int isEmpty(const Node *node) {
    return node == NULL;
}

int insert(const int value, LinkedList *list) {
    Node *node = NULL;
    Node *head = (isEmpty(list->tail)) ? NULL : list->tail->next; 
    
    CreateNode(value, &node);

    if(isEmpty(node)) {
        return ERR_MEMORY_ALLOCATION_NOT_ALLOWED;
    }

    node->next = (isEmpty(head)) ? node : head;

    if(isEmpty(list->tail)) {
        list->tail = node;
    }
    else {
        list->tail->next = node;
    }

    return PROCEDURE_ALLOWED;    
}