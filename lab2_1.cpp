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
