#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;
};

int Height(Node *p) {
    return (p == NULL) ? 0 : p->height;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

Node* CreateNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

Node* RightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = Max(Height(y->left), Height(y->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;

    return x;
}

Node* LeftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = Max(Height(x->left), Height(x->right)) + 1;
    y->height = Max(Height(y->left), Height(y->right)) + 1;

    return y;
}

int Balance(Node *p) {
    if (p == NULL) return 0;
    return Height(p->left) - Height(p->right);
}

Node* Insert(Node *root, int x) {
    if (root == NULL)
        return CreateNode(x);

    if (x < root->data)
        root->left = Insert(root->left, x);
    else if (x > root->data)
        root->right = Insert(root->right, x);
    else
        return root;

    root->height = Max(Height(root->left), Height(root->right)) + 1;

    int bf = Balance(root);

    // LL
    if (bf > 1 && x < root->left->data)
        return RightRotate(root);

    // RR
    if (bf < -1 && x > root->right->data)
        return LeftRotate(root);

    // LR
    if (bf > 1 && x > root->left->data) {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    // RL
    if (bf < -1 && x < root->right->data) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
}

void NLR(Node *root) {
    if (root) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(Node *root) {
    if (root) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void LRN(Node *root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(a) / sizeof(a[0]);
    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = Insert(root, a[i]);

    cout << "NLR: ";
    NLR(root);

    cout << "\nLNR: ";
    LNR(root);

    cout << "\nLRN: ";
    LRN(root);

    return 0;
}
