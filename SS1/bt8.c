//
// Created by Admin on 16/06/2025.
//

#include <stdio.h>
#define MAX_VAL 100

int findMostFrequent(int arr[], int n) {
    int count[MAX_VAL + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int maxFreq = 0;
    int mostVal = arr[0];

    for (int i = 0; i <= MAX_VAL; i++) {
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            mostVal = i;
        }
    }

    printf("Phan tu xuat hien nhieu nhat la: %d (xuat hien %d lan)\n", mostVal, maxFreq);
    return mostVal;
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 5, 3, 1}; // Mảng mẫu
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findMostFrequent(arr, n);

    return 0;
}

// Do phuc tap thoi gian cua doan ma nay la O(n)
// Do phuc tap ko gian cua doan ma nay la O(n)
