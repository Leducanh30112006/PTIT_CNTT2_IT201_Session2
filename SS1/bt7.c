//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>
#define MAX 1001
//C1
int hasDueplicate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Do phuc tap thoi gian cua doan ma nay la O(n^2)
// Do phuc tap ko gian cua doan ma nay la O(1)
// C2
int hasDueplicate2(int arr[], int n) {
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1) {
            return 1;
        }
        hash[arr[i]] = 1;
    }
    return 0;
}

// Do phuc tap thoi gian cua doan ma nay la O(n)
// Do phuc tap ko gian cua doan ma nay la O(n)
