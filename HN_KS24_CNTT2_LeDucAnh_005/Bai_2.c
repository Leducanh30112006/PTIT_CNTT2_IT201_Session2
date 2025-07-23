#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char command[100];
    struct Node *next;
} Node;

// Stack sẽ là danh sách liên kết đơn
typedef struct Stack {
    Node *top;
} Stack;

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1: INSERT \n");
        printf("2: UNDO\n");
        printf("3: REDO \n");
        printf("4: HIEN THI\n");
        printf("5: Thoat chuong trinh \n");
        printf("Chon chuc nagn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Chuc nang khong hop le\n");
        }
    } while (choice != 5);
}
