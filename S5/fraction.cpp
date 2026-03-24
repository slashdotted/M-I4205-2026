#include "fraction.h"

Fraction operator+(Fraction a, const Fraction &b) { return a += b; }

Fraction::Fraction(int numerator, int denominator)
    : m_numerator{numerator}, m_denominator{denominator} {}

void Fraction::num(int numerator) { m_numerator = numerator; }
void Fraction::den(int denominator) { m_denominator = denominator; }

Fraction &Fraction::operator+=(const Fraction &b) {
  int temp_numerator{b.m_numerator * m_denominator};
  m_denominator *= b.m_denominator;
  m_numerator *= b.m_denominator;
  m_numerator += temp_numerator;
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &b) {
  int temp_numerator{b.m_numerator * m_denominator};
  m_denominator *= b.m_denominator;
  m_numerator *= b.m_denominator;
  m_numerator += temp_numerator;
  return *this;
}

/*Fraction Fraction::operator+(const Fraction &b) {
  Fraction f{*this};
  f += b;
  return f;
}*/

Fraction Fraction::operator-(const Fraction &b) {
  Fraction f{*this};
  f -= b;
  return f;
}
