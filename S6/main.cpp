#include <functional>
#include <iostream>

void print(int i, const std::string &header = "--- value ---") {
  std::cout << header << std::endl;
  std::cout << i << std::endl;
}

struct Printer {
  void print(int i) {
    std::cout << m_header << std::endl;
    std::cout << i << std::endl;
  }

  void header(const std::string &header) { m_header = header; }

  void operator()(int i) { print(i); }

private:
  std::string m_header{"--- value ---"};
};

// Functor
struct IsPositiveNumber {
  bool operator()(int i) const { return i >= 0; }
};

// With a functor
void check(int i, IsPositiveNumber pn) {
  if (pn(i)) {
    // ...
  }
}

// With a function pointer
void check(int i, bool (*is_positive_number)(int)) {
  if (is_positive_number(i)) {
    // ...
  }
}

int main() {
  print(42);
  print(77);
  print(8, "--- valore --");

  // Using the Printer class
  Printer p;
  p.print(42);
  p.print(77);
  Printer p2;
  p2.header("--- valore ---");
  p2.print(8);

  p(42);
  p(77);
  p2(8);

  std::cout << " ---- with lambdas -----\n";

  auto h = "--- value ---";
  auto f = "--- ---";

  // [ capture-list ] (arguments) -> retType { body };

  // Capture list "rules":
  // [a,b,c]  capture variables a,b,c by value
  // [&a,&b,&c] capture variable a,b,c by reference
  // [=] capture everything by value
  // [&] capture everything by reference
  // [=,&b] capture everything by value, except b (by reference)
  // [&,a] capture everything by reference, except a (by value)

  // auto p3 = [h,f](int i) -> void {
  auto p3 = [=](int i) -> void {
    std::cout << h << std::endl;
    std::cout << i << std::endl;
    std::cout << f << std::endl;
  };
  h = "*******";
  p3(42);
  p3(77);
  auto p4 = [&, f](int i) {
    double pi{3.14};
    std::cout << h << std::endl;
    std::cout << i << std::endl;
    std::cout << f << std::endl;
  };
  p4(42);
  p4(77);

  // TODO: Create a lambda which counts (and returns)
  // how many times it has been called
  unsigned int counter{0};
  auto countFn = [&counter]() mutable { return ++counter; };

  auto countFn2 = [counter = 0]() mutable { return ++counter; };

  // Behind "auto" we have std::function
  // std::function<retType(arguments)>
  std::function<int()> countFn3 = [counter = 0]() mutable { return ++counter; };

  // Behind "auto" we have std::function
  // std::function<retType(arguments)>
  std::function<int(int, int)> lambdaFn = [](int x, int y) { return x + y; };
}
