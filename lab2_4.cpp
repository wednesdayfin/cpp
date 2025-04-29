#include <iostream>
using namespace std;

int main() {
    float number;

    while (true) {
        cout << "Enter a number: ";
        cin >> number;

        if (number < 0) {
            cout << "Negative number, exiting." << endl;
            break;
        }

        if (number == 0) {
            cout << "Zero" << endl;
            continue;
        }

        cout << "Square is " << number * number << endl;
    }

    return 0;
}
