#pragma once

// Here we can use "class Fraction"
// by default everything in struct is public
// by default everything in class is private
struct Fraction {

  // public: // can be omitted since struct is by default public
  /*explicit*/ Fraction(int numerator = 0, int denominator = 1);
  // Since Fraction(int) is
  // a constructor for this class
  // it can be used to automatically convert
  // an int to a Fraction (whenever necessary)
  // => conversion constructor
  // if we use "explicit", this automatic
  // conversion does not happen
  // (we are forced to explicitly convert an
  // integer to a Fraction)

  // Fraction();
  // Fraction(int numerator);
  // Declarations
  // The implementation goes in the C++ file
  void num(int numerator);
  void den(int denominator);

  // Declarations and implementations
  // Methods will be inline
  /*void num(int numerator) {
    m_numerator = numerator;
    // same as
    // this->m_numerator = numerator;
  }
  void den(int denominator) { m_denominator = denominator; }*/

  // Getters
  // (inline methods)
  int num() const { return m_numerator; }
  int den() const {
    int temp{m_denominator};
    ++temp;
    /* Assignment is not possible because of const */
    // m_numerator = 76;
    return m_denominator;
  }

protected:
private:
  // Initializing the fields
  int m_numerator{0}, m_denominator{1};
};
