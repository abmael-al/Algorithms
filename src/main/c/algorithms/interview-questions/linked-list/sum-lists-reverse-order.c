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

void appendBack(int value, Node **head) {
    Node *node = createNode(value);
    Node *tail = back(*head);

    if(isEmpty(*head)) {
        *head = node;
        
        return;
    }

    tail->next = node;
}

void print(Node* head) {
    printf("\n");

    while(head) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

Node * sum(Node *head1, Node *head2) {
    if(isEmpty(head1)) {
        return head2;
    }
    else if(isEmpty(head2)) {
        return head1;
    }

    Node *result = NULL;
    int carry = 0;

    while(!isEmpty(head1) && !isEmpty(head2)) {
        int sum = head1->value + head2->value + carry;
        carry = sum / 10;
        sum = sum % 10;

        appendBack(sum, &result);

        head1 = head1->next;
        head2 = head2->next;
    }

    Node *remainder = (isEmpty(head1)) ? head2 : head1;
    
    while(!isEmpty(remainder)) {
        int sum = remainder->value + carry;
        carry = sum / 10;
        sum = sum % 10;

        appendBack(sum, &result);

        remainder = remainder->next;
    }

    if(carry) {
        appendBack(carry, &result);
    }

    return result;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    
    // 823
    appendBack(3, &head1);
    appendBack(2, &head1);
    appendBack(8, &head1);

    // 23471
    appendBack(1, &head2);
    appendBack(7, &head2);
    appendBack(4, &head2);
    appendBack(3, &head2);
    appendBack(2, &head2);

    Node *result = sum(head1, head2);

    // 4 9 2 4 2 --> 24294
    print(result);

    return 0;
}
