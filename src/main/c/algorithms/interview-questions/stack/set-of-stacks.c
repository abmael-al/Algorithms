// Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
// threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be
// composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack

// Source [BOOK]: Cracking the Coding Interview. Chapter 2, page 94.

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_STACKS 10
#define ERR_EMPTY_SET_OF_STACKS -1
#define NO_STACK_AVAILABLE -1
#define EMPTY_STACK -1

typedef struct Stack {
    int *arr;
    int top;
} Stack;

typedef struct SetOfStacks {
    Stack *stacks[MAX_NUMBER_OF_STACKS];
    int current;
    int maxHeightForEachStack;
} SetOfStacks;

Stack * createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->arr = (int *)calloc(capacity, sizeof(int));
    stack->top = -1;

    return stack;
}

void initSetOfStacks(SetOfStacks *set, int maxHeightForEachStack) {
    set->current = NO_STACK_AVAILABLE;
    set->maxHeightForEachStack = maxHeightForEachStack;
}

int getCurrent(SetOfStacks set) {
    return set.current;
}

Stack * getCurrentStack(SetOfStacks set) {
    int current = getCurrent(set);

    return set.stacks[current];
}

void incrementCurrent(SetOfStacks *set) {
    ++set->current;
}

void allocateNewStackAtNextAvailableIndex(SetOfStacks *set) {
    incrementCurrent(set);
    
    int current = getCurrent(*set);
    
    set->stacks[current] = createStack(set->maxHeightForEachStack);
}

void pushAtCurrentStack(int value, SetOfStacks *set) {
    Stack *currentStack = getCurrentStack(*set);

    currentStack->arr[++currentStack->top] = value;
}

int isCurrentStackEmpty(SetOfStacks *set) {
    int current = set->current;
    Stack *currentStack = set->stacks[current];

    return currentStack->top == EMPTY_STACK; 
}

int isEmpty(SetOfStacks *set) {
    int current = set->current;

    return current == NO_STACK_AVAILABLE;
}

int isCurrentStackFull(SetOfStacks *set) {
    int current = set->current;
    Stack *currentStack = set->stacks[current];

    return (currentStack->top + 1) == set->maxHeightForEachStack;
}

int isFull(SetOfStacks *set) {
    return (set->current + 1) == MAX_NUMBER_OF_STACKS; 
}

void push(int value, SetOfStacks *set) {
    if(isFull(set) && isCurrentStackFull(set)) {
        return;
    }
    else if(isEmpty(set) || isCurrentStackFull(set)) {
        allocateNewStackAtNextAvailableIndex(set);
    }

    pushAtCurrentStack(value, set);
}

int freeCurrentStack(SetOfStacks *set) {
    Stack *currentStack = getCurrentStack(*set);
   
    set->stacks[set->current--] = NULL;
   
    free(currentStack);
}

int popFromCurrentStack(SetOfStacks *set) {
    Stack *currentStack = getCurrentStack(*set);
    int poppedValue = currentStack->arr[currentStack->top];

    --currentStack->top;

    return poppedValue;

}

int pop(SetOfStacks *set) {
    if(isEmpty(set)) {
        return ERR_EMPTY_SET_OF_STACKS;
    }

    int poppedValue = popFromCurrentStack(set);
    
    if(isCurrentStackEmpty(set)) {
        freeCurrentStack(set);
    }

    return poppedValue;
}

Stack * getStackAt(int index, SetOfStacks *set) {
    Stack *stack = set->stacks[index];

    return stack;
}

int popStackAt(int index,  SetOfStacks *set) {
    Stack *stack = getStackAt(index, set);

    int popppedValue = stack->arr[stack->top--];

    return popppedValue;
}

int isValidIndex(int index, SetOfStacks set) {
    return (index + 1) <= set.maxHeightForEachStack;
}

int popAt(int index, SetOfStacks *set) {
    if(isEmpty(set)) {
        return ERR_EMPTY_SET_OF_STACKS;
    }

    int isValidOperation = isValidIndex(index, *set);
    int poppedValue = EMPTY_STACK;

    if(isValidOperation) {
        poppedValue = popStackAt(index, set);
    }

    return poppedValue;
}
