#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];

    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], const size_t length) {
    if(arr == NULL) {
        return;
    }

    int i, j;

    for(i = length; i > 0; i--) {
        for(j = 1; j < i; j++) {
            if(arr[j - 1] > arr[j]) {
                swap(arr, j - 1, j);
            }
        }
    }
}

int main() {
    int arr[] = { 6, 1, 5, 9, 1, 3, 7, 5, 4, 12 };
    const size_t length = sizeof arr / sizeof(int);

    bubbleSort(arr, length);

    int i;
    for(i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}