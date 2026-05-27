#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ngay {
    int ngay, thang, nam;
} Ngay;

typedef struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
} SinhVien;

typedef struct Node {
    SinhVien data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

void initList(List *l) {
    l->head = NULL;
}

Node* createNode(SinhVien sv) {
    Node *p = (Node*)malloc(sizeof(Node));

    p->data = sv;
    p->next = NULL;

    return p;
}

int cmpMaSV(char *a, char *b) {
    return strcmp(a, b);
}

void insertSorted(List *l, SinhVien sv) {

    Node *p = createNode(sv);

    // chen dau
    if (l->head == NULL ||
        cmpMaSV(sv.maSV, l->head->data.maSV) < 0) {

        p->next = l->head;
        l->head = p;
        return;
    }

    Node *cur = l->head;

    while (cur->next != NULL &&
           cmpMaSV(cur->next->data.maSV, sv.maSV) < 0) {

        cur = cur->next;
    }

    p->next = cur->next;
    cur->next = p;
}

int soSanhNgay(Ngay a, Ngay b) {

    return (a.ngay == b.ngay &&
            a.thang == b.thang &&
            a.nam == b.nam);
}

void nhapDanhSach(List *l, int n) {

    int i;

    for (i = 0; i < n; i++) {

        SinhVien sv;

        printf("\nNhap SV thu %d:\n", i + 1);

        printf("Ma SV: ");
        scanf("%s", sv.maSV);

        getchar();

        printf("Ho ten: ");
        fgets(sv.hoTen, 50, stdin);
        sv.hoTen[strcspn(sv.hoTen, "\n")] = 0;

        printf("Gioi tinh (0-Nu,1-Nam): ");
        scanf("%d", &sv.gioiTinh);

        printf("Ngay sinh (d m y): ");
        scanf("%d %d %d",
              &sv.ngaySinh.ngay,
              &sv.ngaySinh.thang,
              &sv.ngaySinh.nam);

        getchar();

        printf("Dia chi: ");
        fgets(sv.diaChi, 100, stdin);
        sv.diaChi[strcspn(sv.diaChi, "\n")] = 0;

        printf("Lop: ");
        scanf("%s", sv.lop);

        printf("Khoa: ");
        scanf("%s", sv.khoa);

        insertSorted(l, sv);
    }
}

void inDanhSach(List l) {

    Node *p = l.head;

    while (p != NULL) {

        printf("%s | %s | %d | %02d/%02d/%d | %s | %s | %s\n",
               p->data.maSV,
               p->data.hoTen,
               p->data.gioiTinh,
               p->data.ngaySinh.ngay,
               p->data.ngaySinh.thang,
               p->data.ngaySinh.nam,
               p->data.diaChi,
               p->data.lop,
               p->data.khoa);

        p = p->next;
    }
}

int demNgaySinh(List l, Ngay ngay) {

    int count = 0;

    Node *p = l.head;

    while (p != NULL) {

        if (soSanhNgay(p->data.ngaySinh, ngay))
            count++;

        p = p->next;
    }

    return count;
}

void inSVTrungNgaySinh(List l) {

    Node *p = l.head;

    int found = 0;

    while (p != NULL) {

        if (demNgaySinh(l, p->data.ngaySinh) > 1) {

            printf("%s | %s\n",
                   p->data.maSV,
                   p->data.hoTen);

            found = 1;
        }

        p = p->next;
    }

    if (!found)
        printf("Khong co SV trung ngay sinh\n");
}

void xoaTheoNgaySinh(List *l, Ngay ngay) {

    while (l->head != NULL &&
           soSanhNgay(l->head->data.ngaySinh, ngay)) {

        Node *tmp = l->head;

        l->head = l->head->next;

        free(tmp);
    }

    Node *p = l->head;

    while (p != NULL && p->next != NULL) {

        if (soSanhNgay(p->next->data.ngaySinh, ngay)) {

            Node *tmp = p->next;

            p->next = tmp->next;

            free(tmp);

        } else {

            p = p->next;
        }
    }
}

void xoaSVTrungNgaySinh(List *l) {

    Node *p = l->head;

    while (p != NULL) {

        if (demNgaySinh(*l, p->data.ngaySinh) > 1) {

            Ngay ngay = p->data.ngaySinh;

            xoaTheoNgaySinh(l, ngay);

            p = l->head;

        } else {

            p = p->next;
        }
    }
}

int main() {

    List l;

    initList(&l);

    int n;

    printf("Nhap so SV: ");
    scanf("%d", &n);

    nhapDanhSach(&l, n);

    printf("\n===== DANH SACH =====\n");
    inDanhSach(l);

    printf("\n===== SV TRUNG NGAY SINH =====\n");
    inSVTrungNgaySinh(l);

    xoaSVTrungNgaySinh(&l);

    printf("\n===== SAU KHI XOA =====\n");
    inDanhSach(l);

    return 0;
}