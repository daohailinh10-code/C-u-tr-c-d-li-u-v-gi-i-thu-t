#include <iostream>
using namespace std;

int main() {

    char tree[10];

    tree[1] = 'A';
    tree[2] = 'B';
    tree[3] = 'C';
    tree[4] = 'D';
    tree[5] = 'E';
    tree[6] = 'F';

    cout << "Cay day du:\n";

    for (int i = 1; i <= 6; i++) {

        cout << "tree[" << i << "] = "
             << tree[i] << endl;
    }

    return 0;
}