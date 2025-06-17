//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n, arr[100], sum;
    int found = 0;
    do {
        printf("Nhap so phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("nhap tong can tim");
    scanf("%d", &sum);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("Tim thay hai phan tu %d va %d co tong bang %d\n", arr[i], arr[j], sum);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong tim thay hai phan tu co tong bang %d\n", sum);
    }
    return 0;
}
