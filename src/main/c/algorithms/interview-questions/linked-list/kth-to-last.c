#include <stdio.h>
#include <stdlib.h>

#define ERR_EMPTY_LIST -1;
#define ERR_OUT_OF_BOUNDS ERR_EMPTY_LIST;

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

int kthToLast(int k, Node *head) {
    if(isEmpty(head)) {
        return ERR_EMPTY_LIST;
    }

    Node* behind = head;
    Node* ahead = head;

    walk(k - 1, &ahead);

    if(isEmpty(ahead)) {
        return ERR_OUT_OF_BOUNDS;
    }

    while(!isEmpty(ahead->next)) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind->value;
}

int main() {
    Node *head = NULL;

    push(1, &head);
    push(2, &head);
    push(3, &head);
    push(4, &head);
    push(5, &head);
    push(6, &head);
    push(7, &head);
    push(8, &head);
    push(9, &head);
    
    print(head);
    
    int i;
    for(i = 0; i < 12; i++) {
        printf("\nKth to last [%d]: %d", i, kthToLast(i, head));
    }

    return 0;
}