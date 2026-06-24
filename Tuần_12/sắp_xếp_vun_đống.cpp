#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        cout << "Doi " << a[i]
             << " voi " << a[largest] << endl;

        swap(a[i], a[largest]);

        cout << "Trang thai: ";
        printArray(a, n);

        heapify(a, n, largest);
    }
}
void buildHeap(int a[], int n)
{
    cout << "===== TAO DONG =====" << endl;

    for (int i = n / 2; i >= 1; i--)
    {
        cout << endl;
        cout << "Vun dong tai i = "
             << i << endl;

        heapify(a, n, i);

        cout << "Sau buoc i = "
             << i << ": ";

        printArray(a, n);
    }
}

int main()
{
    int a[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    int n = 10;

    cout << "Mang ban dau: ";
    printArray(a, n);

    cout << endl;

    buildHeap(a, n);

    cout << endl;
    cout << "MAX HEAP: ";
    printArray(a, n);

    return 0;
}
