#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;
