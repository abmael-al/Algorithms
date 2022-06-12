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

// Print in forward order.
// Time complexity: O(n)
void printForward(Node *head) {
    if(isEmpty(head)) {
        return;
    }
    
    printf("\n------------ LIST VIEW: FORWARD ------------\n\n");

    while (isNotEmpty(head)) {
        printf("%d ", head->value);

        head = head->next;
    }
    
    printf("\n\n-------------------------------------------\n");
}

// Print a doubly linked list in backward order.
// Time complexity: O(n)
void printBackward(Node *head) {
    if(isEmpty(head)) {
        return;
    }

    Node *iterator = back(head);

    printf("\n------------ LIST VIEW: BACKWARD ------------\n\n");

    while(isNotEmpty(iterator)) {
        printf("%d ", iterator->value);

        iterator = iterator->prev;
    }

    printf("\n\n--------------------------------------------\n");
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

    node->next = helper;

    *head = node;

    helper->prev = node;
}

// Inserts an item at the end of the list.
// Time complexity: O(n)
void appendBack(int value, Node **head) {
    Node *node = createNode(value);

    if(isEmpty(*head)) {
        *head = node;

        return;
    }

    Node *tail = back(*head);

    tail->next = node;

    node->prev = tail;
}


// Insert value at index, so current item at that index.
// is pointed to by new item at index.
// Time complexity; O(n)
void appendAt(int position, int value, Node **head) {
    Node *node = createNode(value);
    Node *current = *head;
    Node *previous = NULL;
    int currPos = 1;
    
    if(isEmpty(*head)) {
        *head = node;

        return;
    }

    if(position == 1) {
        current->prev = node;
        node->next = current;

        *head = node;

        return;
    }

    while(isDiff(currPos, position) && isNotEmpty(current->next)) {
        ++currPos;
        previous = current;
        current = current->next;
    }

    if(isDiff(currPos, position)) {
        return;
    }

    previous->next = node;
    current->prev = node;

    node->prev = previous;
    node->next = current;
}

// Removes the first item in the list with this value.
// Time complexity: O(n)
void deleteValue(int value, Node **head) {
    if(isEmpty(*head)) {
        return;
    }

    Node *current = *head;
    Node *posterior = NULL;
    Node *previous = NULL;

    int isTheFirstNode = (*head)->value == value;
    
    if(isTheFirstNode) {
        posterior = current->next;
        posterior->prev = NULL;

        *head = posterior;

        free(current);

        return;
    } 

    while(isDiff(current->value, value) && isNotEmpty(current->next)) {
        current = current->next;
    }

    if(isDiff(current->value, value)) {
        return;
    }

    posterior = current->next;
    previous = current->prev;

    if(isEmpty(posterior)) {
        previous->next = NULL;
    }
    else if (isNotEmpty(posterior)) {
        posterior->prev = previous;   
        previous->next = posterior;
    }

    free(current);
}