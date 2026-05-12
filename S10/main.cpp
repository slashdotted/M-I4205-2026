#include <iostream>

// ***********************************
// Overloading
// ***********************************

namespace overloading {

void fun() {}

void fun(int) {}

// Not an overload
// int fun() {
//}

struct MyType {
  void m() {}
  void m(int) {}
};

} // namespace overloading

// ***********************************
// Override
// ***********************************

namespace overriding {

struct Super {
  void a() { std::cout << "Super::a\n"; }
};

struct Base : public Super {
  virtual void a() { std::cout << "Base::a\n"; }
};

struct Derived : public Base {
  void a() override { std::cout << "Derived::a\n"; };
};

} // namespace overriding

// ***********************************
// Hiding
// ***********************************

namespace hiding {

struct Super {
  void a() { std::cout << "Super::a\n"; }
};

struct Base : public Super {
  virtual void a() { std::cout << "Base::a()\n"; }

  virtual void a(std::string d) { std::cout << "Base::a(std::string)\n"; }
};

struct Derived : public Base {
  // This method hides Base::a
  void a(int) { std::cout << "Base::a\n"; }
};

struct DerivedNoHiding : public Base {
  using Base::a;

  // "Non-solution": override all "a" from the base class
  void a() override { Base::a(); }

  void a(int) { std::cout << "Base::a\n"; }
};

} // namespace hiding

int main() {
  using namespace hiding;
  Derived d;
  // d.a();
}
