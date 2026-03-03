#include <iostream>
#include <vector>
#include <map>
#include <string>

void vector_examples() {
    using std::vector;
    using std::cout;

    vector<int> myvector;
    cout << "myvector.size()=" << myvector.size() << '\n';
    cout << "myvector.capacity()=" << myvector.capacity() << '\n';
    myvector.push_back(9);
    cout << "myvector.size()=" << myvector.size() << '\n';
    cout << "myvector.capacity()=" << myvector.capacity() << '\n';
    for(int i{0}; i<10; ++i) {
        myvector.push_back(i);
        cout << "myvector.size()=" << myvector.size() << '\n';
        cout << "myvector.capacity()=" << myvector.capacity() << '\n';
    }
    int value{myvector[0]}; // we get the first element
    for(const int& v : myvector) {
        cout << v << '\n';
    }
    myvector.erase(myvector.begin() + 6);
    myvector.clear();

    int number{42};
    myvector.push_back(number);

    //cout << "Non existing element " << myvector[1] << '\n';
    //cout << "Non existing element " << myvector.at(1) << '\n';

    vector<int*> myptrvector;
    myptrvector.push_back(new int{13});
    for(auto& p : myptrvector) {
        delete p;
    }
    myptrvector.clear();
    vector<double> myvector2 {3.14, 2.6, 3.7};
}

void map_examples() {
    using std::map;
    using std::cout;
    using std::string;

    map<string,double> mymap;
    mymap["pi"] = 3.14;
    cout << mymap["pi"] << '\n';
    // Don't do that: it will alllocate a value for "e"
    //if (mymap["e"] != 0) {
    //
    //}
    if (mymap.count("e")) {
        // "e" exists
    }
    mymap.erase("pi");
}

void exception_examples() /*noexcept*/ {
    int *x{new int{99}};
    try {
        throw "error!"; // in C++ you can throw any type
    } catch (int v) {
        std::cout << "Catching int exception " << v << '\n';
    } catch (double v) {
        std::cout << "Catching double exception " << v << '\n';
    } catch (...) {
        delete x;
        throw;
    }
    delete x;
}

int main() {
    //vector_examples();
    //map_examples();
    try {
        exception_examples();
    } catch (const char *m) {
        std::cout << "Got " << m << '\n';
    }
}
