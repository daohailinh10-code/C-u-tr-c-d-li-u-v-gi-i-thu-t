#include <iostream>
using namespace std;

int main() {

    char tree[20] = {};

    tree[1] = 'A';
    tree[3] = 'B';
    tree[7] = 'C';
    tree[15] = 'D';

    cout << "Cay lech phai:\n";

    cout << "1 : " << tree[1] << endl;
    cout << "3 : " << tree[3] << endl;
    cout << "7 : " << tree[7] << endl;
    cout << "15 : " << tree[15] << endl;

    return 0;
}