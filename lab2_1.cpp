#include <iostream>
#include <cmath>
using namespace std;

int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

int multiply(int a, double b, bool roundFlag) {
    double result = a * b;
    return roundFlag ? static_cast<int>(round(result)) : static_cast<int>(result);
}

int main() {

    cout << "multiply(3, 4) = " << multiply(3, 4) << endl;

    // B. Double multiplication
    cout << "multiply(2.5, 4.2) = " << multiply(2.5, 4.2) << endl;

    // C. Integer and double multiplication with round flag
    cout << "multiply(3, 2.7, false) = " << multiply(3, 2.7, false) << endl; // Output: 8
    cout << "multiply(3, 2.7, true) = " << multiply(3, 2.7, true) << endl;  // Output: 8

    cout << "multiply(3, 2.3, false) = " << multiply(3, 2.3, false) << endl; // Output: 6
    cout << "multiply(3, 2.3, true) = " << multiply(3, 2.3, true) << endl;  // Output: 7

    return 0;
}
