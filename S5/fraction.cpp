#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
    : m_numerator{numerator}, m_denominator{denominator} {}

void Fraction::num(int numerator) { m_numerator = numerator; }
void Fraction::den(int denominator) { m_denominator = denominator; }
