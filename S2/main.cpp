#include <iostream>

void wrong() {
    int *i{new int};
    //...
    if (1) {
        return;
    }
    delete i;
}

void right() {
    int i;
    if (1) {
        return;
    }
}


void increment_by_one_by_value(int n) {
    ++n; // n is a copy
}

void increment_by_one_by_ptr(int *n) {
    ++(*n); // n is a copy of the pointer
}

void increment_by_one_by_ref(int& n) {
    ++n; // n is a reference
}

void print_by_value(int n) {
    std::cout << n << std::endl;
}

void print_by_ptr(int *n) {
    std::cout << *n << std::endl;
}

void print_by_ref(const int& n) {
    std::cout << n << std::endl;
}

int get_value() {
    return 42;
}


int main() {
    using namespace std;

    // Allocating on the stack
    int a;
    double b;
    cout << "Address of a=" << (long) &a << " sizeof(a)=" << sizeof(a) << endl;
    cout << "Address of b=" << (long) &b << " sizeof(b)=" << sizeof(b) << endl;
    int *d{&a};

    // Allocating on the heap

    // C way
    int *e = (int*) malloc(sizeof(int));
    // e is on the stack, but points to memory on the heap
    *e=13;
    free(e);

    // C++
    int *c{new int{13}};
    // c in on the stack, but points to memory on the heap
    cout << "Address of c=" << (long) &c << " sizeof(c)=" << sizeof(c) << endl;
    delete c;
    c = new int{89};
    delete c;

    {
        int z;
        // z goes out of scope
    }

    // C++ arrays
    double *ad{new double[10]};
    delete[] ad; // we use delete[] for arrays

    int number{0};
    cout << "number=" << number << endl;
    increment_by_one_by_value(number);
    // number is not incremented
    cout << "number=" << number << endl;
    increment_by_one_by_ptr(&number);
    // number should be 1
    cout << "number=" << number << endl;
    increment_by_one_by_ref(number);
    cout << "number=" << number << endl;
    // number should be 2


    increment_by_one_by_value(42);
    //increment_by_one_by_ptr(42);
    //increment_by_one_by_ref(42);
    //increment_by_one_by_ref(get_value());

    print_by_value(42);
    //print_by_ptr(42);
    print_by_ref(42);
    print_by_ref(get_value());


    // References
    int t{4};
    int& w{t};

    cout << "&t=" << &t << endl;
    cout << "&w=" << &w << endl;


    int myarray[] {1,2,3,4,5};
    for (int t{0}; t<5; ++t) {
        cout << myarray[t] << endl;
    }
    for (int& t : myarray) {
        cout << t << endl;
    }
    cout << "===============\n";
    for (int& t : myarray) {
        cout << ++t << endl;
    }
    cout << "===============\n";
    for (int& t : myarray) {
        cout << t << endl;
    }

    return 0;
}
