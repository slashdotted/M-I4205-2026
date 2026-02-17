#include <iostream>

double get_a() {
    return 42.5;
}

int get_b() {
    return 17;
}

/*int somma(int a, int b) {
    return a+b;
}*/

// In C++ gli argomenti possono avere
// un valore predefinito
int somma(int a, int b, int c=0, int d=0) {
    return a+b+c+d;
}

/*int somma(int a, int b) {
    return somma(a,b,0);
}*/

int main() {
    int x;
    x = 5;
    x = 3.14; // Narrowing conversion
    //int pi{3.14}; // Errore!
    double pi{3.14};
    //x{7}; // Errore! Non posso reinizializzare la variabile con {}
    auto e{2.6};
    auto messaggio{"ciao mondo"};
    auto sum{get_a() + get_b()};
    //auto valore; // Errore! Se uso auto devo inizializzare la variabile
    std::cout << somma(5,6) << '\n';
    std::cout << somma(5,6,7) << '\n';
}
