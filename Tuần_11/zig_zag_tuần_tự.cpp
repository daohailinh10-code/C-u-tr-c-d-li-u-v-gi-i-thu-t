#include <iostream>
using namespace std;

int main() {

    char tree[20] = {};

    tree[1] = 'A';
    tree[2] = 'B';
    tree[5] = 'C';
    tree[10] = 'D';

    cout << "Cay zigzag:\n";

    cout << "1  : " << tree[1] << endl;
    cout << "2  : " << tree[2] << endl;
    cout << "5  : " << tree[5] << endl;
    cout << "10 : " << tree[10] << endl;

    return 0;
}
