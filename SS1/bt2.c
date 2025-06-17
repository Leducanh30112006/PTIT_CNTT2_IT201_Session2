#include <stdio.h>

void printdouble(int n) {
    int i = 1;
    while (i <= n) {
        printf("%d\n", i);
        i *= 2;
    }
}
// Do phuc tap thoi gian cua doan ma nay la O(log n)