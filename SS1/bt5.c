//
// Created by Admin on 16/06/2025.
//

#include "stdio.h"

void sortArr(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    sortArr(arr, n);
    return 0;
}

// Do phuc tap thoi gian cua doan ma nay la O(n^2)
// Do phuc tap bo nho cua doan ma nay la O(1)
