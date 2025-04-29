#include <iostream>
using namespace std;

int main() {
    float value1, value2;
    char op;

    // Input values
    cout << "Enter first number: ";
    cin >> value1;

    cout << "Enter second number: ";
    cin >> value2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    // Perform operation based on the operator
    switch(op) {
        case '+':
            cout << "Result: " << value1 + value2 << endl;
            break;
        case '-':
            cout << "Result: " << value1 - value2 << endl;
            break;
        case '*':
            cout << "Result: " << value1 * value2 << endl;
            break;
        case '/':
            if (value2 != 0)
                cout << "Result: " << value1 / value2 << endl;
            else
                cout << "Can't do that Dave." << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
    }

    return 0;
}
