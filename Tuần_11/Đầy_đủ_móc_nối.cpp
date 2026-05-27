#include <iostream>

using namespace std;

struct Node {

    char data;

    Node* left;
    Node* right;
};

Node* taoNode(char x) {

    Node* p = new Node;

    p->data = x;

    p->left = NULL;
    p->right = NULL;

    return p;
}

void preorder(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main() {

    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    Node* E = taoNode('E');
    Node* F = taoNode('F');

    A->left = B;
    A->right = C;

    B->left = D;
    B->right = E;

    C->left = F;

    cout << "CAY DAY DU:\n";

    preorder(A);

    return 0;
}