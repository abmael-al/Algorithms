#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "stddef.h"

typedef struct Queue {
    size_t mem_size;
    struct Node *tail;
} Queue;

/* Fully initialize all fields of a Queue. 

 Returns 1 is the operation is successfull. If illegal mem size 
 is passed, then returns -5 and nothing is initialized. */
int Queue_Init(Queue *queue, const size_t mem_size);


/* Returns true if the queue is empty, otherwise, false. */
bool Queue_IsEmpty(const Queue queue);


/* Makes a copy of least recently added element, then assign the 
 copy at the respective argument.

 Returns 1 if the operation is successful. If the queue is empty, 
 returns -1. */
int Queue_Peek(const Queue queue, void *dest);


/* Adds value at last position.

 Returns 1 if the operation is successful. If some error ocurred
 during memory allocation, returns -2. */
int enqueue(Queue *queue, const void *data);


/* Makes a copy of least recently added element, then assign the copy at 
 the respective argument and removes the element from the queue.

 Returns 1 if the operation is successful. If the queue is empty, 
 returns -1. */
int dequeue(Queue *queue, void *dequeued_data_dest);

#endif