#include <stdio.h>

int *malloc(int n) {
    int *p = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }

    return arr;
}

// Do phuc tap thoi gian cua doan ma nay la O(n)
