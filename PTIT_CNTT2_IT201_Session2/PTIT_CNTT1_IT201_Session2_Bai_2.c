//
// Created by Admin on 17/06/2025.
//
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int x;

    do {
        printf("nhap so phan tu cua mang (1-100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    if (count == 0) {
        printf("so %d khong co trong mang\n", x);
    } else {
        printf("so %d xuat hien %d lan trong mang\n", x, count);
    }


    return 0;
}
