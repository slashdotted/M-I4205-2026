#pragma once

struct Fraction {
  Fraction(int numerator = 0, int denominator = 1);
  void num(int numerator);
  void den(int denominator);

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
