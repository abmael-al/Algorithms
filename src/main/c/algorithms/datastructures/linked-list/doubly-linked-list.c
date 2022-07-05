#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_LIST -1
#define ERR_OUT_OF_RANGE -2

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node * createNode(const int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;
    node->prev = NULL;

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

    while(!isEmpty(iterator)) {
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
    if(isEmpty(head)) {
        return NULL;
    }

    while(!isEmpty(head->next)) {
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

    while(isDiff(currPos, position) && !isEmpty(iterator->next)) {
        ++currPos;

        iterator = iterator->next;
    }

    if(isDiff(currPos, position)) {
        return ERR_OUT_OF_RANGE;
    }

    return iterator->value;
}

// Print in forward order.
// Time complexity: O(n)
void printForward(Node *head) {
    printf("\n------------ LIST VIEW: FORWARD ------------\n\n");

    while (!isEmpty(head)) {
        printf("%d ", head->value);

        head = head->next;
    }
    
    printf("\n\n-------------------------------------------\n");
}

// Print a doubly linked list in backward order.
// Time complexity: O(n)
void printBackward(Node *head) {
    Node *iterator = back(head);

    printf("\n------------ LIST VIEW: BACKWARD ------------\n\n");

    while(!isEmpty(iterator)) {
        printf("%d ", iterator->value);

        iterator = iterator->prev;
    }

    printf("\n\n--------------------------------------------\n");
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

    node->next = helper;

    *head = node;

    helper->prev = node;
}

// Inserts an item at the end of the list.
// Time complexity: O(n)
void appendBack(const int value, Node **head) {
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
void appendAt(const int position, const int value, Node **head) {
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

    while(isDiff(currPos, position) && !isEmpty(current->next)) {
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

// Remove front item and return its value.
// Time complexity: O(1)
int popFront(Node **head) {
    if(isEmpty(*head)) {
        return ERR_EMPTY_LIST;
    }

    Node *current = *head;
    Node *posterior = current->next;
    int poppedValue = current->value;

    posterior->prev = NULL;

    *head = posterior;

    free(current);

    return poppedValue;
}

// Removes end item and returns its value.
// Time complexity: O(n)
int popBack(Node **head) {
    if(isEmpty(*head)) {
        return ERR_EMPTY_LIST;
    }

    Node *current = back(*head);
    Node *previous = current->prev;
    int poppedValue = current->value;

    int isTheOnlyNodeInTheList = isEmpty(previous);

    if(isTheOnlyNodeInTheList) {
        *head = NULL;
    }
    else if(!isEmpty(previous)) {
        previous->next = NULL;
    }

    free(current);

    return poppedValue;
}

// Removes the first item in the list with this value.
// Time complexity: O(n)
void deleteValue(const int value, Node **head) {
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

    while(isDiff(current->value, value) && !isEmpty(current->next)) {
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
    else if (!isEmpty(posterior)) {
        posterior->prev = previous;   

        previous->next = posterior;
    }

    free(current);
}

// Removes node at given index.
// Time complexity: O(n)
void deleteAt(int position, Node **head) {
    if(isEmpty(*head)) {
        return;
    }

    int currPos = 1;
    Node *current = *head;
    Node *posterior = NULL;
    Node *previous = NULL;

    if(position == 1) {
        posterior = current->next;
        posterior->prev = NULL;

        *head = posterior;

        free(current);

        return;
    }

    while(isDiff(currPos, position) && !isEmpty(current->next)) {
        ++currPos;
        current = current->next;
    }

    if(isDiff(currPos, position)) {
        return;
    }

    posterior = current->next;

    previous = current->prev;

    if(isEmpty(posterior)) {
        previous->next = NULL;
    }
    else if(!isEmpty(posterior)) {
        posterior->prev = previous;

        previous->next = posterior;
    }

    free(current);
}

int main() {
    Node *head = NULL;

    appendBack(4, &head);
    appendBack(5, &head);
    appendBack(6, &head);

    appendFront(3, &head);
    appendFront(2, &head);
    appendFront(1, &head);

    printForward(head); // Linked list: 1 2 3 4 5 6 

    printf("\n\nValue at 3rd position: %d", valueAt(3, head)); // Value at 3rd position: 3
    
    printf("\n\nPop back %d", popBack(&head)); // Pop back: 6

    printf("\n\nSize %d\n", size(head)); // Size: 5
    
    printForward(head); // Linked list: 1 2 3 4 5  

    return 0;
}