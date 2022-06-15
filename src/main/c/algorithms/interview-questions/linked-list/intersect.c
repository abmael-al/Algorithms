#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

//  Given two (singly) linked lists, determine if the two lists intersect. 
// Return the intersecting node. Note that the intersection is defined based on reference, not value. 
// That is, if the kth node of the first linked list is the exact same node (by reference) as the jth 
// node of the second linked list, then they are intersecting. 

// Source [BOOK]: Cracking the Coding Interview. Chapter 2, page 94.

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

int diff(int n1, int n2) {
    return abs(n1 - n2);
}

void walk(int steps, Node **node) {
    int i;
    int isOutOfBounds;

    for(i = 0; i < steps; i++) {
        isOutOfBounds = isEmpty((*node)->next);

        if(isOutOfBounds) {
            *node = NULL;

            return;
        }

        *node = (*node)->next;
    }
}

Node* getPossibleIntersection(Node *head1, Node *head2) {
    while(!isEmpty(head1) && !isEmpty(head2)) {
        if(head1->next == head2->next) {
            return head1->next;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

Node* intersect(Node* head1, Node* head2) {
    int sizeHead1 = size(head1);
    int sizeHead2 = size(head2);
    int sizesDiff = diff(sizeHead1, sizeHead2);

    Node* greaterList = NULL;
    Node* smallerList = NULL;

    if(sizeHead1 >= sizeHead2) {
        greaterList = head1;
        smallerList = head2;
    }
    else if (sizeHead2 > sizeHead1) {
        greaterList = head2;
        smallerList = head1;
    }

    walk(sizesDiff, &greaterList);

    Node* intersectionNode = getPossibleIntersection(greaterList, smallerList);

    return intersectionNode;
}

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

int main() {
    Node *head = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    push(-3, &head);
    push(-2, &head);
    push(-1, &head);
    push(0, &head);
    push(1, &head);
    push(2, &head);
    push(3, &head);

    push(1, &head2);
    push(2, &head2);
    push(3, &head2);

    push(4, &head3);
    push(5, &head3);
    push(6, &head3);

    back(head)->next = head3;
    back(head2)->next = head3;

    return 0;
}