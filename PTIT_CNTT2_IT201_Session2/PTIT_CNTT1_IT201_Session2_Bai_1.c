//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    do {
        printf("nhap so phan tu cua mang (1-100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    int max = arr[0];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);


    return 0;
}
