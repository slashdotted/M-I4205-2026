#include "fraction.h"
#include <iostream>

using namespace std;

Fraction operator+(const Fraction &a, const Fraction &b) {
  Fraction temp{a};
  temp += b;
  return temp;
}

ostream &operator<<(ostream &o, const Fraction &f) {
  o << f.num() << "/" << f.den();
  return o;
}

int main() {
  Fraction p{9, 6};
  Fraction q{2, 3};
  int i{0};
  i += 7;
  p += q;
  p.operator+=(q);
  p + q; // p.operator+
  p + 5; // p.operator+(5) => p.operator+(Fraction{5})
  5 + p; // operator+(5,p) => operator(Fraction{5},p)$
  std::cout << p << "hello";
}
