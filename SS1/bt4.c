//
// Created by Admin on 16/06/2025.
//
#include <stdio.h>

int sum_1(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Do phuc tap thoi gian cua doan ma nay la O(n)
// Do phuc tap bo nho cua doan ma nay la O(1)

// c2

int sum_2(int n) {
    return n * (n + 1) / 2;
}

// Do phuc tap thoi gian cua doan ma nay la O(1)
