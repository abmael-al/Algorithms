#include <stdio.h>
#include <stdlib.h>

// INPUT: An array of n numbers {a1, a2, a3 ..., an}.
// OUTPUT: A permutation (reordering) {a1', a2', a3' ..., an'} of the input
// array such that a1' <=  a2' <= a3' ... <= an'.

void insertionSort(int array[], const int length) {
    if(array == NULL) {
        return;
    }   

    int i, j, key;

    for(i = 1; i < length; i++) {
        key = array[i];
        j = i;            

        while(array[j - 1] > key) {
            array[j] = array[j - 1];

            j--;
        }

        array[j] = key;
    }
}

int main() {
    int arr[] = { 9, 2, 65, 3, 7, 1, 2 };
    int length = sizeof arr / sizeof(int);

    insertionSort(arr, length);

    int i; 
    for(i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}