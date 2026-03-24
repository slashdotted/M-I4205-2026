#pragma once

struct Fraction {
  /*explicit*/ Fraction(int numerator = 0, int denominator = 1);
  void num(int numerator);
  void den(int denominator);

  Fraction &operator+=(const Fraction &b);
  Fraction &operator-=(const Fraction &b);
  // Fraction operator+(const Fraction &b);
  Fraction operator-(const Fraction &b);

  // Prefix
  Fraction &operator++() { return *this += 1; }

  // Postfix
  Fraction operator++(int) {
    Fraction temp{*this};
    *this += 1;
    return temp;
  }

  operator double() const { return double(m_numerator) / m_denominator; }

  int num() const { return m_numerator; }
  int den() const {
    int temp{m_denominator};
    ++temp;
    return m_denominator;
  }

protected:
private:
  int m_numerator{0}, m_denominator{1};
};

Fraction operator+(Fraction a, const Fraction &b);
