#include <stdio.h>
#include <stdlib.h>

#define ERR_OUT_OF_RANGE -1
#define ERR_EMPTY_LIST -1

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Create an initialized node.
Node * createNode(const int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isDiff(const int n1, const int n2) {
    return n1 != n2;
}

int isEmpty(const Node *node) {
    return node == NULL;
}

// Returns number of data elements in list.
// Time complexity: O(n)
int size(Node *head) {
    Node *iterator = head;
    int size = 0;

    if(isEmpty(head)) {
        return size;
    }

    while(!isEmpty(iterator)){
        ++size;
        iterator = iterator->next;
    }

    return size;
}

// Returns front node.
// Time complexity: O(1)
Node * front(Node *head) {
    return head;
}

// Returns back node.
// Time complexity: O(n)
Node * back(Node *head) {
    Node *iterator = head;

    if(isEmpty(head)) {
        return NULL;
    }

    while(!isEmpty(iterator->next)) {
        iterator = iterator->next;
    }

    return iterator;
}

// Returns the value of the nth item.
// Time complexity: O(n)
int valueAt(const int position, Node *head) {
    Node *iterator = head;
    
    if(isEmpty(head)) {
        return ERR_EMPTY_LIST;
    }

    int currPosition = 1;
    while(isDiff(currPosition, position) && !isEmpty(iterator->next)) {  
        ++currPosition;
        iterator = iterator->next;
    }
    
    if(isDiff(currPosition, position)) {
        return ERR_OUT_OF_RANGE;
    }

    return iterator->value;
}

void print(const Node *head) {
    printf("\n");
    
    while(!isEmpty(head)) {
        printf("%d ", head->value);
        
        head = head->next;
    }
}

// Inserts an item to the front of the list.
// Time complexity: O(1)
void appendFront(const int value, Node **head) {
    Node *node = createNode(value);
    Node *helper = *head;

    if(isEmpty(*head)) {
        *head = node;
        
        return;
    }

    *head = node;

    node->next = helper;
}

// Inserts an item at the end of the list.
// Time complexity: O(n)
void appendBack(const int value, Node **head) {
    Node *node = createNode(value);
    Node *tail = back(*head);

    if(isEmpty(*head)) {
        *head = node;
        
        return;
    }

    tail->next = node;
}

// Insert value at index, so current item at that index.
// is pointed to by new item at index.
// Time complexity: O(n)
void appendAt(const int value, const int position, Node **head) {
    Node *node = createNode(value);
    Node *iterator = *head;
        
    if(isEmpty(*head)) {
        *head = node;
        
        return;
    }
    
    int i = 1;
    int oneValuePriorToPosition = position - 1;
    
    for(i = 1; i < oneValuePriorToPosition; i++) {
        if(isEmpty(iterator->next)) {
            return;
        }

        iterator = iterator->next;
    }

    Node *helper = (position == 1) ? *head : iterator->next;

    if(*head == helper) {
        *head = node;

        node->next = helper;

        return;
    }

    iterator->next = node; 

    node->next = helper;
}

// Remove front item and return its value.
// Time complexity: O(1)
int popFront(Node **head) {
    Node *poppedNode = *head;
    int poppedValue = (*head)->value;

    if(isEmpty(*head)) {
        return ERR_EMPTY_LIST;
    }

    *head = (*head)->next;

    free(poppedNode);

    return poppedValue;
}

// Removes end item and returns its value.
// Time complexity: O(n)
int popBack(Node **head) {
    Node *current = *head;
    Node *previous = NULL;

    if(isEmpty(*head)) {
        return ERR_EMPTY_LIST;
    }

    while(!isEmpty(current->next)) {
        previous = current;

        current = current->next;
    }

    int isTheOnlyNodeInTheList = isEmpty(previous); 

    if(isTheOnlyNodeInTheList) {
        *head = NULL;
    }
    else if (!isEmpty(previous)) {
        previous->next = NULL;
    }

    int poppedValue = current->value;
    
    free(current);

    return poppedValue;
}

// Removes the first item in the list with this value.
// Time complexity: O(n)
void deleteValue(const int value, Node **head) {
    Node *previous = *head;
    Node *current = (*head)->next;
    
    if(isEmpty(*head)) {
        return;
    }

    int isFirstValue = (*head)->value == value;
    
    if(isFirstValue) {
        Node *helper = *head;
        
        (*head) = (*head)->next;
        
        free(helper);

        return;
    }

    while(isDiff(current->value, value) && !isEmpty(current->next)) {
        previous = current;

        current = current->next;
    }

    if(isDiff(current->value, value)) {
        return;
    }

    previous->next = current->next;

    free(current);
}

// Removes node at given index.
// Time complexity: O(n)
void deleteAt(const int position, Node **head) {
    Node *current = *head;
    Node *previous = NULL;
    int currPos = 1;

    if(isEmpty(*head)) {
        return;
    }

    if(position == 1) {
        *head = (*head)->next;

        free(current);

        return;
    }

    while(isDiff(currPos, position) && !isEmpty(current->next)) {
        ++currPos;

        previous = current;

        current = current->next;
    }

    if(isDiff(currPos, position)) {
        return;
    }
    
    previous->next = current->next;
    
    free(current);
}
