//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int pos;
    do {
        printf("Nhap so phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    do {
        printf("Nhap vi tri muon xoa (tu 0 den %d): ", n - 1);
        scanf("%d", &pos);
    } while (pos < 0 || pos >= n);

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
