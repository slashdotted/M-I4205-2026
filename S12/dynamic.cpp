#include <iostream>
using namespace std;

class Base {
public:
  virtual void speak() { cout << "Base::speak" << endl; }
};

class Derived : public Base {
public:
  void onlyDerived() { cout << "Metodo solo Derived: pi=" << m_pi << endl; }

private:
  double m_pi{3.1415};
};

bool isDerived(void *ptr) {
  // void is not a polymorphic class
  /*if (dynamic_cast<Derived *>(ptr)) {
    return true;
  }*/
  return false;
}

// "instanceof Derived"
bool isDerived(Base *ptr) {
  if (dynamic_cast<Derived *>(ptr)) {
    return true;
  }
  return false;
}

// "instanceof Derived"
bool isDerived(Base &b) {
  try {
    auto t = dynamic_cast<Derived &>(b);
    return true;
  } catch (...) {
    return false;
  }
}

int main() {
  {
    Base *b1{new Derived()};
    Base *b2{new Base()};

    Derived *d1 = dynamic_cast<Derived *>(b1);
    d1->onlyDerived();

    Derived *d2 = dynamic_cast<Derived *>(b2);
    // if the cast is not valid we get nullptr
    if (d2) { // check if d2 is not nullptr
      d2->onlyDerived();
    }

    // Emulating instance of
    if (dynamic_cast<Derived *>(b2)) {
      // "b2 instanceof Derived"
    }

    delete b1;
    delete b2;
  }
  {
    Derived b1;
    Base b2;

    Derived &d1 = dynamic_cast<Derived &>(b1);
    d1.onlyDerived();

    try {
      Derived &d2 = dynamic_cast<Derived &>(b2);
      d2.onlyDerived();
    } catch (const std::bad_cast &e) {
      // Invalid cast
    }
  }
  return 0;
}
