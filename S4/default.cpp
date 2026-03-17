struct Foo {
  Foo(int i) {}

  // Bringing back the default
  // constructor
  // Foo() {}
  Foo() = default;
};

int main() {
  Foo f;
  f = 9;
}
