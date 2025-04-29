#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int array1[size] = {1, 4, 7, 10, 15};
    int array2[size];

    int* ptr = array1 + size - 1;
    int* dest = array2;

    for (int i = 0; i < size; ++i) {
        *(dest + i) = *(ptr - i);
    }

    cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        cout << *(dest + i) << " ";
    }
    cout << endl;

    return 0;
}
