#include <stdio.h>
#include <stdlib.h>

#define ILLEGAL_CAPACITY NULL
#define ERR_EMPTY_ARR -1
#define MAX 10

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

    int isTheLastElementInTheArray = array->current == 1;

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
        
        if(isEmpty(array->arr)) {
            break;
        }
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
int find(int value, const Array array) {
    if(isEmpty(array.arr)) {
        return ERR_EMPTY_ARR;
    }

    int valueIndex = -1;

    int i;
    for(i = 0; i <= array.current; i++) {
        if(array.arr[i] == value) {
            valueIndex = i;
            break;
        }
    }

    return valueIndex;
}

char * cookString(const Array source, char destination[], const size_t destinationCapacity) {
    int workingIndex = 1;
    int i;

    destination[0] = '[';

    for(i = 0; i < source.current; i++) {
        const int token = source.arr[i] + '0';
        const int tokenIndex = workingIndex;
        const int commaIndex = workingIndex + 1;
        const int spaceIndex = workingIndex + 2;

        destination[tokenIndex] = token;

        int isNotGoingToAddCommaAndSpaceToLastElement = i != source.current - 1;
        if(isNotGoingToAddCommaAndSpaceToLastElement) {
            destination[commaIndex] = ',';
            destination[spaceIndex] = ' ';
        }

        workingIndex += 3;
    }

    int secondToLastIndex = destinationCapacity - 2;
    int lastIndex = destinationCapacity - 1;

    destination[secondToLastIndex] = ']';
    destination[lastIndex] = '\0';

    return destination;
}

char *toString(const Array array) {
    const int BUT_NOT_FOR_THE_LAST_ELEMENT = 2;
    const int MEMORY_FOR_COMMA_AND_SPACE = 3;
    const int NULL_BYTE = 1;
    const int SPACE_FOR_BRACKETS = 2;
    const int isArrayEmpty = isEmpty(array.arr) || (array.current == 0);
    
    int NumOfElements = isArrayEmpty ? SPACE_FOR_BRACKETS + NULL_BYTE : 
                            (array.current * 
                            MEMORY_FOR_COMMA_AND_SPACE - 
                            BUT_NOT_FOR_THE_LAST_ELEMENT) + 
                            SPACE_FOR_BRACKETS + NULL_BYTE;
    
    char *string = (char *)calloc(NumOfElements, sizeof(char));

    cookString(array, string, NumOfElements);

    return string;
}

int main() {
    Array *array = CreateArray(MAX);

    push(1, array); 
    push(2, array); 
    push(3, array); 
    push(4, array); 
    push(5, array);
    push(6, array); 
    push(7, array); 
    push(8, array); 
   
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 
    push(9, array); 

    print(*array);

    deleteAt(1, array);

    print(*array);

    removeValue(9, array);

    print(*array);

    printf("\nFind: %d", find(1, *array));

    return 0;
}