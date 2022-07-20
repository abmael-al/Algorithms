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