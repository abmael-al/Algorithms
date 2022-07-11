#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];

    arr[i] = arr[j];
    arr[j] = temp;
}


void selectionSort(int array[], const size_t length) {
    if(array == NULL) {
        return;
    }

    int i, j, min;

    for(i = 0; i < length; i++) {
        min = i;

        for(j = i + 1; j < length; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }

        swap(array, i, min);
    }
}

int main() {
    int arr[] = { 6, 34, 1, 5, 2, 8, 1, 54, 2 };
    const size_t length = sizeof arr / sizeof(int);

    selectionSort(arr, length);

    int i;
    for(i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}   