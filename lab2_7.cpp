#include <iostream>
using namespace std;

int main() {
    int x = 100;
    int* p1 = &x;
    int* p2 = p1;

    cout << "Original value of x: " << x << endl;
    cout << "Value via p1: " << *p1 << endl;
    cout << "Value via p2: " << *p2 << endl;

    *p1 = 200;

    cout << "\nAfter modifying through p1:" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value via p1: " << *p1 << endl;
    cout << "Value via p2: " << *p2 << endl;

    *p2 = 300;

    cout << "\nAfter modifying through p2:" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value via p1: " << *p1 << endl;
    cout << "Value via p2: " << *p2 << endl;

    return 0;
}
