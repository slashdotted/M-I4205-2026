#include <iostream>

// Final (for classes and structs)

struct Base {};

struct Derived final : public Base {};

/*struct Eeee : public Derived {

};*/

// Final (for polymorphic methods)
struct Alpha {
  virtual void doSomething() = 0;
};

struct Beta : public Alpha {
  void doSomething() override final {}
};

struct Eta : public Beta {
  // Error! Final method cannot be overridden
  // void doSomething() override {
  //}
};

int main() { std::cout << "Hello world\n"; }
