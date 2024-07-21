#include <stdio.h>
// Function to find the smallest element in the unsorted part of the array
void smallest(int arr[], int i, int n, int *pos) {
    int small = arr[i];
    *pos = i;
    for (int j = i + 1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            *pos = j;
        }
    }
}
// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, pos;
    for (i = 0; i < n - 1; i++) {
        smallest(arr, i, n, &pos);
        // Swap arr[i] with arr[pos]
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
int main() {
    int arr[] = {34, 74, 15, 42, 65, 10, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
