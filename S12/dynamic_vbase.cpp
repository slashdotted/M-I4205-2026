class A {
public:
    virtual ~A() {}
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    B b;
    A* a{&b};
    B* c{static_cast<B*>(a)};
}
