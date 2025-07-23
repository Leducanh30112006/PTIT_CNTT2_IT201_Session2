#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *graph[], int firstNode, int secondNode) {
    if (firstNode == secondNode) return;
    for (int i = 3; i >= 0; i--) {
        if (i == firstNode) {
            Node *newNode = createNode(secondNode);
            newNode->next = graph[i];
            graph[i] = newNode;
            return;
        }
    }
}

int main() {
    Node *graph[3] = {NULL,NULL,NULL};
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 1);
    printf("Input 1: \n");
    for (int i = 0; i < 3; i++) {
        Node *temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 0);
    printf("\nInput 2: \n");
    for (int i = 0; i < 3; i++) {
        Node *temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}
