#include <stdio.h>
#include <stdlib.h>

#define ERR_OUT_OF_RANGE -3
#define ERR_EMPTY_LIST -1
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

    while(isNotEmpty(iterator)){
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
    Node *iterator = head;

    if(isEmpty(head)) {
        return NULL;
    }

    while(isNotEmpty(iterator->next)) {
        iterator = iterator->next;
    }

    return iterator;
}

// Returns the value of the nth item.
// Time complexity: O(n)
int valueAt(int position, Node *head) {
    Node *iterator = head;
    
    if(isEmpty(head)) {
        return ERR_EMPTY_LIST;
    }

    int currPosition = 1;
    while(isDiff(currPosition, position) && isNotEmpty(iterator->next)) {  
        ++currPosition;
        iterator = iterator->next;
    }
    
    if(isDiff(currPosition, position)) {
        return ERR_OUT_OF_RANGE;
    }

    return iterator->value;
}

void print(Node *head) {
    if(isEmpty(head)) {
        return;
    }

    printf("\n");
    
    while(isNotEmpty(head)) {
        printf("%d ", head->value);
        
        head = head->next;
    }
}

// Inserts an item to the front of the list.
// Time complexity: O(1)
void appendFront(int value, Node **head) {
    Node *node = createNode(value);
    Node *helper = *head;

    if(isEmpty(*head)) {
        *head = node;
        
        return;
    }

    *head = node;
    node->next = helper;
}