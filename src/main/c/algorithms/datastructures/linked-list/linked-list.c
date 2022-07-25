#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROCEDURE_ALLOWED 1
#define ERR_EMPTY_LIST 0
#define ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED -1
#define ERR_MEMORY_ALLOCATION_NOT_ALLOWED -2
#define ERR_VALUE_DOES_NOT_EXIST_IN_THE_LIST -3
#define ERR_INDEX_OUT_OF_RANGE -4

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

// Display all the values from the list. 
void print(LinkedList list) {
    if(isEmpty(list.tail)) {
        return;
    }

    Node *head = list.tail->next;
    Node *current = head;

    printf("\n");
    do {
        printf("%d ", current->value);
        
        current = current->next;
        
    } while(current != head);
    printf("\n");
}

// Get the value of the first node. 
int front(const LinkedList list) {
    if(isEmpty(list.tail)) {
        return ERR_EMPTY_LIST;
    }

    return list.tail->next->value;
}

// Get the value of the lastnode. 
int back(const LinkedList list) {
    if(isEmpty(list.tail)) {
        return ERR_EMPTY_LIST;
    }

    return list.tail->value;
}

// Get the length of the linked list. 
size_t length(LinkedList list) {
    size_t size = 0;
    
    if(isEmpty(list.tail)) {
        return size;
    }

    Node *head = list.tail->next;
    Node *current = head;

    do {
        current = current->next;
        size++;

    } while(current != head);

    return size;
}

// Get the value of a node at a given position. 
int valueAt(const size_t index, LinkedList list) {
    if(isEmpty(list.tail)) {
        return ERR_EMPTY_LIST;
    }

    Node *head = list.tail->next;
    Node *current = head;
    bool isOutOfBounds;
    size_t currIndex = 1;

    while(currIndex != index) {
        current = current->next;
        currIndex++;

        if(current->next == head) {
            break;
        }
    }

    isOutOfBounds = (currIndex != index) && (current->next == head);

    if(isOutOfBounds) {
        return ERR_INDEX_OUT_OF_RANGE;
    }

    return current->value;
}

// Get the value at the nth node from end. 
int nthValueFromEnd(const size_t index, LinkedList list) {
    if(isEmpty(list.tail)) {
        return ERR_EMPTY_LIST;
    }

    Node *head = list.tail->next;
    Node *ahead = head;
    Node *behind = head;
    size_t currIndex = 0;
    bool isOutOfBounds;

    while(currIndex != index - 1) {
        ahead = ahead->next;
        currIndex++;

        if(ahead->next == head) {
            break;
        }
    }
    
    isOutOfBounds = (ahead->next == head) && (++currIndex != index);

    if(isOutOfBounds) {
        return ERR_INDEX_OUT_OF_RANGE;
    }

    while(ahead->next != head) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind->value;
}

// Insert a value at the first position.
int insertAtHead(const int value, LinkedList *list) {
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

// Insert a value at the last position.
int insertAtTail(const int value, LinkedList *list) {
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

// Insert a value at a given position. If list is empty, inserts
// at the first position.
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

        if(current->next == head) {
            break;
        }
    }

    isOutOfRange = (current->next == head) && (index != 1);

    if(isOutOfRange) {
        return ERR_INDEX_OUT_OF_RANGE;
    }

    node->next = current->next;
    current->next = node;

    return PROCEDURE_ALLOWED;
}

// Removes the node at the first position. 
int deleteHead(LinkedList *list) {
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

// Removes the node at the last position. 
int deleteTail(LinkedList *list) {
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

// Removes the node at a given position. 
int deleteAt(const size_t index, LinkedList *list) {
    if(isEmpty(list->tail)) {
        return ERR_EMPTY_LIST;
    }

    Node *current = list->tail;
    Node *head = list->tail->next;
    Node *temp = NULL;
    size_t currIndex = 0;
    bool isOutOfRange;
    bool isAtTheLastPosition;

    while(currIndex != index - 1) {
        current = current->next;
        currIndex++;

        if(current->next == head) {
            break;
        }
    } 

    isOutOfRange = (current->next == head) && (index != 1);
    isAtTheLastPosition = (current->next == list->tail);

    if(isOutOfRange) {
        return ERR_INDEX_OUT_OF_RANGE;
    }

    if(isAtTheLastPosition) {
        list->tail = current;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);

    return PROCEDURE_ALLOWED;
}

// Removes the first node that holds a given value. 
int deleteValue(const int value, LinkedList *list) {
    if(isEmpty(list->tail)) {
        return ERR_EMPTY_LIST;
    }

    Node *head = list->tail->next;
    Node *current = list->tail;
    Node *previous = NULL;
    bool valueDoesNotExistInTheList;
    bool isAtTheLastPosition;

    do {
        previous = current;
        current = current->next;

        if(current->next == head) {
            break;
        }

    } while(current->value != value);

    valueDoesNotExistInTheList = (current->next == head) 
                              && (current->value != value);

    isAtTheLastPosition = (current->next == head) 
                       && (current->value == value);

    if(valueDoesNotExistInTheList) {
        return ERR_VALUE_DOES_NOT_EXIST_IN_THE_LIST;
    }

    if(isAtTheLastPosition) {
        list->tail = previous;
    }

    previous->next = current->next;
    free(current);

    return PROCEDURE_ALLOWED;
}

int main() {
    LinkedList list;

    InitLinkedList(&list);

    insertAtHead(5, &list);
    insertAtHead(4, &list);
    insertAtHead(3, &list);
    insertAtHead(2, &list);
    insertAtHead(1, &list);

    print(list);

    insertAtTail(6, &list);
    insertAtTail(7, &list);
    insertAtTail(8, &list);
    insertAtTail(9, &list);

    print(list);
    printf("Length: %lld\n", length(list));

    deleteHead(&list);
    deleteTail(&list);
    deleteAt(2, &list);

    print(list);


    return 0;
}