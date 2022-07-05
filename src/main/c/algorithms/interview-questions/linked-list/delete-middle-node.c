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

    deleteMiddleNode(&head);

    printf("\n--- Middle node deleted ---\n");
    print(head);

    return 0;
}