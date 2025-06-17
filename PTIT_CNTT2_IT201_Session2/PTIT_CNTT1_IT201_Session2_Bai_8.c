//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n, arr[100];
    do {
        printf("Nhap so phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu lon hon cac phan tu dung sau no :\n");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                count++;
            }
        }
        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}
