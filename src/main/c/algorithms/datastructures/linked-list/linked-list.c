#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROCEDURE_ALLOWED 1
#define ERR_EMPTY_LIST 0
#define ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED -1
#define ERR_MEMORY_ALLOCATION_NOT_ALLOWED -2
#define ERR_INDEX_OUT_OF_RANGE -3

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
bool isEmpty(const Node *node) {
    return node == NULL;
}

void print(LinkedList list) {
    if(isEmpty(list.tail)) {
        return;
    }

    Node *head = list.tail->next;
    Node *current = head;

    do {
        printf("%d ", current->value);
        
        current = current->next;
        
    } while(current != head);
}

int insert(const int value, LinkedList *list) {
    Node *node = NULL;
    Node *head = (isEmpty(list->tail)) ? NULL : list->tail->next; 
    
    CreateNode(value, &node);

    if(isEmpty(node)) {
        return ERR_MEMORY_ALLOCATION_NOT_ALLOWED;
    }

    node->next = isEmpty(head) ? node : head;

    if(isEmpty(list->tail)) {
        list->tail = node;
    }
    else {
        list->tail->next = node;
    }

    return PROCEDURE_ALLOWED;    
}

int append(const int value, LinkedList *list) {
    Node *node = NULL;

    CreateNode(value, &node);

    if(isEmpty(node)) {
        return ERR_MEMORY_ALLOCATION_NOT_ALLOWED;
    }

    node->next = isEmpty(list->tail) ? node : list->tail->next;

    if(!isEmpty(list->tail)) {
        list->tail->next = node;
    }

    list->tail = node;

    return PROCEDURE_ALLOWED;
}

int insertAt(const int value, const size_t index, LinkedList *list) {
    Node *node = NULL;
    Node *head = isEmpty(list->tail) ? NULL : list->tail->next;
    Node *current = list->tail;
    size_t currIndex = 0;
    bool isOutOfRange;

    CreateNode(value, &node);

    if(isEmpty(node)) {
        return ERR_MEMORY_ALLOCATION_NOT_ALLOWED;
    }

    if(isEmpty(head)) {
        list->tail = node;
        node->next = node;

        return PROCEDURE_ALLOWED;
    }

    while(currIndex != index - 1) {
        current = current->next;
        currIndex++;
    }

    isOutOfRange = (current->next == head) && (index != 1);

    if(isOutOfRange) {
        return ERR_INDEX_OUT_OF_RANGE;
    }

    node->next = current->next;
    current->next = node;

    return PROCEDURE_ALLOWED;
}

int removeFromFront(LinkedList *list) {
    if(isEmpty(list->tail)) {
        return ERR_EMPTY_LIST;
    }

    Node *head = list->tail->next;
    bool isTheLastElementInTheList = (head->next == head);

    if(isTheLastElementInTheList) {
        list->tail = NULL;
    }
    else {
        list->tail->next = head->next;
    }

    free(head);

    return PROCEDURE_ALLOWED;
}

int removeFromBack(LinkedList *list) {
    if(isEmpty(list->tail)) {
        return ERR_EMPTY_LIST;
    }
    
    Node *current = list->tail->next; /* head */
    Node *temp = NULL;
    bool isTheLastElementInTheList = (current->next == current);

    if(isTheLastElementInTheList) {
        list->tail = NULL;
        free(current);

        return PROCEDURE_ALLOWED;
    }

    while(current->next != list->tail) {
        current = current->next;
    }

    temp = current->next;
    current->next = list->tail->next;
    list->tail = current;
    
    free(temp);

    return PROCEDURE_ALLOWED;
}

// Remove node at given index
// Remove first item in the list with given value

// Get front item
// Get back item

// Reverse
// Return value of the nth item
// Value N from end
// Size