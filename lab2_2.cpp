#include <iostream>
#include <cmath>
using namespace std;

void swap(float a, float b) {
    float temp = a;
    a = b;
    b = temp;

    std::cout << "a:" << a << ", b = " << b << std::endl;
}

void swapPointers(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapReferences(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    swap(2,4);
    swapPointers(float* a, float* b);
    swapReferences(float& a, float& b);
    return 0;
}
