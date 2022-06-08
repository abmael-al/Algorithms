#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *arr;
    size_t capacity;
    size_t current;
} Array;

Array* init(Array *array, size_t size) {
    array->arr = (int*)calloc(size, sizeof(int));
    array->capacity = size;
    array->current = 0;

    return array;
}

int isEmpty(int *array) {
    return array == NULL;
}

int isFull(int current, int capacity) {
    return current == capacity;
}

void freeArray(Array *array) {
    free(array->arr);

    array->arr = NULL;
    array->capacity = 0;
    array->current = 0;
}

Array* push(int value, Array* array) {
    if(isFull(array->current, array->capacity)) {
       array->capacity *= 2;
       array->arr = realloc(array->arr, array->capacity * sizeof(int));
    }

    array->arr[array->current] = value;
    ++array->current;

    return array;
}

void pushAt(int value, int position, Array* array) {
    if(position > array->current) {
        return;
    }

    if(isFull(array->current, array->capacity)) {
       array->capacity *= 2;
       array->arr = realloc(array->arr, array->capacity * sizeof(int));
    }

    int previous = array->current; 
    int posterior = previous + 1;

    while(posterior != position) {
        array->arr[posterior] = array->arr[previous];
        --previous;
        --posterior;
    }
    
    array->arr[posterior] = value;
    ++array->current;
}

void replaceBy(int index, int value, Array* array) {
    int currIndex = 0;

    if(currIndex > array->capacity) {
        return;
    }

    array->arr[index] = value;
}

void print(Array array) {
    printf("\n");
    for(int i = 0; i < array.current; i++) {
        printf("%d ", array.arr[i]);
    }
}
