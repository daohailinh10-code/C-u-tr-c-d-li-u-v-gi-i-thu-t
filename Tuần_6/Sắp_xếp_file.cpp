#include <iostream>
#include <string>

using namespace std;

struct File {
    string tenFile;
    double kichThuoc;
    long long thoiGian;
};

struct Node {
    File data;
    Node* next;
};

struct List {
    Node* head;
};

void init(List &listFile) {
    listFile.head = NULL;
}

Node* taoNode(File x) {
    Node* p = new Node;

    p->data = x;
    p->next = NULL;

    return p;
}

void chenTheoThoiGian(List &listFile, File x) {
    Node* p = taoNode(x);

    // chen dau
    if (listFile.head == NULL ||
        x.thoiGian < listFile.head->data.thoiGian) {

        p->next = listFile.head;
        listFile.head = p;
        return;
    }

    Node* vitri = listFile.head;

    while (vitri->next != NULL &&
           vitri->next->data.thoiGian < x.thoiGian) {

        vitri = vitri->next;
    }

    p->next = vitri->next;
    vitri->next = p;
}

double tongKichThuoc(List listFile) {
    double sum = 0;

    Node* p = listFile.head;

    while (p != NULL) {
        sum += p->data.kichThuoc;
        p = p->next;
    }

    return sum;
}

Node* timMin(List listFile) {
    if (listFile.head == NULL)
        return NULL;

    Node* minNode = listFile.head;
    Node* p = listFile.head;

    while (p != NULL) {
        if (p->data.kichThuoc < minNode->data.kichThuoc)
            minNode = p;

        p = p->next;
    }

    return minNode;
}

void xoaNode(List &listFile, Node* fileCanXoa) {

    if (fileCanXoa == NULL || listFile.head == NULL)
        return;

    // xoa dau
    if (listFile.head == fileCanXoa) {
        listFile.head = listFile.head->next;
        delete fileCanXoa;
        return;
    }

    Node* p = listFile.head;

    while (p->next != NULL &&
           p->next != fileCanXoa) {

        p = p->next;
    }

    if (p->next == fileCanXoa) {
        p->next = fileCanXoa->next;
        delete fileCanXoa;
    }
}

void backupUSB(List &listFile) {

    while (tongKichThuoc(listFile) > 32000) {

        Node* minNode = timMin(listFile);

        xoaNode(listFile, minNode);
    }
}

void xuatDanhSach(List listFile) {

    Node* p = listFile.head;

    while (p != NULL) {

        cout << "Ten file: "
             << p->data.tenFile << endl;

        cout << "Kich thuoc: "
             << p->data.kichThuoc
             << " MB" << endl;

        cout << "Thoi gian: "
             << p->data.thoiGian << endl;

        cout << "------------------" << endl;

        p = p->next;
    }
}

int main() {

    List listFile;

    init(listFile);

    int n;

    cout << "Nhap so luong file: ";
    cin >> n;

    cin.ignore();

    int i;

    for (i = 0; i < n; i++) {

        File x;

        cout << "\nNhap ten file: ";
        getline(cin, x.tenFile);

        cout << "Nhap kich thuoc: ";
        cin >> x.kichThuoc;

        cout << "Nhap thoi gian: ";
        cin >> x.thoiGian;

        cin.ignore();

        chenTheoThoiGian(listFile, x);
    }

    cout << "\n===== DANH SACH FILE =====\n";

    xuatDanhSach(listFile);

    cout << "\nTong kich thuoc: "
         << tongKichThuoc(listFile)
         << " MB" << endl;

    backupUSB(listFile);

    cout << "\n===== SAU BACKUP =====\n";

    xuatDanhSach(listFile);

    cout << "\nTong sau backup: "
         << tongKichThuoc(listFile)
         << " MB" << endl;

    return 0;
}
