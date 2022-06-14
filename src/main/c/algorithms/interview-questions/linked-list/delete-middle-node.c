#include <stdio.h>
#include <stdlib.h>

// Source [BOOK]: Cracking the Code Interview. Chapter 2, page 94. 

// Delete Middle Node: Implement an algorithm to delete a node in the middle 
// (i.e., any node butthe first and last node, not necessarily the exact middle) 
// of a singly linked list, given only access to that node.

// EXAMPLE
// lnput: the node c from the linked list a->b->c->d->e->f
// Result: nothing is returned, but the new linked list looks like a->b->d->e->f

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

void deleteMiddleNode(Node **head) {
    if(isEmpty(*head)) {
        return;
    }

    int hasReachedMiddle;

    Node* fast = (*head)->next;
    Node* slow = *head;
    Node* behindSlow = NULL;

    while(1) {
        hasReachedMiddle = isEmpty(fast);

        if(hasReachedMiddle) {
            break;
        }
        
        if(isEmpty(fast->next)) {
            fast = fast->next;
        }

        else if(!isEmpty(fast->next)) {
            fast = fast->next->next;
        }

        behindSlow = slow;
        slow = slow->next;
    }

    int isTheOnlyNodeInTheList = isEmpty(behindSlow);
    
    if(isTheOnlyNodeInTheList) {
        *head = NULL;

        free(slow);

        return;
    }

    Node* middle = slow;

    behindSlow->next = middle->next;

    free(middle); 
}
