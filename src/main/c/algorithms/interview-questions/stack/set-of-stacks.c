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
