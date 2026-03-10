#include "fraction.h"
#include <iostream>

Fraction::Fraction(int numerator, int denominator)
    // init-list, used to initialize the fields of the object
    : m_numerator{numerator}, m_denominator{denominator} {
  // std::cout << "Initial:" << m_numerator << "/" << m_denominator << '\n';
  // m_numerator = numerator;
  // m_denominator = denominator;
}

#ifdef SKIP
Fraction::Fraction() : Fraction{0, 1} {
  // Wrong!
  // Fraction{0, 1};
  // this creates a temporary object 0/1
}

Fraction::Fraction(int numerator) : Fraction{numerator, 1} {
  // Wrong!
  // Fraction{numerator, 1};
  // this creates a temporary object numerator/1
}
#endif

void Fraction::num(int numerator) { m_numerator = numerator; }
void Fraction::den(int denominator) { m_denominator = denominator; }
