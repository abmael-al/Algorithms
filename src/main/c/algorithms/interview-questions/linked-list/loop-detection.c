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

Node * loopDetection(Node* head) {
    if(isEmpty(head)) {
        return NULL;
    }

    Node *nodeAtBeginningOfTheLoop = NULL;

    Node *slow = head;

    Node *fast = head;

    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            nodeAtBeginningOfTheLoop = slow;

            break;
        }
    }

    return nodeAtBeginningOfTheLoop;
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

    push(9, &head);
    push(8, &head);
    push(7, &head);
    push(6, &head);
    push(5, &head);
    push(4, &head);
    push(3, &head);
    push(2, &head);
    push(1, &head);

    print(head);

    back(head)->next = head;

    printf("\nLoop detection: %d", loopDetection(head)->value);

    return 0;
}