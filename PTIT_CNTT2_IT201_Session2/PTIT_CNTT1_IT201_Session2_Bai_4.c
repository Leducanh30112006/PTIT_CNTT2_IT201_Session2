//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int pos, newValue;
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
        printf("Nhap vi tri muon sua (tu 0 den %d): ", n - 1);
        scanf("%d", &pos);
    } while (pos < 0 || pos >= n);
    printf("Nhap gia tri moi tai vi tri %d: ", pos);
    scanf("%d", &newValue);
    arr[pos] = newValue;
    printf("Mang sau khi cap nhat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
