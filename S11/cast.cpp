#include <iostream>
#include <string>

struct Base {
  int valore;
};

struct Derivata : public Base {
  double data;
};

struct DoppiaDerivata : public Derivata {
  std::string nome;
};

void foo(const Base &b) {}

void foo(Base *b) {}

int main() {
  Base b;
  Derivata d;
  DoppiaDerivata dd;

  DoppiaDerivata *ptr_dd{&dd};
  Derivata *ptr_d{&d};

  DoppiaDerivata &ref_dd{dd};
  Derivata &ref_d{d};

  foo(d);  // upcast
  foo(dd); // upcast

  foo(&d);  // upcast
  foo(&dd); // upcast

  d.valore = 67;
  d.data = 42;
  Base *d_b{&d};
  // Derivata* p = (Derivata*) d_b;
  Derivata *p = static_cast<Derivata *>(d_b);
  DoppiaDerivata *ddp = static_cast<DoppiaDerivata *>(d_b);
  std::cout << "valore=" << ddp->valore << '\n'
            << "data=" << ddp->data << '\n'
            << '\n'
            << "nome=" << ddp->nome << '\n';
}
