// Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
// threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be
// composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack

// Source [BOOK]: Cracking the Coding Interview. Chapter 2, page 94.

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
} Stack;
