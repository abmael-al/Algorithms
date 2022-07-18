#include "Queue.h"
#include <stdio.h>
#include <stdio.h>

int main() {
    Queue queue;
    int i, dest;

    Queue_Init(&queue, sizeof(int));

    printf("Inserting elements...");
    for(i = 0; i < 15; i++) {
        enqueue(&queue, &i);
    }

    Queue_Peek(queue, &dest);
    printf("\nPeek: %d", dest);

    printf("\nRemoving all elements...");
    printf("\nRemoved elements: ");
    while(!Queue_IsEmpty(queue)) {
        dequeue(&queue, &dest);
        printf("%d ", dest);
    }

    printf("\nDouble checking...");
    if(Queue_IsEmpty(queue)) {
        printf("\nAll elements removed successfully.");
    }
    else {
        printf("\nOoops! Not empty yet.");
    }

    return 0;
}