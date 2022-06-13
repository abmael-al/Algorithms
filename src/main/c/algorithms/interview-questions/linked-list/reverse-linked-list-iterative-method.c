#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Given the head of a singly linked list, reverse the list.

typedef struct Node {
    int value;
    struct Node* next;
} Node;
