#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* Taovong(int N) {
    if (N <= 0) return NULL;

    Node *head = NULL, *temp, *vong = NULL;
    int i;

    for (i = 1; i <= N; i++) {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) exit(1);

        temp->data = i;
        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else
            vong->next = temp;

        vong = temp;
    }

    vong->next = head;
    return head;
}

int Timnguoi(int N, int M) {
    if (N <= 0 || M <= 0) return -1;

    Node* hien_tai = Taovong(N);
    if (hien_tai == NULL) return -1;

    Node* vong = hien_tai;

    while (vong->next != hien_tai)
        vong = vong->next;

    while (hien_tai->next != hien_tai) {
        int i;
        for (i = 1; i < M; i++) {
            vong = hien_tai;
            hien_tai = hien_tai->next;
        }

        vong->next = hien_tai->next;
        free(hien_tai);
        hien_tai = vong->next;
    }

    int winner = hien_tai->data;
    free(hien_tai);
    return winner;
}
int main() {
    int N = 10;

    printf("M=1: %d\n", Timnguoi(N,1));
    printf("M=2: %d\n", Timnguoi(N,2));
    printf("M=3: %d\n", Timnguoi(N,3));

    return 0;
}