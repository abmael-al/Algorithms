#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *arr;
    size_t size;
    size_t current;
} Array;

Array* init(Array *array, size_t size) {
    array->arr = (int*)calloc(size, sizeof(int));
    array->size = size;
    array->current = 0;

    return array;
}

int isEmpty(int *array) {
    return array == NULL;
}

int isFull(Array array) {
    return array.current == array.size;
}

void freeArray(Array *array) {
    free(array->arr);

    array->arr = NULL;
    array->size = 0;
    array->current = 0;
}

void resize(Array *array, int size) {
    array->size = size;
    array->arr = realloc(array->arr, size * sizeof(int));
}

Array* push(int value, Array* array) {
    if(isFull(*array)) {
       resize(array, array->size * 2);
    }

    array->arr[array->current] = value;
    ++array->current;

    return array;
}

void pushAt(int value, int index, Array* array) {
    int isOutOfRange = index > array->current;
    
    if(isOutOfRange) {
        return;
    }

    if(isFull(*array)) {
       resize(array, array->size * 2);
    }

    int current = array->current; 
    int posterior = current + 1;

    while(posterior != index) {
        array->arr[posterior] = array->arr[current];
        --current;
        --posterior;
    }
    
    array->arr[posterior] = value;
    ++array->current;
}

void replaceBy(int index, int value, Array* array) {
    int isOutOfRange = index > array->current;

    if(isOutOfRange) {
        return;
    }

    array->arr[index] = value;
}

int isQuarterOf(int value, int number) {
    return value == (number / 4);
}

int halfOf(int number) {
    return number / 2;
}

void deleteAt(int index, Array* array) {
    if(isEmpty(array->arr)) {
        return;
    }

    int isOutOfRange = index > array->current;

    if(isOutOfRange) {
        return;
    }

    int isTheLastElementInTheArray = array->current == 0 && index == 0;

    if(isTheLastElementInTheArray) {
        freeArray(array);
        return;
    }

    int current = index;
    int posterior = current + 1;
    while(current != array->current) {
        array->arr[current] = array->arr[posterior];
        ++current;
        ++posterior;
    }

    --array->current;

    if(isQuarterOf(array->current, array->size)) {
        resize(array, halfOf(array->size));
    }
}

void print(Array array) {
    printf("\n");
    for(int i = 0; i < array.current; i++) {
        printf("%d ", array.arr[i]);
    }
    printf("\n");
}

// Returns item at given index, returns -1 if index out of bounds.
// Time complexity: O(1)
int at(int index, Array array) {
    int isOutOfBound = index > array.current;
    
    if(isOutOfBound) {
        return -1;
    }

    return array.arr[index];
}
