// File header
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"

#define ALLOCATION_ALLOWED 2
#define OPERATION_ALLOWED 1
#define ERR_EMPTY_QUEUE -1
#define ERR_MEMORY_ALLOCATION_NOT_ALLOWED -2
#define ERR_DATA_MEM_ALLOCATION_NOT_ALLOWED -3
#define ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED -4
#define ERR_ILLEGAL_MEM_SIZE -5

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

int Node_Create(Node **dest, const size_t mem_size) {
    if(mem_size == 0) {
        return ERR_ILLEGAL_MEM_SIZE;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    
    *dest = node;

    if(node == NULL) {
        return ERR_NODE_MEM_ALLOCATION_NOT_ALLOWED;
    }

    node->data = malloc(mem_size);
    
    if(node->data == NULL) {
        // Errant code tends to fail faster with a 0 pointer/data 
        // than with its original data still potentially intact. 
        // Faster failing code is easier to debug.
        memset(node, 0, sizeof *node);
        free(node);
        *dest = NULL;
        
        return ERR_DATA_MEM_ALLOCATION_NOT_ALLOWED;
    }

    node->next = NULL;

    return ALLOCATION_ALLOWED;
}

int Queue_Init(Queue *queue, const size_t mem_size) {
   if(mem_size == 0) {
        return ERR_ILLEGAL_MEM_SIZE;
   }
   
    queue->mem_size = mem_size;
    queue->tail = NULL;

    return OPERATION_ALLOWED;
}

bool Queue_IsEmpty(const Queue queue) {    
    return queue.tail == NULL;
}

int Queue_Peek(const Queue queue, void *dest) {
    if(Queue_IsEmpty(queue)) {
        return ERR_EMPTY_QUEUE;
    }

    const Node *head = queue.tail->next;

    memcpy(dest, head->data, queue.mem_size);

    return OPERATION_ALLOWED;
}

int enqueue(Queue *queue, const void *data) {
    Node *node;

    Node_Create(&node, queue->mem_size);

    if(node == NULL) {
        return ERR_MEMORY_ALLOCATION_NOT_ALLOWED;
    }

    memcpy(node->data, data, queue->mem_size);

    if(Queue_IsEmpty(*queue)) {
        queue->tail = node;
        node->next = node;
    }
    else {
        node->next = queue->tail->next;
        
        queue->tail->next = node;
        queue->tail = node;
    }

    return OPERATION_ALLOWED;
}

int dequeue(Queue *queue, void *dequeued_data_dest) {
    if(Queue_IsEmpty(*queue)) {
        return ERR_EMPTY_QUEUE;
    }

    Node *ex_head = queue->tail->next;
    Node *new_head = ex_head->next;

    bool isNotTheLastNode = new_head != ex_head;

    queue->tail->next = (isNotTheLastNode) ? new_head : NULL;
    queue->tail = (isNotTheLastNode) ? queue->tail : NULL;

    if(dequeued_data_dest != NULL) {
        memcpy(dequeued_data_dest, ex_head->data, queue->mem_size);
    }
    
    free(ex_head->data);
    free(ex_head);

    return OPERATION_ALLOWED;
}