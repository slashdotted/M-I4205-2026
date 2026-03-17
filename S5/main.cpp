#include "fraction.h"
#include <iostream>

using namespace std;

void print(const Fraction &f) { cout << f.num() << "/" << f.den() << endl; }

Fraction get_half() {
  // Fraction on the heap
  Fraction *g{new Fraction{8, 3}};
  // Fraction on the stack
  // initialized using the constructor
  Fraction f{8, 3};
  // f.num(8);
  // f.den(3);
  delete g;
  return f;
}

int main() {
  Fraction p{9};
  print(p);
  cout << "---------------\n";
  print(get_half());
  cout << "---------------\n";
  Fraction f1{0, 1}; // An object on the stack
  print(f1);
  cout << "---------------\n";
  // f1.numerator = 2;
  f1.num(2);
  // f1.denominator = 0;
  f1.den(0);
  print(f1);
  // f1.numerator = 7;
  f1.num(7);
  // f1.denominator = 3;
  f1.den(3);
  print(f1);

  Fraction t;
  t = 7;
  print(t);
  print(42);
}
