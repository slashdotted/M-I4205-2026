class A {
public:
  virtual ~A() {}
};

class B : public virtual A {};
class C : public virtual A {};
class D : public B, public C {};

int main() {
  B b;
  A *a{&b};
  B *c{dynamic_cast<B *>(a)};
}
