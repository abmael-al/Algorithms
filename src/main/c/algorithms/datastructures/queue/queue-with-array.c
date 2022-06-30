#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    double queue[MAX_SIZE];
    int head;
    int tail;
} Queue;
