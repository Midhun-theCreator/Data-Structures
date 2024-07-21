#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int smallest(int arr[], int start, int n) {
    int pos = start;
    int small = arr[start];
    for (int j = start + 1; j < n; j++) {
        if (arr[j] < small) {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}

void selectionSort(int arr[], int n) {
    int pos;
    for (int i = 0; i < n - 1; i++) {
        pos = smallest(arr, i, n);
        swap(&arr[i], &arr[pos]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}