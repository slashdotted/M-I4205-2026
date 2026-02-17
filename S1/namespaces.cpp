#include <iostream>
#include "mymath.h"

using namespace std;

int multiply(int a, int b) {
    return a*b;
}

void foo() {
    using namespace mydoublemath;
    cout << multiply(3.5,2.6) << endl;
}

int main() {
    using namespace mymath;
    cout << mymath::multiply(3,2) << endl;
}


