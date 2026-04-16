#include <iostream>
#include <utility>
#include <vector>

struct Appunti {
  Appunti() : m_i{new int{0}} { std::cout << "Appunti created\n"; }

  // Copy constructor
  Appunti(const Appunti &o) : m_i{new int{*o.m_i}} {
    std::cout << "Appunti copy constructed\n";
  }

  // Copy constructor
  Appunti(Appunti &&o) : m_i{o.m_i} {
    std::cout << "Appunti move constructed\n";
    o.m_i = nullptr;
  }

  // Copy assignment operator
  Appunti &operator=(const Appunti &o) {
    *m_i = *o.m_i;
    std::cout << "Appunti copy assigned\n";
    return *this;
  }

  ~Appunti() {
    delete m_i;
    std::cout << "Destroying Appunti\n";
  }

private:
  int *m_i;
};

struct Studente {
  Studente(const std::string &nome) : m_appunti{new Appunti}, m_nome{nome} {
    std::cout << "Sono un nuovo studente e mi chiamo " << m_nome << '\n';
  }
  ~Studente() {
    std::cout << "Abbandono la scuola, mi chiamo " << m_nome << '\n';
    delete m_appunti;
  }
  Studente(const Studente &) = delete;
  Studente &operator=(const Studente &) = delete;

  // Move constructor
  Studente(Studente &&o) : m_appunti{o.m_appunti}, m_nome{o.m_nome} {
    std::cout << "Move constructor " << m_nome << '\n';
    o.m_appunti = nullptr;
  }

  Studente &operator=(Studente &&o) {
    std::cout << "Move assignment operator " << m_nome << '\n';
    m_appunti = o.m_appunti;
    o.m_appunti = nullptr;
    return *this;
  }

  Appunti getAppunti() const { return *m_appunti; }

  void setAppunti(const Appunti &a) { *m_appunti = a; }

private:
  Appunti *m_appunti;
  std::string m_nome;
};

void foo(Appunti v) {}

void bar(Studente b) {}

Studente dropOut() { return Studente{"Pippo"}; }

Appunti getAppunti() { return Appunti{}; }

int main() {
  Studente dc{"Davide"};
  // bar(dc);
  Studente tp{"Tommy"};
  // tp.setAppunti(dropOut().getAppunti());
  tp = dropOut();
  tp = Studente{"Igor"};
  Studente pq{dropOut()};            // Copy Elision
  Studente pp{std::move(dropOut())}; // Disable Copy Elision
  bar(std::move(pq));
}
