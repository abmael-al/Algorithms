#include <stdio.h>
#include <stdlib.h>

#define ILLEGAL_CAPACITY NULL

typedef struct Array {
    int *arr;
    int current;
    size_t size;
} Array;

// Initialize array with a certain capacity.
Array *InitArray(Array *array, size_t size) {
    if(size < 0) {
        return ILLEGAL_CAPACITY;
    }

    array->arr = (int*)calloc(size, sizeof(int));
    array->size = size;
    array->current = 0;

    return array;
}

Array *CreateArray(size_t size) {
    if(size < 0) {
        return ILLEGAL_CAPACITY;
    }
    
    Array *array = (Array *)malloc(sizeof(Array));

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

// Deallocate memory and reset all variables.
void freeArray(Array *array) {
    free(array->arr);

    array->arr = NULL;
    array->size = 0;
    array->current = 0;
}

// Resize a given array with size.
void resize(Array *array, int size) {
    array->size = size;
    array->arr = realloc(array->arr, size * sizeof(int));
}

// Inserts value at last index.
// Time Complexity: O(1)
Array* push(int value, Array* array) {
    if(isFull(*array)) {
       resize(array, array->size * 2);
    }

    array->arr[array->current] = value;
    ++array->current;

    return array;
}

// Inserts value at index, shifts that index's value and trailing elements to the right.
// Time Complexity: O(n)
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

// Replace element at index by given value.
// Time complexity: 0(1)
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

// Remove from end and return value, returns -1 if the array is empty.
// Time complexity: 0(1)
int pop(Array *array) {
    if(isEmpty(array->arr)) {
        return -1;
    }

    int poppedValue = array->arr[array->current--];

    if(isQuarterOf(array->current, array->size)) {
        resize(array, halfOf(array->size));
    }

    return poppedValue;
}

// Delete item at index, shifting all trailing elements left.
// Time complexity: O(n)
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

void removeWhileElementAtIndexEqualsToValue(int index, int value, Array *array) {
    if(isEmpty(array->arr)) {
        return;
    }
    
    while(array->arr[index] == value) {
        deleteAt(index, array);
    }
}

// Looks for value and removes index holding it (even if in multiple places).
// Time complexity: O(n^2)
void removeValue(int value, Array *array) {
    if(isEmpty(array->arr)) {
        return;
    }

    int index = 0;
    for(index; index <= array->current; index++) {
        removeWhileElementAtIndexEqualsToValue(index, value, array);
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

// Looks for value and returns first index with that value, -1 if not found.
// This implementation take into consideration that the array isn't sorted out.
// Time complexity: O(n)
int find(int value, Array array) {
    if(isEmpty(array.arr)) {
        return -1;
    }

    int index = 0;
    for(index = 0; index <= array.current; index++) {
        if(array.arr[index] == value) {
            return index;
        }
    }

    return -1;
}
