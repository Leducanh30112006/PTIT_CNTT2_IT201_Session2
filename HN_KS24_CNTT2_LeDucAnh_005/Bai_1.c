#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id; // Mã sách
    char title[100]; // Tên sách
    char author[100]; // Tác giả
    char category[50]; // Thể loại
    float price; // Giá sách
} Book;

typedef struct BookNode {
    Book data;
    struct BookNode *next;
} BookNode;

typedef struct ReadBookNode {
    Book data;
    struct ReadBookNode *prev;
    struct ReadBookNode *next;
} ReadBookNode;

int main() {
    BookNode *bookList = NULL;
    ReadBookNode *readList = NULL;
    int choice, id;
    char title[100];

    do {
        printf("Menu:\n");
        printf("1: Them sach\n");
        printf("2: Hien thin danh sach tat ca quyen sach\n");
        printf("3: Xoa Sach \n");
        printf("4: Cap nhat thong tin mot quyen sach \n");
        printf("5: Danh dau sach da doc \n");
        printf("6: Sap xep theo gia tang dan \n");
        printf("7: Tim kiem sach theo tieu de \n");
        printf("8: Thoat chuong trinh \n");
        printf("Chon chuc nagn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook(&bookList);
                break;
            case 2:
                displayBooks(bookList);
                break;
            case 3:
                printf("Nhap id sach can xoa: ");
                scanf("%d", &id);
                deleteBook(&bookList, id);
                break;
            case 4:
                printf("Nhap Id sach can cap nhat: ");
                scanf("%d", &id);
                updateBook(bookList, id);
                break;
            case 5:
                printf("Nhap id sach da doc: ");
                scanf("%d", &id);
                markAsRead(&bookList, &readList, id);
                break;

            case 6:
                sortBooksByPrice(&bookList);
                printf("Da sap xep theo gia tang dan \n");
                break;
            case 7:
                printf("Nhap tieu de sach can tim: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                searchBook(bookList, title);
                break;

            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Chuc nang khong hop le\n");
        }
    } while (choice != 8);

    BookNode *tmp;
    while (bookList) {
        tmp = bookList;
        bookList = bookList->next;
        free(tmp);
    }
    ReadBookNode *rtmp;
    while (readList) {
        rtmp = readList;
        readList = readList->next;
        free(rtmp);
    }
    return 0;
}

void addBook(BookNode **head) {
    BookNode *newNode = (BookNode *) malloc(sizeof(BookNode));
    printf("NHap ma sach: ");
    scanf("%d", &newNode->data.id);
    getchar();
    printf("Nhap ten sach: ");
    fgets(newNode->data.title, 100, stdin);
    newNode->data.title[strcspn(newNode->data.title, "\n")] = 0;
    printf("Nhap ten tac gia : ");
    fgets(newNode->data.author, 100, stdin);
    newNode->data.author[strcspn(newNode->data.author, "\n")] = 0;
    printf("Nhap the loai: ");
    fgets(newNode->data.category, 50, stdin);
    newNode->data.category[strcspn(newNode->data.category, "\n")] = 0;
    printf("Nhap gia sach: ");
    scanf("%f", &newNode->data.price);
    getchar();
    newNode->next = *head;
    *head = newNode;
    printf("Da them sach thanh cong\n");
}

void displayBooks(BookNode *head) {
    printf("\nDanh sach tat ca cac quyen sach:\n");
    while (head) {
        printf("ID: %d | Ten sach: %s | Tac gia: %s | The loai: %s | Gia: %.0f\n",
               head->data.id, head->data.title, head->data.author, head->data.category, head->data.price);
        head = head->next;
    }
}

void deleteBook(BookNode **head, int id) {
    BookNode *curr = *head, *prev = NULL;
    while (curr && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        printf("khong tim thay sach co id nay\n");
        return;
    }
    if (prev) prev->next = curr->next;
    else *head = curr->next;
    free(curr);
    printf("Da xoa sach\n");
}

void updateBook(BookNode *head, int id) {
    while (head && head->data.id != id) head = head->next;
    if (!head) {
        printf("khong tim thay sach co id nay\n");
        return;
    }
    printf("Nhap ten moi: ");
    getchar();
    fgets(head->data.title, 100, stdin);
    head->data.title[strcspn(head->data.title, "\n")] = 0;
    printf("Nhap tac gia moi : ");
    fgets(head->data.author, 100, stdin);
    head->data.author[strcspn(head->data.author, "\n")] = 0;
    printf("Nhap the loai mơi : ");
    fgets(head->data.category, 50, stdin);
    head->data.category[strcspn(head->data.category, "\n")] = 0;
    printf("Nhap gia moi: ");
    scanf("%f", &head->data.price);
    printf("Da cap nhat thong tin sach\n");
}

void markAsRead(BookNode **head, ReadBookNode **readHead, int id) {
    BookNode *curr = *head, *prev = NULL;
    while (curr && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        printf("Khong tim thay sach co id nay\n");
        return;
    }
    if (prev) prev->next = curr->next;
    else *head = curr->next;
    ReadBookNode *newNode = (ReadBookNode *) malloc(sizeof(ReadBookNode));
    newNode->data = curr->data;
    newNode->prev = NULL;
    newNode->next = *readHead;
    if (*readHead) (*readHead)->prev = newNode;
    *readHead = newNode;
    free(curr);
    printf("Da danh dau sach da doc xong \n");
}

void sortBooksByPrice(BookNode **head) {
    if (!*head || !(*head)->next) return;
    int swapped;
    BookNode *ptr1, *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data.price > ptr1->next->data.price) {
                Book temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void searchBook(BookNode *head, const char *title) {
    int found = 0;
    while (head) {
        if (strstr(head->data.title, title)) {
            printf("ID: %d | Ten sach: %s | Tac gia: %s | The loai: %s | Gia: %.0f\n",
                   head->data.id, head->data.title, head->data.author, head->data.category, head->data.price);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("Khong tim thay sach voi tieu de nay \n");
}
