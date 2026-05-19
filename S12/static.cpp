#include <iostream>
using namespace std;

class Base {
public:
  void speak() { cout << "Base::speak" << endl; }
};

class Derived : public Base {
public:
  void onlyDerived() { cout << "Metodo solo Derived: pi=" << m_pi << endl; }

private:
  double m_pi{3.1415};
};

int main() {
  {
    Base *b1{new Derived()};
    Base *b2{new Base()};

    Derived *d1 = static_cast<Derived *>(b1);
    d1->onlyDerived();

    Derived *d2 = static_cast<Derived *>(b2);
    d2->onlyDerived();

    delete b1;
    delete b2;
  }
  {
    Derived b1;
    Base b2;

    Derived &d1 = static_cast<Derived &>(b1);
    d1.onlyDerived();

    Derived &d2 = static_cast<Derived &>(b2);
    d2.onlyDerived();
  }
  return 0;
}
