//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>

int countArr(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    int count = countArr(arr, n, x);
    printf("The number %d appears %d times in the array.\n", x, count);
    return 0;
}

//TG :O(n)
//KG :O(1)
