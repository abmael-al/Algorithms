#include <stdio.h>
#include <stdlib.h>

// INPUT: An array of n numbers {a1, a2, a3 ..., an}.
// OUTPUT: A permutation (reordering) {a1', a2', a3' ..., an'} of the input
// array such that a1' <=  a2' <= a3' ... <= an'.

void insertionSort(int array[], int sizeOfArray) {    
    int arrayLength = sizeOfArray / sizeof(array[0]);
    int i = 1;
    
    for(i; i < arrayLength; i++) {
        int key = array[i];
        int priorIndex = i - 1;            

        while(priorIndex >= 0 && array[priorIndex] > key) {
            int posteriorIndex = priorIndex + 1;

            array[posteriorIndex] = array[priorIndex];

            priorIndex = priorIndex - 1;
        }

        int index = priorIndex + 1;

        array[index] = key;
    }
}