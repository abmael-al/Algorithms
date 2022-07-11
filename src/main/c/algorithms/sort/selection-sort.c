#include <stdio.h>
#include <stdlib.h>

void selectionSort(int array[], const size_t length) {
    if(array == NULL) {
        return;
    }

    int i, j, min, temp;

    for(i = 0; i < length; i++) {
        min = i;

        for(j = i + 1; j < length; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }

        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
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