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
  // static_cast cannot pass through virtual inheritance
  // B* c{static_cast<B*>(a)};
}
