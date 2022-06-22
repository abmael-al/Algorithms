// Write code to partition a linked list around a value x, such that all nodes less than x come
// before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
// to be after the elements less than x (see below). The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right partitions.
// EXAMPLE
 
// Input: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8 
// Output: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]

// Source [BOOK]: Cracking the Coding Interview. Chapter 2, page 94.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

int isEmpty(Node* node) {
    return node == NULL;
}

void push(int value, Node **head) {
    Node* node = createNode(value);

    if(isEmpty(*head)) {
        *head = node;

        return;
    }

    node->next = *head;
    
    *head = node;
}

void print(Node* head) {
    printf("\n");

    while(head) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

Node * find(int value, Node *head) {
    if(isEmpty(head)) {
        return NULL;
    }

    Node *iterator = head;
    Node *firstInstance = NULL;

    while(!isEmpty(iterator)) {
        if(iterator->value == value) {
            firstInstance = iterator;
            
            break;
        } 

        iterator = iterator->next;
    }

    return (firstInstance) ? firstInstance : NULL;
}

void partition(int value, Node **head) {
    if(isEmpty(*head)) {
        return;
    }
    
    Node *tail = *head;
    Node *current = *head;
    Node *thisValueExistsInTheList = find(value, *head);

    if(!thisValueExistsInTheList) {
        return;
    }        

    while(!isEmpty(current)) {
        Node *next = current->next;
        int isLessThanGivenValue = current->value < value; 
        int isGreaterThanGivenValue = current->value >= value;

        if(isLessThanGivenValue) {
            current->next = *head;
            
            *head = current;
        }
        else if(isGreaterThanGivenValue) {
            tail->next = current;
            
            tail = current;
        }

        current = next;
    }

    tail->next = NULL;
}

int main(){
    Node *head = NULL;

    push(1, &head);
    push(3, &head);
    push(9, &head);
    push(5, &head);
    push(2, &head);
    push(8, &head);
    push(1, &head);
    push(7, &head);
    push(4, &head);
    push(3, &head);
    push(6, &head);
    push(1, &head);
    push(3, &head);
    push(9, &head);
    push(5, &head);
    push(2, &head);
    push(8, &head);
    push(1, &head);
    push(7, &head);
    push(6, &head);
    push(4, &head);
    push(3, &head);
    
    print(head);

    partition(6, &head);

    print(head);

    return 0;
}