#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int namSinh;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->namSinh = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->namSinh)
        root->left = insert(root->left, x);
    else if (x > root->namSinh)
        root->right = insert(root->right, x);

    return root;
}

// In cây theo dạng trực quan
void printTree(Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->namSinh);

    printTree(root->left, space);
}

int main() {
    int a[] = {2001, 2002, 2006, 2007, 2008,
               2004, 2005, 2001, 1999, 2004};

    int n = sizeof(a) / sizeof(a[0]);
    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Cay BST:\n");
    printTree(root, 0);

    return 0;
}
