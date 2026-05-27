#include <iostream>
using namespace std;

int main() {

    char tree[20] = {};

    tree[1] = 'A';
    tree[2] = 'B';
    tree[4] = 'C';
    tree[8] = 'D';

    cout << "Cay lech trai:\n";

    cout << "1 : " << tree[1] << endl;
    cout << "2 : " << tree[2] << endl;
    cout << "4 : " << tree[4] << endl;
    cout << "8 : " << tree[8] << endl;

    return 0;
}